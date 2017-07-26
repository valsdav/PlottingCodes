#ifndef _VBFCONTROLPLOTVARS_H
#define _VBFCONTROLPLOTVARS_H

#include "plotvar_t.h"

////////////////////////////////////////////VBF
const plotVar_t vbfplotvars[] = {
  //    plotvar MINRange  MAXRange  NBINS  slog xlabel    outfile  AMINRange  AMAXRange ANBINS drawleg
#if 0
  { "nVBFPairs",
                        0, 10,  11, 0, "Number of VBF jet pairs", "nVBFpairs", 0, 10, 11, 0 },
#endif
#if 0
  { "vbf_maxpt_j1_pt",        40,   300, 13, 3, "Tagjet1  p_{T}",  "vbftagjeta_pt",    20,  300, 14, 1 },
  { "vbf_maxpt_j2_pt",        30,   200, 17, 3, "Tagjet2  p_{T}",  "vbftagjetb_pt",    20,  200, 18, 1 },
  { "vbf_maxpt_j1_eta",      -4.4 , 4.4, 11, 1, "Tagjet1 #eta",    "vbftagjeta_eta", -5.2,  5.2, 13, 0 },
  { "vbf_maxpt_j2_eta",      -4.4 , 4.4, 11, 1, "Tagjet2 #eta",    "vbftagjetb_eta", -5.2,  5.2, 13, 0 },
  { "abs(vbf_maxpt_j2_eta-vbf_maxpt_j1_eta)",
                               3. , 7., 20, 1, "Tagjets |#Delta #eta|", "vbftagjet_deta",   3., 7.0, 20, 1 },
  { "((l_eta-0.5*(vbf_maxpt_j2_eta+vbf_maxpt_j1_eta))/abs(vbf_maxpt_j2_eta-vbf_maxpt_j1_eta))",
                              -1. , 1., 10, 1, "Zep(lep)", "vbf_zeplep",   -1., 1.0, 10, 0 },
  { "vbf_maxpt_jj_m",         300, 1800,15, 3, "Tagjet Invariant Mass (GeV)", "vbftagjet_mass", 200,  1800, 16, 1 },
#endif
  { "VBSCentrality",    0, 4.0, 20, 1, "VBS Centrality",   "vbfcentrality",   0, 4.0, 20, 1 },
  { "", 0.0,0.0,0,0,"","",0.,0.,0,0 }
};

#endif // _VBFCONTROLPLOTVARS_H
