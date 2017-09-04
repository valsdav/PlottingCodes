#ifndef _NMINUS1PLOTPLOTVARS_H
#define _NMINUS1PLOTPLOTVARS_H

#include "plotvar_t.h"

const plotVar_t met[] = {
 { "pfMET",		0, 480, 16, 3,	"pf MET (GeV)",  		"pfmet",	 0, 480, 16, 1 },
 { "pfMETpuppi",	0, 480, 16, 3,	"pf MET (puppi) (GeV)",		"pfmetpuppi",	 0, 480, 16, 1 },
 { "pfMET_Corr",	0, 480, 16, 3,	"pf MET (puppi) (GeV)",		"pfMET_Corr",	 0, 480, 16, 1 },
 { "pfMETpuppi_Corr",	0, 480, 16, 3,	"pf MET (puppi) (GeV)",		"pfMETpuppi_Corr",	 0, 480, 16, 1 },
 { "pfMET_Phi",		-3.5, 3.5, 20, 6,	"pf MET #phi ", 		"pfMET_Phi",	 -3.5,  3.5, 20, 0 },
 { "pfMETpuppi_Phi",	-3.5, 3.5, 20, 6,	"pf MET #phi (puppi) ",		"pfMETpuppi_Phi",-3.5,  3.5, 20, 0 },
 { "pfMET_Corr_phi",	-3.5, 3.5, 20, 6,	"pf MET #phi (puppi) ",		"pfMET_Corr_phi",-3.5,  3.5, 20, 0 },
 { "pfMETpuppi_Corr_phi",-3.5, 3.5, 20, 6,	"pf MET #phi (puppi) ",		"pfMETpuppi_Corr_phi",-3.5,  3.5, 20, 0 },
 { "", 0.0,0.0,0,0,"","",0.,0.,0,0 }
 
};

const plotVar_t fat_jet[] = {
 { "ungroomed_AK8jet_pt",	100, 800, 14, 3, "AK8 p_{T} (GeV)",		"ungroomed_AK8jet_pt",  100, 800, 14, 1 },
 { "", 0.0,0.0,0,0,"","",0.,0.,0,0 }
  
};

const plotVar_t vbfmjj[] = {
 { "vbf_maxpt_jj_m", 	0, 1600, 16, 1,		"m_{jj} (VBF) GeV",	"vbf_maxpt_jj_m",  0, 1600, 16, 1},
 { "", 0.0,0.0,0,0,"","",0.,0.,0,0 }
};

const plotVar_t vbfdEta[] = {
 { "vbf_maxpt_jj_Deta", 0, 10, 10, 1, 	"VBF jet #Delta #eta", "vbf_maxpt_jj_Deta", 0, 10, 10, 1},
 { "", 0.0,0.0,0,0,"","",0.,0.,0,0 }
};

const plotVar_t nbtag[] = {
 { "nBTagJetPuppi_medium", 0, 6, 6, 1, "number of VBF jets (medium b-tag)", "nBTagJetPuppi_medium", 0, 6, 6, 1},
 { "", 0.0,0.0,0,0,"","",0.,0.,0,0 }
};

#endif // _COMMONCONTROLPLOTVARS_H
