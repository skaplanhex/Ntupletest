// ----------------------------------------------------------------------------
// Created: Sun Apr 27 17:08:13 2014 by mkhelper.py
// Author:  Shakepeare's ghost      
// ----------------------------------------------------------------------------
#include "PhysicsTools/TheNtupleMaker/interface/UserBuffer.h"
#include "PhysicsTools/TheNtupleMaker/interface/pluginfactory.h"
#include "Ntuples/MyNtuple/interface/patJetHelper.h"
typedef UserBuffer<pat::Jet, pat::JetHelper, COLLECTION>
patJetHelper_t;
DEFINE_EDM_PLUGIN(BufferFactory, patJetHelper_t,
                  "patJetHelper");
