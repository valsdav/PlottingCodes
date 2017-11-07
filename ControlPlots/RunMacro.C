void RunMacro()
{
  gROOT->ProcessLine(".L myControlPlots.C+");
  //gROOT->ProcessLine(".L model.C+");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_WjetControlRegion.txt\", \"DibosonBoostedElSamples13TeV.txt\")");
    
    //		WITHOUT JET ID
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_WjetControlRegion_Tighter_Puppi.txt\", \"DibosonBoostedElSamples13TeV_InData_3Oct.txt\", commonplotvars_puppi ) ");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_WjetControlRegion_Tighter_CHS.txt\", \"DibosonBoostedElSamples13TeV_InData_3Oct.txt\", commonplotvars_chs ) ");
    
    //		WITH WITH JET ID
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_WjetControlRegion_Tighter_Puppi.txt\", \"DibosonBoostedElSamples13TeV_InData_2Oct.txt\", commonplotvars_puppi ) ");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_WjetControlRegion_Tighter_CHS.txt\", \"DibosonBoostedElSamples13TeV_InData_2Oct.txt\", commonplotvars_chs ) ");

    //	9 october : Applied CHS jet id to puppi jets
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_WjetControlRegion_Tighter_Puppi.txt\", \"DibosonBoostedElSamples13TeV_InData_9Oct.txt\", commonplotvars_puppi ) ");

    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_WjetControlRegion_Tighter_CHS.txt\", \"DibosonBoostedElSamples13TeV_InData_11Oct_OnlyCHS.txt\", commonplotvars_chs ) ");
    gROOT->ProcessLine("myControlPlots(\"DibosonBoostedMuCuts13TeV_WjetControlRegion_Tighter_CHS.txt\", \"DibosonBoostedMuSamples13TeV_InData_11Oct_OnlyCHS_condor.txt\", commonplotvars_chs ) ");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_TTBarControlRegion.txt\", \"DibosonBoostedElSamples13TeV_InData_11Oct_OnlyCHS.txt\", commonplotvars_chs ) ");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedMuCuts13TeV_TTBarControlRegion.txt\", \"DibosonBoostedMuSamples13TeV_InData_11Oct_OnlyCHS.txt\", commonplotvars_chs ) ");

    //gROOT->ProcessLine("Wjet_loose()");
    //gROOT->ProcessLine("Wjet_tight()");
    //gROOT->ProcessLine("TopControl()");
    //gROOT->ProcessLine("Wjet_tighter()");
}
