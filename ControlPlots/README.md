# Set-up instructions

	cmsrel CMSSW_9_0_1
	cd CMSSW_9_0_1/src
	git clone git@github.com:osWW-VBS/ControlPlots.git
	cd ControlPlots

* Prepare "InData" and "OutDir" directories; e.g., "ln -s . OutDir" to go to current dir
* Prepare "cuttable.txt" of cut names and cut string
	

		root -l -b -q RunMacro.C
