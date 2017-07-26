#ifndef _MVACONTROLPLOTVARS_H
#define _MVACONTROLPLOTVARS_H

#include "plotvar_t.h"

////////////////////////////////////////////MVA
const plotVar_t mvaplotvars[] = {
  //    plotvar MINRange  MAXRange  NBINS  slog xlabel    outfile  AMINRange  AMAXRange ANBINS drawleg

  { "costheta1_type2",    -1.0, 1.0, 20, 1, "Cos(#theta_{1})" ,  "mvacostheta1",   -1.0, 1.0, 20, 1 },
//{ "mva_wjj_ang_hb",        0,   1, 10, 1, "Cos(#theta_{2})" ,  "mvaanghb",          0,   1, 10, 1 },
  { "costhetastar_type2", -1.0, 1.0, 20, 1, "Cos(#theta*)" ,    "mvacosthetastar", -1.0, 1.0, 20, 1 },
//{ "mva_wjj_ang_phi",    -3.2, 3.2, 32, 6, "#Phi (rad)" ,       "mvaangphi",      -3.5, 3.5, 35, 1 },
  { "phi1_type2",         -3.2, 3.2, 32, 6, "#Phi_{1} (rad)",    "mvaangphi1",     -3.5, 3.5, 35, 1 },

  { "mt_lvj_run2_PuppiAK8",       0, 2500, 50, 3, "m_{T} of WW (GeV)", "mvamtlvJ",  0, 2500, 50, 1 },
  { "pt_lvj_run2_PuppiAK8",       0,  500, 25, 3, "p_{T} of WW (GeV)", "mvaptlvJ",  0,  500, 25, 1 },

  { "eta_lvj_run2_PuppiAK8",   -4.4,  4.4, 22, 1, "eta of WW", "mvaetalvJ",      -5.2,  5.2, 26, 1 },
  { "rapidity_lvj_run2_PuppiAK8",-4.4,4.4, 22, 1, "Rap. of WW", "mvaraplvJ",     -5.2,  5.2, 26, 1 },
  { "phi_lvj_run2_PuppiAK8",   -3.2,  3.2, 32, 6, "phi of WW (rad)", "mvaphilvJ",-3.5,  3.5, 35, 1 },
  { "energy_lvj_run2_PuppiAK8",   0, 2500, 50, 3, "E of WW (GeV)", "mvaElvJ",       0, 2500, 50, 1 },

  { "l_charge",                -1.2,  1.2, 24, 1, "Lepton Charge", "mvalepcharge",-1.2, 1.2, 24, 1 },

  { "VBSCentrality_type2",      0.,  10.,  50, 1, "VBS Centrality", "mvavbscent",  0., 10., 50, 1  },
  { "ZeppenfeldWH",            -5.,   5.,  50, 1, "Zep(V_{had})",  "mvazepvhad",  -5.,  5., 50, 1  },
  { "ZeppenfeldWL_type2",      -5.,   5.,  50, 1, "Zep(W_{lep})",  "mvazepwlep",  -5.,  5., 50, 1  },
  { "RpT_type2",                0.,  50.,  50, 1, "pTWh*pTWl/(ptj1*ptj2)", "mvarpt", 0., 50., 50, 1 },
  { "LeptonProjection_type2",   0.,   2.,  40, 1, "Lepton Projection", "mvalepproj",  0., 2., 40, 1 },

  { "", 0.0,0.0,0,0,"","",0.,0.,0,0 }
};

#endif // _MVACONTROLPLOTVARS_H
