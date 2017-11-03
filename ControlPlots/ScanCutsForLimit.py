import os
import time
import datetime
import subprocess
import yaml
import numpy as np

f = "CutScan.yaml"

OutPutDir = "OutPutRootFiles_1D_"+ datetime.datetime.now().strftime('%Y-%m-%d_%Hh%M')
os.system("mkdir "+OutPutDir)

SignificanceOutput = open("Significance_"+ datetime.datetime.now().strftime('%Y-%m-%d_%Hh%M') +".log","w")

with open(f, 'r') as f_in:
	dataMap = yaml.load(f_in)

var = dataMap['variables']


for i in range(0,len(var)):
	# Printing the variable name
	Varlen = len(var[i]['name'])
	pline1 = "====        "+var[i]['name']+"        ===="
	pline2 = "="*len(pline1)
	print pline2,"\n",pline1,"\n",pline2,"\n"

	EachVarOut = open("Significance_"+str(var[i]['name'])+".log", "w")

	SignificanceOutput.write(pline2+"\n"+pline1+"\n"+pline2+"\n")
	EachVarOut.write(pline2+"\n"+pline1+"\n"+pline2+"\n")

	countCut = 0
	for cut in np.arange(var[i]['iRange'], var[i]['fRange'], var[i]['step']):
		countCut += 1
		CutString = '"'+str(var[i]['tag'])+'"\t\t"('+str(var[i]['name'])+str(var[i]['ltgt'])+str(cut)+')"'
		#print CutString,"\n"
		os.system('cp Template_El_Cuts_Limit.txt DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt')
		with open("DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt", "a") as myfile:
		    myfile.write(CutString)
		myfile.close()
		os.system('cat DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt')
		print ''
		print ''
		print ''

		OutRootFileName = 'histo_El_'+str(var[i]['name'])+'_'+(str(cut).replace(".","_")).replace("-","_")+'.root'
		os.system("sed 's/histo_El_SCut.root/"+OutRootFileName+"/' Templet_RunMacro_limit.C > RunMacro_limit.C")
		os.system('root -l -b -q RunMacro_limit.C')

		LogFile = open("OutDir/DibosonBoostedElCuts13TeV_Signal_CHS_Limit_mass_lvj_type0.log","r")
		for lines in LogFile:
			if "Total MC" in lines:
				mc = lines.split()[3]
			if "WV(EWK)" in lines:
				ewk = lines.split()[2]
			if "Significance (SM EWK) =" in lines:
				sigEwk = lines.split()[4]
			if "Significance (aQGC)   = " in lines:
				sigaQGC = lines.split()[3]
			elif "aQGC" in lines:
				aQGC = lines.split()[2]
		if 'aQGC' in locals():
			if countCut == 1:
				SignificanceOutput.write("CutValue\tSM-Events\taQGC-Events\tTotal-Bkg\tewk-significance\taQGC-significance\n")
				EachVarOut.write("CutValue\tSM-Events\taQGC-Events\tTotal-Bkg\tewk-significance\taQGC-significance\n")
			SignificanceOutput.write(str(cut)+"\t"+str(ewk)+"\t"+str(aQGC)+"\t"+str(mc)+"\t"+str(sigEwk)+"\t"+str(sigaQGC)+"\n")
			EachVarOut.write(str(cut)+"\t"+str(ewk)+"\t"+str(aQGC)+"\t"+str(mc)+"\t"+str(sigEwk)+"\t"+str(sigaQGC)+"\n")
		else:
			if countCut == 1:
				SignificanceOutput.write("CutValue\tSM-Events\tTotal-Bkg\tewk-significance\n")
				EachVarOut.write("CutValue\tSM-Events\tTotal-Bkg\tewk-significance\n")
			SignificanceOutput.write(str(cut)+"\t"+str(ewk)+"\t"+str(mc)+"\t"+str(sigEwk)+"\n")
			EachVarOut.write(str(cut)+"\t"+str(ewk)+"\t"+str(mc)+"\t"+str(sigEwk)+"\n")
		#output = subprocess.check_output("root -l -b -q RunMacro_limit.C", shell=True)
		print "================================================\n\n\n"
		print "Moving output root file to limitExtraction directory...\n"
		#os.system('mv '+OutRootFileName+'  /afs/cern.ch/user/r/rasharma/work/aQGC_Studies/LimitExtraction/CMSSW_8_1_0/src/HiggsAnalysis/CombinedLimit/data/tutorials/shapes/')
		os.system('mv '+ OutRootFileName + ' ' + OutPutDir)
	EachVarOut.close()
	SignificanceOutput.write("\n\n")
SignificanceOutput.close()		
os.system('mv *.log  '+OutPutDir)
