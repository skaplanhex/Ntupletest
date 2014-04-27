#-------------------------------------------------------------------------
# Created: Fri Apr 25 14:53:25 2014 by mkntuplecfi.py
#-------------------------------------------------------------------------
import FWCore.ParameterSet.Config as cms
demo =\
cms.EDAnalyzer("TheNtupleMaker",
               ntupleName = cms.untracked.string("ntuple.root"),
               analyzerName = cms.untracked.string("analyzer.cc"),


# NOTE: the names listed below will be the prefixes for
#       the associated C++ variables created by mkanalyzer.py
#       and the asscociated C++ structs.

               buffers =
               cms.untracked.
               vstring(
    'Jet',
    'Jet1'
    ),

               Jet =
               cms.untracked.
               vstring(
    'patJet                          selectedPatJetsAK5PF            200',
    #---------------------------------------------------------------------
    'float  bDiscriminator("combinedSecondaryVertexBJetTags")',
    'double pt()',
    'bool  hasTagInfo("impactParameter")',
    'double pt100()'
    ),
               Jet1 =
               cms.untracked.
               vstring(
    'patJet                          selectedPatJetsPFlow            200',
    #---------------------------------------------------------------------
    'float  bDiscriminator("combinedSecondaryVertexBJetTags")',
    'bool  hasTagInfo("impactParameter")',
    'double pt()',
    'double pt100()'
    )
               )
