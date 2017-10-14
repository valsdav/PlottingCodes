void RunMacro_SigBkgComparison()
{
    gROOT->ProcessLine(".L myControlPlots_SignalBkg_Comparison.C+");


    gROOT->ProcessLine("myControlPlots_SignalBkg_Comparison(\"DibosonBoostedMuCuts13TeV_Signal_CHS.txt\", \"DibosonBoostedMuSamples13TeV_InData_11Oct_OnlyCHS.txt\", commonplotvars_chs_signal ) ");
    gROOT->ProcessLine("myControlPlots_SignalBkg_Comparison(\"DibosonBoostedElCuts13TeV_Signal_CHS.txt\", \"DibosonBoostedElSamples13TeV_InData_11Oct_OnlyCHS.txt\", commonplotvars_chs_signal ) ");

    //gROOT->ProcessLine("Wjet_loose()");
    //gROOT->ProcessLine("Wjet_tight()");
    //gROOT->ProcessLine("TopControl()");
    //gROOT->ProcessLine("Wjet_tighter()");
}
