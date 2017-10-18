// vbf_maxpt_jj_Deta
// vbf_maxpt_jj_m
// mass_lvj_type0
void RunMacro_limit()
{
    gROOT->ProcessLine(".L myControlPlots.C+");
    gROOT->ProcessLine("myControlPlots(\"DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt\", \"DibosonBoostedElSamples13TeV_InData_11Oct_OnlyCHS_limit.txt\", commonplotvars_chs_signal , \"histo_El_SCut.root\") ");
    //gROOT->ProcessLine("myControlPlots(\"DibosonBoostedMuCuts13TeV_Signal_CHS.txt\", \"DibosonBoostedMuSamples13TeV_InData_11Oct_OnlyCHS_limit.txt\", commonplotvars_chs_signal , \"histo_Mu_SCut.root\") ");

//==================================================
//
//	Plot signal and background
//
//==================================================
//    gROOT->ProcessLine(".L myControlPlots_SignalBkg_Comparison.C+");
//    gROOT->ProcessLine("myControlPlots_SignalBkg_Comparison(\"DibosonBoostedElCuts13TeV_Signal_CHS_Limit.txt\", \"DibosonBoostedElSamples13TeV_InData_11Oct_OnlyCHS_limit.txt\", commonplotvars_chs_signal , \"histo_El_SCut.root\") ");
  
    //gROOT->ProcessLine("myControlPlots_SignalBkg_Comparison(\"DibosonBoostedMuCuts13TeV_Signal_CHS.txt\", \"DibosonBoostedMuSamples13TeV_InData_11Oct_OnlyCHS_limit.txt\", commonplotvars_chs_signal , \"histo_Mu_SCut.root\") ");
    
}
