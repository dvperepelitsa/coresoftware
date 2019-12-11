#ifndef G4JET_FASTJETALGO_H
#define G4JET_FASTJETALGO_H

#include "Jet.h"
#include "JetAlgo.h"

#include <iostream>   // for cout, ostream
#include <vector>     // for vector

class FastJetAlgo : public JetAlgo
{
 public:
  FastJetAlgo(Jet::ALGO algo, float par, int verbosity = 0);
  virtual ~FastJetAlgo() {}

  void identify(std::ostream& os = std::cout);
  Jet::ALGO get_algo() { return _algo; }
  float get_par() { return _par; }

  std::vector<Jet*> get_jets(std::vector<Jet*> particles);

 private:
  int _verbosity;
  Jet::ALGO _algo;
  float _par;
};

#endif
