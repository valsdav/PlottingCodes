# Set-up instructions

	cmsrel CMSSW_9_0_1
	cd CMSSW_9_0_1/src
	git clone git@github.com:osWW-VBS/ControlPlots.git
	cd ControlPlots

* Prepare "InData" and "OutDir" directories; e.g., 
	
		ln -s <Path_of_InputData> InData_v2
		mkdir OutDir

* Add all signal, background and data samples in file **DibosonBoostedMuSamples13TeV.txt** (for electrons), **DibosonBoostedElSamples13TeV.txt** (for muons)

## Control Plot Instructions
 Run the macro **RunMacro.C** to get the control plots

	root -l -b -q RunMacro.C
	RunMacro.C
	myControlPlots.C
	DibosonBoostedMuCuts13TeV_WjetControlRegion_Tighter_CHS.txt
	DibosonBoostedElCuts13TeV_WjetControlRegion_Tighter_CHS.txt
	DibosonBoostedMuCuts13TeV_TTBarControlRegion.txt
	DibosonBoostedElCuts13TeV_TTBarControlRegion.txt
	DibosonBoostedMuSamples13TeV_InData_11Oct_OnlyCHS.txt
	DibosonBoostedElSamples13TeV_InData_11Oct_OnlyCHS.txt

## Signal Background Comparison

	RunMacro_SigBkgComparison.C
	myControlPlots_SignalBkg_Comparison.C
	DibosonBoostedElCuts13TeV_Signal_CHS.txt
	DibosonBoostedMuCuts13TeV_Signal_CHS.txt
	controlplotvars_CHS_signal.h
	DibosonBoostedMuSamples13TeV_InData_11Oct_OnlyCHS.txt
	DibosonBoostedElSamples13TeV_InData_11Oct_OnlyCHS.txt

## Cut Optimization

To optimize the cut using limit tool we need single root files with different set of cuts applied. So, below receip provide us the way to do this automatically.

List of main files:

	1. ScanCutsForLimit.py for 1D cuts and ScanCutsForLimit_2D.py for 2D cut. With 2D cut I mean cuts like mW mass window and by 1D, I mean simple cut like lepton pT, MET, etc.
	2. CutScan.yaml: This file has basic details of cuts over which we have to scan.
	3. 


	ScanCutsForLimit.py	# This script to run for simple cut
	ScanCutsForLimit_2D.py	# Thsi should be run for window like cuts
	CutScan.yaml		# Cut scan list
	myControlPlots.C	# Main code
	controlplotvars_CHS_signal.h	# Observable 
	DibosonBoostedElSamples13TeV_InData_11Oct_OnlyCHS_limit.txt	# List of all signal and bkg
	Template_El_Cuts_Limit.txt	# Template file used by script
	Templet_RunMacro_limit.C	# Template file used by script

