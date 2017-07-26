#ifndef _BOOSTEDCONTROLPLOTVARS_H
#define _BOOSTEDCONTROLPLOTVARS_H

#include "plotvar_t.h"

const plotVar_t boostedplotvars[] = {

  //    plotvar	MINRange  MAXRange  NBINS  slog xlabel outfile AMINRange  AMAXRange ANBINS mva_in drawleg
  { "PuppiAK8_jet_pt_so",   200,   800, 15, 3, "Jet (Puppi,Softdrop) p_{T} (GeV)",  "PuppiAK8_jet_pt_so",  200,  800, 15, 1 },
  { "PuppiAK8_jet_mass_pr",   0,   200, 20, 3, "Jet (Puppi, Pruned) mass (GeV)",   "PuppiAK8_jet_mass_pr",   0,  200, 20, 1 },
  { "", 0.0,0.0,0,0,"","",0.,0.,0,0 }
};


#endif // _BOOSTEDCONTROLPLOTVARS_H
