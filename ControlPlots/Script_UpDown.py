import os
import sys

# User Modifiable lines
varToPlot = '{ "ungroomed_AK8jet_pt+vbf_maxpt_j1_pt+vbf_maxpt_j2_pt",    500, 2100, 8, 3, "HT", "ht", 500, 2100, 8, 1},'

OutPutRootFileName = "testRoot.root" 

CutArray = ['"Ele"			"(type==1)"', 
	    '"1 lepton"		"(l_pt2<0)"', 
	    '"Good Muon"		"((l_pt1>30.) && (abs(l_eta1)<2.5))"', 
	    '"Good FatJet"		"((ungroomed_AK8jet_pt>200)&&(abs(ungroomed_AK8jet_eta)<2.4)&&(AK8jet_tau2tau1<0.55))"',
	    '"m_{J}<50 && m_{J}>110"	"((AK8jet_mass_so>50) && (AK8jet_mass_so<110))"',
	    '"Loose b-tag AK4<2"	"(nBTagJet_loose==0)"',
	    '"pfMET_Corr>30"		"(pfMET_Corr>50)"',
	    '"VBFjets"		"(isVBF==1)"',
	    '"VBF jet deta > 2.5"    "(abs(vbf_maxpt_j2_eta-vbf_maxpt_j1_eta)>2.5)"',
	    '"VBF jet pts > 30"	"((vbf_maxpt_j1_pt>30) && (vbf_maxpt_j2_pt>30))"',
	    '"VBF Mjj > 500"         "(vbf_maxpt_jj_m>500)"'
	    ]

# End user edit lies

varFileWrite = open("controlplotvars_UpDn.h","w")

# Mandatory lines to write infile
varFileWrite.write('#ifndef _UPDOWNPLOTVARS_CHS_H\n')
varFileWrite.write('#define _UPDOWNPLOTVARS_CHS_H\n\n')
varFileWrite.write('#include "plotvar_t.h"\n\n')
varFileWrite.write('const plotVar_t updownplotvars_chs[] = {\n')
varFileWrite.write('//    plotvar   MINRange  MAXRange  NBINS  slog xlabel outfile AMINRange  AMAXRange ANBINS drawleg\n')
varFileWrite.write(varToPlot+'\n')
varFileWrite.write('\n{ "", 0.0,0.0,0,0,"","",0.,0.,0,0 }\n };\n\n #endif\n')
varFileWrite.close()
# Variable header file generated


# Start makeing cut file
cutFileWrite = open("DibosonBoostedMuCuts13TeV_Script.txt","w")
for cuts in CutArray:
	cutFileWrite.write(cuts+'\n')
cutFileWrite.close();

# Start making run c++ file
runFilewrite = open("RunCpp.C",'w')
runFilewrite.write('void RunCpp()\n{\n')
runFilewrite.write('\tgROOT->ProcessLine(".L myControlPlots.C+");\n\n')
runFilewrite.write('\tgROOT->ProcessLine("myControlPlots(\\"DibosonBoostedMuCuts13TeV_Script.txt\\", \\"DibosonBoostedMuSamples13TeV_2017-11-07_14h59_OnlyCHS.txt\\", updownplotvars_chs, \\"'+OutPutRootFileName+'\\" ) ");\n\n}\n')
runFilewrite.close()


# Run the generated macro
os.system('root -l -b -q RunCpp.C')
