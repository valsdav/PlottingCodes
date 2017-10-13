#ifndef _COMMONCONTROLPLOTVARS_PUPPI_H
#define _COMMONCONTROLPLOTVARS_PUPPI_H

#include "plotvar_t.h"

const plotVar_t commonplotvars_puppi[] = {

////    plotvar	MINRange  MAXRange  NBINS  slog xlabel outfile AMINRange  AMAXRange ANBINS drawleg
////
////    LEPTONS
 { "l_pt1+pfMET+ungroomed_PuppiAK8_jet_pt+vbfPuppi_maxpt_j1_pt+vbfPuppi_maxpt_j2_pt",	500, 2000, 20, 3, "HT", "ht", 500, 2000, 20, 1},
 { "nPV",		0, 50, 50, 3,	"Number of primary vertices", "nPV", 	0, 50, 50, 1},
 { "l_pt1",		20, 320, 10, 3,		"Lepton p_{T} (GeV)",     "lepton_pt",       20,  320, 10, 1 },
 { "l_eta1",		-2.4, 2.4, 8, 1,	"Lepton #eta",            "lepton_eta",    -2.4,  2.4,  8, 0 },
//
//////	MET
 { "pfMETpuppi",	0, 480, 16, 3,	"pf MET (puppi) (GeV)",		"pfmetpuppi",	 0, 480, 16, 1 },
 { "pfMETpuppi_Corr",	0, 480, 16, 3,	"pf MET Corr (puppi) (GeV)",		"pfMETpuppi_Corr",	 0, 480, 16, 1 },
 { "pfMETpuppi_Phi",	-3.5, 3.5, 20, 6,	"pf MET #phi (puppi) ",		"pfMETpuppi_Phi",-3.5,  3.5, 20, 0 },
 { "pfMETpuppi_Corr_phi",-3.5, 3.5, 20, 6,	"pf MET #phi Corr (puppi) ",		"pfMETpuppi_Corr_phi",-3.5,  3.5, 20, 0 },

//	Leptonic & Hadronic W-boson 
 { "v_pt_type0",		200, 700, 10, 3,	"W p_{T} (GeV)",		"v_pt", 	 200, 700, 10, 1 },
 { "v_mt_type0",		0, 140, 14, 3,	"W Transverse Mass (GeV)",	"v_mt", 	 0, 140, 14, 0 },

 { "ungroomed_PuppiAK8_jet_pt", 200, 800, 12, 3, "AK8 Puppi p_{T} GeV",		"ungroomed_PuppiAK8_jet_pt", 200, 800, 12, 1},
 { "ungroomed_PuppiAK8_jet_eta",-2.4, 2.4, 12, 1,  "AK8 Puppi #eta",		"ungroomed_PuppiAK8_jet_eta", -2.4, 2.4, 12, 0},
 { "ungroomed_PuppiAK8_jet_phi",-4.0, 4.0, 12, 1,  "AK8 Puppi #phi",		"ungroomed_PuppiAK8_jet_phi", -4.0, 4.0, 12, 0},
 { "PuppiAK8_jet_mass", 	0, 240, 12, 1, "AK8 mass (GeV)",		"Puppi_AK8_mass",    0, 240, 12, 1},
 { "PuppiAK8_jet_mass_pr", 	0, 250, 10, 1, "AK8 pruned mass (GeV)",	"Puppi_AK8_mass_pr", 0, 250, 10, 1},
 { "PuppiAK8_jet_mass_so", 	110, 250, 10, 1, "AK8 Softdrop mass (GeV)",	"Puppi_AK8_mass_so", 110, 250, 10, 1},
 { "PuppiAK8_jet_mass_tr", 	0, 250, 10, 1, "AK8 tr mass (GeV)", 		"Puppi_AK8_mass_tr", 0, 250, 10, 1},

//////	Number of jets
 { "njetsPuppi",  0, 10, 10, 1, "Number of VBF jets",	"njetsPuppi", 0, 10, 10, 1},
 { "nBTagJetPuppi_loose", 0, 6, 6, 1, "number of VBF jets (Loose b-tag)", "nBTagJetPuppi_loose", 0, 6, 6, 1},
 { "nBTagJetPuppi_medium", 0, 6, 6, 1, "number of VBF jets (medium b-tag)", "nBTagJetPuppi_medium", 0, 6, 6, 1},

////// 
 { "PuppiAK8_jet_tau2tau1", 	0, 1, 10, 1, "AK8 Puppi #tau_{2}/#tau_{1}", 	"PuppiAK8_jet_tau2tau1",0,1,10,0},
 { "vbfPuppi_maxpt_jj_m", 	0, 1600, 16, 1,		"m_{jj} (VBF) GeV",	"vbfPuppi_maxpt_jj_m",  0, 1600, 16, 1},

//////	VBF JET 
//
 { "vbfPuppi_maxpt_j1_eta", -5.0, 5.0, 20, 1,	"Leading VBF Jet #eta",	"vbfPuppi_maxpt_j1_eta", 	-5.0, 5.0, 20, 0},
 { "vbfPuppi_maxpt_j2_eta", -5.0, 5.0, 20, 1,	"Sub-Leading VBF Jet #eta", "vbfPuppi_maxpt_j2_eta", -5.0, 5.0, 20, 0},
 { "vbfPuppi_maxpt_j2_pt", 0,280, 28, 1,		"Sub-Leading VBF Jet p_{T}", "vbfPuppi_maxpt_j2_pt", 0,280,28,0 },
 { "vbfPuppi_maxpt_j1_pt", 0,400, 20, 1,		"Leading VBF Jet p_{T}",	"vbfPuppi_maxpt_j1_pt", 0,400,20,1 },
 { "vbfPuppi_maxpt_jj_Deta", 0, 10, 20, 1,	"VBF #Delta #eta",	"vbfPuppi_maxpt_jj_Deta",0,10, 20, 1 },
//
////// Angular variables
//
 { "vbfPuppi_maxpt_deltaR", 0, 10, 10, 1, 	"#Delta R (VBF jets)" 	, "vbfPuppi_maxpt_deltaR", 0,10, 10, 1}, 

 { "", 0.0,0.0,0,0,"","",0.,0.,0,0 }
};


#endif // _COMMONCONTROLPLOTVARS_H
