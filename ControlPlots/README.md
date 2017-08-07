# Set-up instructions

	cmsrel CMSSW_9_0_1
	cd CMSSW_9_0_1/src
	git clone git@github.com:osWW-VBS/ControlPlots.git
	cd ControlPlots

* Prepare "InData" and "OutDir" directories; e.g., 
	
		ln -s <Path_of_InputData> InData_v2
		mkdir OutDir

* Add all signal, background and data samples in file **DibosonBoostedMuSamples13TeV.txt** (for electrons), **DibosonBoostedElSamples13TeV.txt** (for muons)

* Run the macro **RunMacro.C** to get the control plots

		root -l -b -q RunMacro.C
