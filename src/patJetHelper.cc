//-----------------------------------------------------------------------------
// Subsystem:   Ntuples
// Package:     MyNtuple
// Description: TheNtupleMaker helper class for pat::Jet
// Created:     Sun Apr 27 17:08:13 2014
// Author:      Shakepeare's ghost      
//-----------------------------------------------------------------------------
#include "Ntuples/MyNtuple/interface/patJetHelper.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
//-----------------------------------------------------------------------------
using namespace std;
using namespace pat;
//-----------------------------------------------------------------------------
// This constructor is called once per job
JetHelper::JetHelper()
  : HelperFor<pat::Jet>() {}
    
JetHelper::~JetHelper() {}

// -- Called once per event
//void JetHelper::analyzeEvent()
//{
//
//}

//-- Called once per object
void JetHelper::analyzeObject()
{
	pt100_ = object->pt()+100.;
}

// -- User access methods
//double JetHelper::someMethod()  const
//{
//  return  //-- some-value --
//}

double JetHelper::pt100() const
{
	return pt100_;
}
