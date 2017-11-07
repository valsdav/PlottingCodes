import os
import sys
import time
import datetime
import subprocess
import yaml
import numpy as np

print 'Argument List:', str(sys.argv)

Lepton = sys.argv[-1]
print("==> Number of leptons = "+str(Lepton))

SignificanceOutput = open("Significance_"+ datetime.datetime.now().strftime('%Y_%m_%d_%Hh%M') +".log","w")


# Printing the variable name
Varlen = len(sys.argv[1])
pline1 = "====        "+sys.argv[1]+"        ===="
pline2 = "="*len(pline1)
print pline2,"\n",pline1,"\n",pline2,"\n"

SignificanceOutput.write("=="*20)
SignificanceOutput.write("==\t Cut File \t==")
SignificanceOutput.write("=="*20)
if (int(Lepton)==1):
	for lines in open("Template_El_Cuts_Limit_1Lep.txt","r"):
		SignificanceOutput.write(lines)
if (int(Lepton)==2):
	for lines in open("Template_El_Cuts_Limit_2Lep.txt","r"):
		SignificanceOutput.write(lines)

SignificanceOutput.write("=="*20+"\n")

EachVarOut = open("Significance_"+str(sys.argv[1])+".log", "w")

SignificanceOutput.write(pline2+"\n"+pline1+"\n"+pline2+"\n")

EachVarOut.write(pline2+"\n"+pline1+"\n"+pline2+"\n")

countCut = 0

for cut in np.arange(float(sys.argv[3]), float(sys.argv[4]), float(sys.argv[5])):
	countCut += 1
	CutString = '"' + str(sys.argv[2]) + '"\t\t"(' + str(sys.argv[1]) + str(sys.argv[6]) + str(cut)+')"'
	print CutString,"\n"
	os.system('rm DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt')

	if (int(Lepton)==1):
		os.system('cp Template_El_Cuts_Limit_1Lep.txt DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt')
	if (int(Lepton)==2):
		os.system('cp Template_El_Cuts_Limit_2Lep.txt DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt')

	if (os.path.isfile("DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt")):
		print "Cut file foCut file..."
	else:
		sys.exit('Cut file "DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt" not found.')

	with open("DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt", "a") as myfile:
		myfile.write(CutString)
	myfile.close()
	print "========== Print Cut file \n\n"
	os.system('cat DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt')
	print "\n\n========== End Cut file \n\n"
	print ''
	OutRootFileName = 'histo_El_'+str(sys.argv[1])+'_'+(str(cut).replace(".","_")).replace("-","_")+'.root'
	os.system("sed 's/histo_El_SCut.root/"+OutRootFileName+"/' Templet_RunMacro_limit.C > RunMacro_limit.C")
	print "**"*20
	os.system("cat RunMacro_limit.C")
	print "**"*20
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
	print "================================================\n\n\n"
EachVarOut.close()
SignificanceOutput.write("\n\n")
SignificanceOutput.close()		