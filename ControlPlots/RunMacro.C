void RunMacro()
{
  gROOT->ProcessLine(".L myControlPlots.C+");
  //gROOT->ProcessLine(".L model.C+");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_WjetControlRegion.txt\", \"DibosonBoostedElSamples13TeV.txt\")");
    gROOT->ProcessLine("Wjet_loose()");
    gROOT->ProcessLine("Wjet_tight()");
    gROOT->ProcessLine("TopControl()");
    gROOT->ProcessLine("Wjet_tighter()");
}
