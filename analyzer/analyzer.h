#ifndef ANALYZER_H
#define ANALYZER_H
//-----------------------------------------------------------------------------
// File:        analyzer.h
// Description: Analyzer header for ntuples created by TheNtupleMaker
// Created:     Sun Apr 27 17:23:45 2014 by mkanalyzer.py
// Author:      Shakepeare's ghost
//-----------------------------------------------------------------------------
// -- System

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cmath>

#include "analyzerutil.h"
#include "treestream.h"
#include "pdg.h"

// -- Root

#include "TROOT.h"
#include "TApplication.h"
#include "TDirectory.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TKey.h"
#include "TH1F.h"
#include "TH2F.h"

namespace evt {
//-----------------------------------------------------------------------------
// --- Declare variables
//-----------------------------------------------------------------------------
std::vector<float>	Jet1_combinedSecondaryVertexBJetTags(200,0);
std::vector<int>	Jet1_impactParameter(200,0);
std::vector<double>	Jet1_pt(200,0);
std::vector<float>	Jet_combinedSecondaryVertexBJetTags(200,0);
std::vector<int>	Jet_impactParameter(200,0);
std::vector<double>	Jet_pt(200,0);
int	nJet;
int	nJet1;

//-----------------------------------------------------------------------------
// --- indexmap keeps track of which objects have been flagged for selection
// --- IMPORTANT: initialize must be called every event to clear selection
std::map<std::string, std::vector<int> > indexmap;
void initialize()
{
  for(std::map<std::string, std::vector<int> >::iterator
    item=indexmap.begin(); 
    item != indexmap.end();
	++item)
	item->second.clear();
}

void select(std::string objname)
{
  indexmap[objname] = std::vector<int>();
}

void select(std::string objname, int index)
{
  try
    {
      indexmap[objname].push_back(index);
    }
  catch (...)
    {
      std::cout << "*** perhaps you failed to call select for " 
                << objname << std::endl;
      assert(0);
    }
}

//-----------------------------------------------------------------------------
// --- Structs can be filled by calling fillObjects()
// --- after the call to stream.read(...)
//-----------------------------------------------------------------------------
struct Jet_s
{
  float	combinedSecondaryVertexBJetTags;
  double	pt;
  int	impactParameter;
};
std::vector<Jet_s> Jet(200);

std::ostream& operator<<(std::ostream& os, const Jet_s& o)
{
  char r[1024];
  os << "Jet" << std::endl;
  sprintf(r, "  %-32s: %f\n", "combinedSecondaryVertexBJetTags", (double)o.combinedSecondaryVertexBJetTags); os << r;
  sprintf(r, "  %-32s: %f\n", "pt", (double)o.pt); os << r;
  sprintf(r, "  %-32s: %f\n", "impactParameter", (double)o.impactParameter); os << r;
  return os;
}
//-----------------------------------------------------------------------------
struct Jet1_s
{
  float	combinedSecondaryVertexBJetTags;
  int	impactParameter;
  double	pt;
};
std::vector<Jet1_s> Jet1(200);

std::ostream& operator<<(std::ostream& os, const Jet1_s& o)
{
  char r[1024];
  os << "Jet1" << std::endl;
  sprintf(r, "  %-32s: %f\n", "combinedSecondaryVertexBJetTags", (double)o.combinedSecondaryVertexBJetTags); os << r;
  sprintf(r, "  %-32s: %f\n", "impactParameter", (double)o.impactParameter); os << r;
  sprintf(r, "  %-32s: %f\n", "pt", (double)o.pt); os << r;
  return os;
}
//-----------------------------------------------------------------------------

inline void fillJet()
{
  Jet.resize(Jet_combinedSecondaryVertexBJetTags.size());
  for(unsigned int i=0; i < Jet.size(); ++i)
    {
      Jet[i].combinedSecondaryVertexBJetTags	= Jet_combinedSecondaryVertexBJetTags[i];
      Jet[i].pt	= Jet_pt[i];
      Jet[i].impactParameter	= Jet_impactParameter[i];
    }
}

inline void fillJet1()
{
  Jet1.resize(Jet1_combinedSecondaryVertexBJetTags.size());
  for(unsigned int i=0; i < Jet1.size(); ++i)
    {
      Jet1[i].combinedSecondaryVertexBJetTags	= Jet1_combinedSecondaryVertexBJetTags[i];
      Jet1[i].impactParameter	= Jet1_impactParameter[i];
      Jet1[i].pt	= Jet1_pt[i];
    }
}


void fillObjects()
{
  fillJet();
  fillJet1();
}

//-----------------------------------------------------------------------------
// --- Call saveSelectedObjects() just before call to addEvent if
// --- you wish to save only the selected objects
//-----------------------------------------------------------------------------
// Select objects for which the select function was called
void saveSelectedObjects()
{
  int n = 0;

  n = 0;
  try
    {
       n = indexmap["Jet"].size();
    }
  catch (...)
    {}
  if ( n > 0 )
    {
      std::vector<int>& index = indexmap["Jet"];
      for(int i=0; i < n; ++i)
        {
          int j = index[i];
          Jet_combinedSecondaryVertexBJetTags[i]	= Jet_combinedSecondaryVertexBJetTags[j];
          Jet_pt[i]	= Jet_pt[j];
          Jet_impactParameter[i]	= Jet_impactParameter[j];
        }
      nJet = n;
    }

  n = 0;
  try
    {
       n = indexmap["Jet1"].size();
    }
  catch (...)
    {}
  if ( n > 0 )
    {
      std::vector<int>& index = indexmap["Jet1"];
      for(int i=0; i < n; ++i)
        {
          int j = index[i];
          Jet1_combinedSecondaryVertexBJetTags[i]	= Jet1_combinedSecondaryVertexBJetTags[j];
          Jet1_impactParameter[i]	= Jet1_impactParameter[j];
          Jet1_pt[i]	= Jet1_pt[j];
        }
      nJet1 = n;
    }
}

//-----------------------------------------------------------------------------
// --- Select variables to be read
//-----------------------------------------------------------------------------
void selectVariables(itreestream& stream)
{
  stream.select("patJet_selectedPatJetsPFlow.combinedSecondaryVertexBJetTags", Jet1_combinedSecondaryVertexBJetTags);
  stream.select("patJet_selectedPatJetsPFlow.impactParameter", Jet1_impactParameter);
  stream.select("patJet_selectedPatJetsPFlow.pt", Jet1_pt);
  stream.select("patJet_selectedPatJetsAK5PF.combinedSecondaryVertexBJetTags", Jet_combinedSecondaryVertexBJetTags);
  stream.select("patJet_selectedPatJetsAK5PF.impactParameter", Jet_impactParameter);
  stream.select("patJet_selectedPatJetsAK5PF.pt", Jet_pt);
  stream.select("npatJet_selectedPatJetsAK5PF", nJet);
  stream.select("npatJet_selectedPatJetsPFlow", nJet1);

}
}; // end namespace evt
#endif
