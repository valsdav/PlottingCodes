void RunMacro()
{
    gROOT->ProcessLine(".L myControlPlots.C+");
    gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV.txt\", \"DibosonBoostedElSamples13TeV.txt\")");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_mjjLT500.txt\", \"DibosonBoostedElSamples13TeV.txt\")");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_NoMetCut.txt\", \"DibosonBoostedElSamples13TeV.txt\")");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_TTBarControlRegion.txt\", \"DibosonBoostedElSamples13TeV.txt\")");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_WjetControlRegion.txt\", \"DibosonBoostedElSamples13TeV.txt\")");
}
