#! /usr/bin/env python
import os
import glob
import math
from array import array
import sys
import time
import subprocess
import tarfile
import datetime
import commands

currentDir = os.getcwd();
CMSSWDir =  currentDir+"/../";

inputFolder = "/store/user/rasharma/tmp/";
TestRun = 0


# Get date and time for output directory
## ADD "test" IN OUTPUT FOLDER IF YOU ARE TESTING SO THAT LATER YOU REMEMBER TO WHICH DIRECTORY YOU HAVE TO REMOVE FROM EOS
if TestRun:
	outputFolder = "/store/user/rasharma/CutScanLimit_PlottingToolOutputs/WWTree_"+datetime.datetime.now().strftime('%Y-%m-%d_%Hh%M')+"_TEST/";
	OutputLogPath = "OutPut_Logs/Logs_" + datetime.datetime.now().strftime('%Y-%m-%d_%Hh%M') + "_TEST/";
else:
	outputFolder = "/store/user/rasharma/CutScanLimit_PlottingToolOutputs/WWTree_"+datetime.datetime.now().strftime('%Y-%m-%d_%Hh%M');
	OutputLogPath = "OutPut_Logs/Logs_" + datetime.datetime.now().strftime('%Y-%m-%d_%Hh%M')+"/";


print "Name of output dir: ",outputFolder
# create a directory on eos
os.system('xrdfs root://cmseos.fnal.gov/ mkdir ' + outputFolder)
# create directory in pwd for log files
os.system('mkdir -p ' + OutputLogPath)

# Function to create a tar file
def make_tarfile(output_filename, source_dir):
    with tarfile.open(output_filename, "w:gz") as tar:
            tar.add(source_dir, arcname=os.path.basename(source_dir))

# Get CMSSW directory path and name
cmsswDirPath = commands.getstatusoutput('echo ${CMSSW_BASE}')
CMSSWRel = os.path.basename(cmsswDirPath[1])

print "CMSSW release used : ",CMSSWRel

# create tarball of present working CMSSW base directory
os.system('rm CMSSW*.tgz *.root *.log')
make_tarfile(CMSSWRel+".tgz", cmsswDirPath[1])

# send the created tarball to eos
os.system('xrdcp -f ' + CMSSWRel+".tgz" + ' root://cmseos.fnal.gov//store/user/rasharma/' + CMSSWRel+".tgz")
#os.system('xrdcp -f ThingsUpdated.txt root://cmseos.fnal.gov/' + outputFolder)
#os.system('cp ThingsUpdated.txt ' + OutputLogPath)

inputlist = "submit_on_lpcCondor_MINIAODv2.py, runstep2condor.sh"

command = "python ScanCutsForLimit_Condor.py $1 $2 $3 $4 $5 $6";

outScript = open("runstep2condor.sh","w");
outScript.write('#!/bin/bash');
outScript.write("\n"+'echo "Starting job on " `date`');
outScript.write("\n"+'echo "Running on: `uname -a`"');
outScript.write("\n"+'echo "System software: `cat /etc/redhat-release`"');
outScript.write("\n"+'source /cvmfs/cms.cern.ch/cmsset_default.sh');
outScript.write("\n"+'### copy the input root files if they are needed only if you require local reading');
outScript.write("\n"+'xrdcp -s root://cmseos.fnal.gov//store/user/rasharma/' + CMSSWRel +'.tgz  .');
outScript.write("\n"+'tar -xf '+ CMSSWRel +'.tgz' );
outScript.write("\n"+'rm '+ CMSSWRel +'.tgz' );
outScript.write("\n"+'cd ' + CMSSWRel + '/src/PlottingCodes/ControlPlots/' );
outScript.write("\n"+'scramv1 b ProjectRename');
outScript.write("\n"+'eval `scram runtime -sh`');
outScript.write("\n"+command);
outScript.write("\n"+'echo "====> List output files : " ');
outScript.write("\n"+'ls *.root *.log');
outScript.write("\n"+'xrdcp *.root *.log root://cmseos.fnal.gov/' + outputFolder);
outScript.write("\n"+'rm *.root *.log');
outScript.write("\n"+'cd ${_CONDOR_SCRATCH_DIR}');
outScript.write("\n"+'rm -rf ' + CMSSWRel);
outScript.write("\n");
outScript.close();
os.system("chmod 777 runstep2condor.sh");

outJDL = open("runstep2condor.jdl","w");
outJDL.write("Executable = runstep2condor.sh\n");
outJDL.write("Universe = vanilla\n");
#outJDL.write("Requirements =FileSystemDomain==\"fnal.gov\" && Arch==\"X86_64\"");
outJDL.write("Notification = ERROR\n");
outJDL.write("Should_Transfer_Files = YES\n");
outJDL.write("WhenToTransferOutput = ON_EXIT\n");
#outJDL.write("include : list-infiles.sh |\n");
outJDL.write("Transfer_Input_Files = "+inputlist+"\n");
outJDL.write("x509userproxy = $ENV(X509_USER_PROXY)\n");

    #MC
import yaml
import numpy as np

f = "CutScan.yaml"

with open(f, 'r') as f_in:
        dataMap = yaml.load(f_in)

var = dataMap['variables']


for i in range(0,len(var)):
        outJDL.write("Output = "+OutputLogPath+var[i]['name']+".stdout\n");
        outJDL.write("Error  = "+OutputLogPath+var[i]['name']+".stdout\n");
        outJDL.write("Arguments = "+str(var[i]['name']) + " '" + str(var[i]['tag']) + "' " + str(var[i]['iRange']) + " " + str(var[i]['fRange']) + " " + str(var[i]['step']) + " " + str(var[i]['ltgt']) + "\n");
        outJDL.write("Queue\n");

outJDL.close();
print "===> Set Proxy Using:";
print "\tvoms-proxy-init --voms cms --valid 168:00";
print "\"condor_submit runstep2condor.jdl\" to submit";

