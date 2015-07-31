// $Id: $                                                                                             

/*!
 * \file PHG4OuterHcalFieldSetup.cc
 * \brief 
 * \author Jin Huang <jhuang@bnl.gov>
 * \version $Revision:   $
 * \date $Date: $
 */

#include "PHG4OuterHcalFieldSetup.h"
#include "PHG4OuterHcalField.h"

#include <g4field/PHG4Field2D.h>
#include <g4field/PHG4Field3D.h>
#include <g4field/PHG4FieldsPHENIX.h>

#include <fun4all/Fun4AllServer.h>
#include <fun4all/getClass.h>

#include <phool/PHCompositeNode.h>
#include <phool/PHIODataNode.h>
#include <phool/PHNodeIterator.h>

#include <Geant4/G4SystemOfUnits.hh>
#include <Geant4/G4UniformMagField.hh>
#include <Geant4/G4MagneticField.hh>
#include <Geant4/G4FieldManager.hh>
#include <Geant4/G4TransportationManager.hh>
#include <Geant4/G4EquationOfMotion.hh>
#include <Geant4/G4EqMagElectricField.hh>
#include <Geant4/G4Mag_UsualEqRhs.hh>
#include <Geant4/G4MagIntegratorStepper.hh>
#include <Geant4/G4MagIntegratorDriver.hh>
#include <Geant4/G4ChordFinder.hh>

#include <Geant4/G4ExplicitEuler.hh>
#include <Geant4/G4ImplicitEuler.hh>
#include <Geant4/G4SimpleRunge.hh>
#include <Geant4/G4SimpleHeum.hh>
#include <Geant4/G4ClassicalRK4.hh>
#include <Geant4/G4HelixExplicitEuler.hh>
#include <Geant4/G4HelixImplicitEuler.hh>
#include <Geant4/G4HelixSimpleRunge.hh>
#include <Geant4/G4CashKarpRKF45.hh>
#include <Geant4/G4RKG3_Stepper.hh>

PHG4OuterHcalFieldSetup::PHG4OuterHcalFieldSetup( G4int steelPlates,
    G4double scintiGap, G4double tiltAngle):
    /*G4int*/n_steel_plates(steelPlates),
    /*G4double*/scinti_gap(scintiGap),
    /*G4double*/tilt_angle(tiltAngle)
{
  fMinStep = 0.005 * mm; // minimal step of 10 microns

  fFieldManagerIron = new G4FieldManager();
  fFieldManagerGap = new G4FieldManager();


}

PHG4OuterHcalFieldSetup::~PHG4OuterHcalFieldSetup()
{
//  interesting that pointers in the F03FieldSetup was not cleaned up at the end
}

