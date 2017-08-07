void RunMacro()
{
    gROOT->ProcessLine(".L myControlPlots.C+");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_WjetControlRegion.txt\", \"DibosonBoostedElSamples13TeV.txt\")");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_mjjLT500.txt\", \"DibosonBoostedElSamples13TeV.txt\")");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_NoMetCut.txt\", \"DibosonBoostedElSamples13TeV.txt\")");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedMuCuts13TeV_LowMet.txt\", \"DibosonBoostedMuSamples13TeV.txt\")");
    gROOT->ProcessLine("myControlPlots(\"DibosonBoostedMuCuts13TeV_TTBarControlRegion.txt\", \"DibosonBoostedMuSamples13TeV.txt\")");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedMuCuts13TeV_WjetControlRegion.txt\", \"DibosonBoostedMuSamples13TeV.txt\")");
}
