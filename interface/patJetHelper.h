#ifndef PATJETHELPER_H
#define PATJETHELPER_H
//-----------------------------------------------------------------------------
// Subsystem:   Ntuples
// Package:     MyNtuple
// Description: TheNtupleMaker helper class for pat::Jet
// Created:     Sun Apr 27 17:08:13 2014
// Author:      Shakepeare's ghost      
//-----------------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include "PhysicsTools/TheNtupleMaker/interface/HelperFor.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
//-----------------------------------------------------------------------------
// Definitions:
//   helper:        object of class JetHelper
//   helped object: object of class pat::Jet
//
//
// The following variables are automatically defined and available to
//       all methods:
//
//         blockname          name of config. buffer object (config block) 
//         buffername         name of buffer in config block
//         labelname          name of label in config block (for getByLabel)
//         parameter          parameter (as key, value pairs)
//                            accessed as in the following example:
//
//                            string param = parameter("label");
//
//         0. hltconfig       pointer to HLTConfigProvider
//                            Note: this will be zero if HLTConfigProvider
//                                  has not been properly initialized
//
//         1. config          pointer to global ParameterSet object
//         2. event           pointer to the current event
//         3. object          pointer to the current helped object
//         4. oindex          index of current helped object
//
//         5. index           index of item(s) returned by helper.
//                            Note 1: an item is associated with all
//                                    helper methods (think of it as an
//                                    extension of the helped object)
//                                  
//                            Note 2: index may differ from oindex if,
//                                    for a given helped object, the count
//                                    variable (see below) differs from 1.
//
//         6. count           number of items per helped object (default=1)
//                            Note:
//                                  count = 0  ==> current helped object is
//                                                 to be skipped
//
//                                  count = 1  ==> current helped object is
//                                                 to be kept
//
//                                  count > 1  ==> current helped object is
//                                                 associated with "count"
//                                                 items, where each item
//                                                 is associated with all the
//                                                 helper methods
//
//       variables 0-6 are initialized by TheNtupleMaker.
//       variables 0-5 should not be changed.
//       variable    6 can be changed by the helper to control whether a
//                     helped object should be kept or generates more items
//-----------------------------------------------------------------------------

namespace pat
{
  /// A helper class for pat::Jet.
  class JetHelper : public HelperFor<pat::Jet>
  {
  public:
	///
	JetHelper();

	virtual ~JetHelper();

	// Uncomment if this class does some event-level analysis
	// virtual void analyzeEvent();
	 
	// Uncomment if this class does some object-level analysis
	virtual void analyzeObject();

	// ---------------------------------------------------------
	// -- User access methods go here
	// ---------------------------------------------------------
    double pt100() const;

	
  private:
    // -- User internals
    double pt100_;


  public:
    // ---------------------------------------------------------
    // -- Access Methods
    // ---------------------------------------------------------

	// WARNING: some methods may fail to compile because of coding
	//          problems in one of the CMSSW base classes. If so,
	//          just comment out the offending method and try again.
  


    // from pat::Jet
    const reco::TrackRefVector associatedTracks() const
    { return object->associatedTracks(); }

    // from pat::Jet
    const std::vector<std::string> availableJECLevels(int set=0) const
    { return object->availableJECLevels(set); }

    // from pat::Jet
    const std::vector<std::string> availableJECLevels(std::string set) const
    { return object->availableJECLevels(set); }

    // from pat::Jet
    const std::vector<std::string> availableJECSets() const
    { return object->availableJECSets(); }

    // from pat::Jet
    float bDiscriminator(std::string theLabel) const
    { return object->bDiscriminator(theLabel); }

    // from reco::LeafCandidate
    math::XYZVector boostToCM() const { return object->boostToCM(); }

    // from pat::Jet
    const pat::CaloSpecific caloSpecific() const
    { return object->caloSpecific(); }

    // from pat::Jet
    const CaloTowerFwdPtrVector caloTowersFwdPtr() const
    { return object->caloTowersFwdPtr(); }

    // from reco::LeafCandidate
    int charge() const { return object->charge(); }

    // from pat::Jet
    float chargedEmEnergy() const { return object->chargedEmEnergy(); }

    // from pat::Jet
    float chargedEmEnergyFraction() const
    { return object->chargedEmEnergyFraction(); }

    // from pat::Jet
    float chargedHadronEnergy() const { return object->chargedHadronEnergy(); }

    // from pat::Jet
    float chargedHadronEnergyFraction() const
    { return object->chargedHadronEnergyFraction(); }

    // from pat::Jet
    int chargedHadronMultiplicity() const
    { return object->chargedHadronMultiplicity(); }

    // from pat::Jet
    float chargedMuEnergy() const { return object->chargedMuEnergy(); }

    // from pat::Jet
    float chargedMuEnergyFraction() const
    { return object->chargedMuEnergyFraction(); }

    // from pat::Jet
    int chargedMultiplicity() const { return object->chargedMultiplicity(); }

    // from reco::Jet
    float constituentEtaPhiSpread() const
    { return object->constituentEtaPhiSpread(); }

    // from reco::Jet
    float constituentPtDistribution() const
    { return object->constituentPtDistribution(); }

    // from pat::Jet
    pat::Jet
    correctedJet(std::string level, std::string flavor="none", std::string set="") const
    { return object->correctedJet(level, flavor, set); }

    // from pat::Jet
    /**
    pat::Jet
    correctedJet(unsigned int level, pat::JetCorrFactors::Flavor flavor=NONE, unsigned int set=0) const
    { return object->correctedJet(level, flavor, set); }
    */

    // from pat::Jet
    const math::XYZTLorentzVector
    correctedP4(std::string level, std::string flavor="none", std::string set="") const
    { return object->correctedP4(level, flavor, set); }

    // from pat::Jet
    /**
    const math::XYZTLorentzVector
    correctedP4(unsigned int level, pat::JetCorrFactors::Flavor flavor=NONE, unsigned int set=0) const
    { return object->correctedP4(level, flavor, set); }
    */

    // from pat::Jet
    pat::JetCorrFactors::Flavor currentJECFlavor() const
    { return object->currentJECFlavor(); }

    // from pat::Jet
    std::string currentJECLevel() const { return object->currentJECLevel(); }

    // from pat::Jet
    std::string currentJECSet() const { return object->currentJECSet(); }

    // from pat::Jet
    reco::Candidate* daughter(size_t i) const
    { return (reco::Candidate*)object->daughter(i); }

    // from reco::CompositePtrCandidate
    reco::CandidatePtr daughterPtr(size_t i) const
    { return object->daughterPtr(i); }

    // from reco::CompositePtrCandidate
    const std::vector<edm::Ptr<reco::Candidate> > daughterPtrVector() const
    { return object->daughterPtrVector(); }

    // from reco::Jet
    float detectorEta(float fZVertex, float fPhysicsEta) const
    { return object->detectorEta(fZVertex, fPhysicsEta); }

    // from reco::Jet
    /**
    math::XYZTLorentzVector
    detectorP4(math::XYZPoint vertex, reco::Candidate inParticle) const
    { return object->detectorP4(vertex, inParticle); }
    */

    // from pat::PATObject<reco::Jet>
    std::vector<std::pair<std::string,pat::LookupTableRecord> >
    efficiencies() const
    { return object->efficiencies(); }

    // from pat::PATObject<reco::Jet>
    const pat::LookupTableRecord efficiency(std::string name) const
    { return object->efficiency(name); }

    // from pat::PATObject<reco::Jet>
    const std::vector<std::string> efficiencyNames() const
    { return object->efficiencyNames(); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::LookupTableRecord> efficiencyValues() const
    { return object->efficiencyValues(); }

    // from pat::Jet
    float elecMultiplicity() const { return object->elecMultiplicity(); }

    // from pat::Jet
    const reco::TrackRefVector elecsInVertexInCalo() const
    { return object->elecsInVertexInCalo(); }

    // from pat::Jet
    const reco::TrackRefVector elecsInVertexOutCalo() const
    { return object->elecsInVertexOutCalo(); }

    // from pat::Jet
    const reco::TrackRefVector elecsOutVertexInCalo() const
    { return object->elecsOutVertexInCalo(); }

    // from pat::Jet
    float electronEnergy() const { return object->electronEnergy(); }

    // from pat::Jet
    float electronEnergyFraction() const
    { return object->electronEnergyFraction(); }

    // from pat::Jet
    int electronMultiplicity() const { return object->electronMultiplicity(); }

    // from pat::Jet
    float emEnergyFraction() const { return object->emEnergyFraction(); }

    // from pat::Jet
    float emEnergyInEB() const { return object->emEnergyInEB(); }

    // from pat::Jet
    float emEnergyInEE() const { return object->emEnergyInEE(); }

    // from pat::Jet
    float emEnergyInHF() const { return object->emEnergyInHF(); }

    // from reco::LeafCandidate
    double energy() const { return object->energy(); }

    // from pat::Jet
    float energyFractionHadronic() const
    { return object->energyFractionHadronic(); }

    // from reco::LeafCandidate
    double et() const { return object->et(); }

    // from reco::LeafCandidate
    double eta() const { return object->eta(); }

    // from reco::Jet
    float etaetaMoment() const { return object->etaetaMoment(); }

    // from reco::Jet
    float etaphiMoment() const { return object->etaphiMoment(); }

    // from reco::Jet
    reco::Jet::EtaPhiMoments etaPhiStatistics() const
    { return object->etaPhiStatistics(); }

    // from reco::Jet
    float etInAnnulus(float fRmin, float fRmax) const
    { return object->etInAnnulus(fRmin, fRmax); }

    // from pat::Jet
    reco::GenJet* genJet() const { return (reco::GenJet*)object->genJet(); }

    // from pat::Jet
    const edm::FwdRef<std::vector<reco::GenJet>,reco::GenJet,edm::refhelper::FindUsingAdvance<std::vector<reco::GenJet>,reco::GenJet> >
    genJetFwdRef() const
    { return object->genJetFwdRef(); }

    // from pat::PATObject<reco::Jet>
    reco::GenParticle* genParticle(size_t idx=0) const
    { return (reco::GenParticle*)object->genParticle(idx); }

    // from pat::PATObject<reco::Jet>
    /**
    reco::GenParticleRef
    genParticleById(int pdgId, int status, uint8_t autoCharge=0) const
    { return object->genParticleById(pdgId, status, autoCharge); }
    */

    // from pat::PATObject<reco::Jet>
    reco::GenParticleRef genParticleRef(size_t idx=0) const
    { return object->genParticleRef(idx); }

    // from pat::PATObject<reco::Jet>
    std::vector<reco::GenParticleRef> genParticleRefs() const
    { return object->genParticleRefs(); }

    // from pat::PATObject<reco::Jet>
    size_t genParticlesSize() const { return object->genParticlesSize(); }

    // from pat::Jet
    reco::GenParticle* genParton() const
    { return (reco::GenParticle*)object->genParton(); }

    // from pat::Jet
    CaloTowerPtr getCaloConstituent(unsigned int fIndex) const
    { return object->getCaloConstituent(fIndex); }

    // from pat::Jet
    const std::vector<edm::Ptr<CaloTower> > getCaloConstituents() const
    { return object->getCaloConstituents(); }

    // from reco::Jet
    std::vector<edm::Ptr<reco::Candidate> > getJetConstituents() const
    { return object->getJetConstituents(); }

    // from reco::Jet
    std::vector<const reco::Candidate*> getJetConstituentsQuick() const
    { return object->getJetConstituentsQuick(); }

    // from pat::PATObject<reco::Jet>
    const pat::CandKinResolution getKinResolution(std::string label="") const
    { return object->getKinResolution(label); }

    // from pat::Jet
    const std::vector<std::pair<std::string,float> > getPairDiscri() const
    { return object->getPairDiscri(); }

    // from pat::Jet
    reco::PFCandidatePtr getPFConstituent(unsigned int fIndex) const
    { return object->getPFConstituent(fIndex); }

    // from pat::Jet
    const std::vector<edm::Ptr<reco::PFCandidate> > getPFConstituents() const
    { return object->getPFConstituents(); }

    // from pat::Jet
    float hadEnergyInHB() const { return object->hadEnergyInHB(); }

    // from pat::Jet
    float hadEnergyInHE() const { return object->hadEnergyInHE(); }

    // from pat::Jet
    float hadEnergyInHF() const { return object->hadEnergyInHF(); }

    // from pat::Jet
    float hadEnergyInHO() const { return object->hadEnergyInHO(); }

    // from pat::Jet
    int hadronFlavour() const { return object->hadronFlavour(); }

    // from pat::PATObject<reco::Jet>
    bool hasKinResolution(std::string label="") const
    { return object->hasKinResolution(label); }

    // from pat::PATObject<reco::Jet>
    bool hasOverlaps(std::string label) const
    { return object->hasOverlaps(label); }

    // from pat::Jet
    bool hasTagInfo(std::string label) const
    { return object->hasTagInfo(label); }

    // from pat::PATObject<reco::Jet>
    bool hasUserCand(std::string key) const
    { return object->hasUserCand(key); }

    // from pat::PATObject<reco::Jet>
    bool hasUserData(std::string key) const
    { return object->hasUserData(key); }

    // from pat::PATObject<reco::Jet>
    bool hasUserFloat(char* key) const { return object->hasUserFloat(key); }

    // from pat::PATObject<reco::Jet>
    bool hasUserFloat(std::string key) const
    { return object->hasUserFloat(key); }

    // from pat::PATObject<reco::Jet>
    bool hasUserInt(std::string key) const { return object->hasUserInt(key); }

    // from pat::Jet
    float HFEMEnergy() const { return object->HFEMEnergy(); }

    // from pat::Jet
    float HFEMEnergyFraction() const { return object->HFEMEnergyFraction(); }

    // from pat::Jet
    int HFEMMultiplicity() const { return object->HFEMMultiplicity(); }

    // from pat::Jet
    float HFHadronEnergy() const { return object->HFHadronEnergy(); }

    // from pat::Jet
    float HFHadronEnergyFraction() const
    { return object->HFHadronEnergyFraction(); }

    // from pat::Jet
    int HFHadronMultiplicity() const { return object->HFHadronMultiplicity(); }

    // from pat::Jet
    bool isBasicJet() const { return object->isBasicJet(); }

    // from pat::Jet
    bool isCaloJet() const { return object->isCaloJet(); }

    // from reco::LeafCandidate
    bool isCaloMuon() const { return object->isCaloMuon(); }

    // from reco::LeafCandidate
    bool isConvertedPhoton() const { return object->isConvertedPhoton(); }

    // from reco::LeafCandidate
    bool isElectron() const { return object->isElectron(); }

    // from reco::LeafCandidate
    bool isGlobalMuon() const { return object->isGlobalMuon(); }

    // from reco::Jet
    bool isJet() const { return object->isJet(); }

    // from pat::Jet
    bool isJPTJet() const { return object->isJPTJet(); }

    // from reco::LeafCandidate
    bool isMuon() const { return object->isMuon(); }

    // from pat::Jet
    bool isPFJet() const { return object->isPFJet(); }

    // from reco::LeafCandidate
    bool isPhoton() const { return object->isPhoton(); }

    // from reco::LeafCandidate
    bool isStandAloneMuon() const { return object->isStandAloneMuon(); }

    // from reco::LeafCandidate
    bool isTrackerMuon() const { return object->isTrackerMuon(); }

    // from pat::Jet
    float
    jecFactor(std::string level, std::string flavor="none", std::string set="") const
    { return object->jecFactor(level, flavor, set); }

    // from pat::Jet
    /**
    float
    jecFactor(unsigned int level, pat::JetCorrFactors::Flavor flavor=NONE, unsigned int set=0) const
    { return object->jecFactor(level, flavor, set); }
    */

    // from pat::Jet
    bool jecSetAvailable(std::string set) const
    { return object->jecSetAvailable(set); }

    // from pat::Jet
    bool jecSetAvailable(unsigned int set) const
    { return object->jecSetAvailable(set); }

    // from pat::Jet
    bool jecSetsAvailable() const { return object->jecSetsAvailable(); }

    // from reco::Jet
    float jetArea() const { return object->jetArea(); }

    // from pat::Jet
    float jetCharge() const { return object->jetCharge(); }

    // from pat::Jet
    const reco::JetFlavourInfo jetFlavourInfo() const
    { return object->jetFlavourInfo(); }

    // from pat::Jet
    const reco::JetID jetID() const { return object->jetID(); }

    // from pat::Jet
    const pat::JPTSpecific jptSpecific() const
    { return object->jptSpecific(); }

    // from reco::LeafCandidate
    bool longLived() const { return object->longLived(); }

    // from reco::LeafCandidate
    double mass() const { return object->mass(); }

    // from reco::LeafCandidate
    bool massConstraint() const { return object->massConstraint(); }

    // from reco::LeafCandidate
    double massSqr() const { return object->massSqr(); }

    // from reco::Jet
    float maxDistance() const { return object->maxDistance(); }

    // from pat::Jet
    float maxEInEmTowers() const { return object->maxEInEmTowers(); }

    // from pat::Jet
    float maxEInHadTowers() const { return object->maxEInHadTowers(); }

    // from reco::LeafCandidate
    math::XYZVector momentum() const { return object->momentum(); }

    // from reco::CompositePtrCandidate
    reco::Candidate* mother(size_t i=0) const
    { return (reco::Candidate*)object->mother(i); }

    // from reco::LeafCandidate
    double mt() const { return object->mt(); }

    // from reco::LeafCandidate
    double mtSqr() const { return object->mtSqr(); }

    // from pat::Jet
    float muonEnergy() const { return object->muonEnergy(); }

    // from pat::Jet
    float muonEnergyFraction() const { return object->muonEnergyFraction(); }

    // from pat::Jet
    int muonMultiplicity() const { return object->muonMultiplicity(); }

    // from pat::Jet
    const reco::TrackRefVector muonsInVertexInCalo() const
    { return object->muonsInVertexInCalo(); }

    // from pat::Jet
    const reco::TrackRefVector muonsInVertexOutCalo() const
    { return object->muonsInVertexOutCalo(); }

    // from pat::Jet
    const reco::TrackRefVector muonsOutVertexInCalo() const
    { return object->muonsOutVertexInCalo(); }

    // from pat::Jet
    int n60() const { return object->n60(); }

    // from pat::Jet
    int n90() const { return object->n90(); }

    // from reco::Jet
    int nCarrying(float fFraction) const
    { return object->nCarrying(fFraction); }

    // from reco::Jet
    int nConstituents() const { return object->nConstituents(); }

    // from pat::Jet
    float neutralEmEnergy() const { return object->neutralEmEnergy(); }

    // from pat::Jet
    float neutralEmEnergyFraction() const
    { return object->neutralEmEnergyFraction(); }

    // from pat::Jet
    float neutralHadronEnergy() const { return object->neutralHadronEnergy(); }

    // from pat::Jet
    float neutralHadronEnergyFraction() const
    { return object->neutralHadronEnergyFraction(); }

    // from pat::Jet
    int neutralHadronMultiplicity() const
    { return object->neutralHadronMultiplicity(); }

    // from pat::Jet
    int neutralMultiplicity() const { return object->neutralMultiplicity(); }

    // from reco::Jet
    int nPasses() const { return object->nPasses(); }

    // from pat::Jet
    size_t numberOfDaughters() const { return object->numberOfDaughters(); }

    // from reco::CompositePtrCandidate
    size_t numberOfMothers() const { return object->numberOfMothers(); }

    // from reco::CompositePtrCandidate
    size_t numberOfSourceCandidatePtrs() const
    { return object->numberOfSourceCandidatePtrs(); }

    // from pat::PATObject<reco::Jet>
    reco::Candidate* originalObject() const
    { return (reco::Candidate*)object->originalObject(); }

    // from pat::PATObject<reco::Jet>
    const edm::Ptr<reco::Candidate> originalObjectRef() const
    { return object->originalObjectRef(); }

    // from pat::PATObject<reco::Jet>
    const std::vector<std::string> overlapLabels() const
    { return object->overlapLabels(); }

    // from pat::PATObject<reco::Jet>
    const edm::PtrVector<reco::Candidate> overlaps(std::string label) const
    { return object->overlaps(label); }

    // from reco::LeafCandidate
    double p() const { return object->p(); }

    // from reco::LeafCandidate
    const math::XYZTLorentzVector p4() const { return object->p4(); }

    // from pat::Jet
    int partonFlavour() const { return object->partonFlavour(); }

    // from reco::LeafCandidate
    int pdgId() const { return object->pdgId(); }

    // from pat::Jet
    const reco::PFCandidateFwdPtrVector pfCandidatesFwdPtr() const
    { return object->pfCandidatesFwdPtr(); }

    // from pat::Jet
    const pat::PFSpecific pfSpecific() const { return object->pfSpecific(); }

    // from reco::LeafCandidate
    double phi() const { return object->phi(); }

    // from reco::Jet
    float phiphiMoment() const { return object->phiphiMoment(); }

    // from pat::Jet
    float photonEnergy() const { return object->photonEnergy(); }

    // from pat::Jet
    float photonEnergyFraction() const
    { return object->photonEnergyFraction(); }

    // from pat::Jet
    int photonMultiplicity() const { return object->photonMultiplicity(); }

    // from reco::Jet
    float physicsEta(float fZVertex, float fDetectorEta) const
    { return object->physicsEta(fZVertex, fDetectorEta); }

    // from reco::Jet
    /**
    math::XYZTLorentzVector
    physicsP4(math::XYZPoint newVertex, reco::Candidate inParticle, math::XYZPoint oldVertex=ROOT::Math::PositionVector3D<ROOT::Math::Cartesian3D<double>, ROOT::Math::DefaultCoordinateSystemTag>(((const double&)((const double*)(&0.0))), ((const double&)((const double*)(&0.0))), ((const double&)((const double*)(&0.0))))) const
    { return object->physicsP4(newVertex, inParticle, oldVertex); }
    */

    // from reco::Jet
    float pileup() const { return object->pileup(); }

    // from pat::Jet
    const reco::TrackRefVector pionsInVertexInCalo() const
    { return object->pionsInVertexInCalo(); }

    // from pat::Jet
    const reco::TrackRefVector pionsInVertexOutCalo() const
    { return object->pionsInVertexOutCalo(); }

    // from pat::Jet
    const reco::TrackRefVector pionsOutVertexInCalo() const
    { return object->pionsOutVertexInCalo(); }

    // from reco::LeafCandidate
    const math::PtEtaPhiMLorentzVector polarP4() const
    { return object->polarP4(); }

    // from reco::LeafCandidate
    double pt() const { return object->pt(); }

    // from reco::LeafCandidate
    double px() const { return object->px(); }

    // from reco::LeafCandidate
    double py() const { return object->py(); }

    // from reco::LeafCandidate
    double pz() const { return object->pz(); }

    // from reco::LeafCandidate
    double rapidity() const { return object->rapidity(); }

    // from pat::PATObject<reco::Jet>
    double resolE(std::string label="") const { return object->resolE(label); }

    // from pat::PATObject<reco::Jet>
    double resolEt(std::string label="") const
    { return object->resolEt(label); }

    // from pat::PATObject<reco::Jet>
    double resolEta(std::string label="") const
    { return object->resolEta(label); }

    // from pat::PATObject<reco::Jet>
    double resolM(std::string label="") const { return object->resolM(label); }

    // from pat::PATObject<reco::Jet>
    double resolP(std::string label="") const { return object->resolP(label); }

    // from pat::PATObject<reco::Jet>
    double resolPhi(std::string label="") const
    { return object->resolPhi(label); }

    // from pat::PATObject<reco::Jet>
    double resolPInv(std::string label="") const
    { return object->resolPInv(label); }

    // from pat::PATObject<reco::Jet>
    double resolPt(std::string label="") const
    { return object->resolPt(label); }

    // from pat::PATObject<reco::Jet>
    double resolPx(std::string label="") const
    { return object->resolPx(label); }

    // from pat::PATObject<reco::Jet>
    double resolPy(std::string label="") const
    { return object->resolPy(label); }

    // from pat::PATObject<reco::Jet>
    double resolPz(std::string label="") const
    { return object->resolPz(label); }

    // from pat::PATObject<reco::Jet>
    double resolTheta(std::string label="") const
    { return object->resolTheta(label); }

    // from reco::CompositePtrCandidate
    reco::CandidatePtr sourceCandidatePtr(size_t i) const
    { return object->sourceCandidatePtr(i); }

    // from reco::LeafCandidate
    int status() const { return object->status(); }

    // from pat::Jet
    reco::BaseTagInfo* tagInfo(std::string label) const
    { return (reco::BaseTagInfo*)object->tagInfo(label); }

    // from pat::Jet
    reco::SecondaryVertexTagInfo*
    tagInfoSecondaryVertex(std::string label="") const
    { return (reco::SecondaryVertexTagInfo*)object->tagInfoSecondaryVertex(label); }

    // from pat::Jet
    const pat::TagInfoFwdPtrCollection tagInfosFwdPtr() const
    { return object->tagInfosFwdPtr(); }

    // from pat::Jet
    reco::SoftLeptonTagInfo* tagInfoSoftLepton(std::string label="") const
    { return (reco::SoftLeptonTagInfo*)object->tagInfoSoftLepton(label); }

    // from pat::Jet
    reco::TrackIPTagInfo* tagInfoTrackIP(std::string label="") const
    { return (reco::TrackIPTagInfo*)object->tagInfoTrackIP(label); }

    // from reco::LeafCandidate
    double theta() const { return object->theta(); }

    // from reco::LeafCandidate
    int threeCharge() const { return object->threeCharge(); }

    // from pat::Jet
    float towersArea() const { return object->towersArea(); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone* triggerObjectMatch(size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatch(idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByAlgorithm(char* nameAlgorithm, bool algoCondAccepted=true, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByAlgorithm(nameAlgorithm, algoCondAccepted, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByAlgorithm(char* nameAlgorithm, unsigned int algoCondAccepted, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByAlgorithm(nameAlgorithm, algoCondAccepted, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByAlgorithm(std::string nameAlgorithm, bool algoCondAccepted=true, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByAlgorithm(nameAlgorithm, algoCondAccepted, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByAlgorithm(std::string nameAlgorithm, unsigned int algoCondAccepted, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByAlgorithm(nameAlgorithm, algoCondAccepted, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByCollection(char* coll, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByCollection(coll, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByCollection(std::string coll, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByCollection(coll, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByCondition(char* nameCondition, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByCondition(nameCondition, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByCondition(std::string nameCondition, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByCondition(nameCondition, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByFilter(char* labelFilter, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByFilter(labelFilter, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByFilter(std::string labelFilter, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByFilter(labelFilter, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByFilterID(unsigned int triggerObjectType, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByFilterID(triggerObjectType, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByPath(char* namePath, bool pathLastFilterAccepted=false, bool pathL3FilterAccepted=true, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByPath(namePath, pathLastFilterAccepted, pathL3FilterAccepted, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByPath(char* namePath, unsigned int pathLastFilterAccepted, unsigned int pathL3FilterAccepted=1, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByPath(namePath, pathLastFilterAccepted, pathL3FilterAccepted, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByPath(std::string namePath, bool pathLastFilterAccepted=false, bool pathL3FilterAccepted=true, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByPath(namePath, pathLastFilterAccepted, pathL3FilterAccepted, idx); }

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByPath(std::string namePath, unsigned int pathLastFilterAccepted, unsigned int pathL3FilterAccepted=1, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByPath(namePath, pathLastFilterAccepted, pathL3FilterAccepted, idx); }

    // from pat::PATObject<reco::Jet>
    /**
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByType(trigger::TriggerObjectType triggerObjectType, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByType(triggerObjectType, idx); }
    */

    // from pat::PATObject<reco::Jet>
    pat::TriggerObjectStandAlone*
    triggerObjectMatchByType(unsigned int triggerObjectType, size_t idx=0) const
    { return (pat::TriggerObjectStandAlone*)object->triggerObjectMatchByType(triggerObjectType, idx); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatches() const
    { return object->triggerObjectMatches(); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByAlgorithm(char* nameAlgorithm, bool algoCondAccepted=true) const
    { return object->triggerObjectMatchesByAlgorithm(nameAlgorithm, algoCondAccepted); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByAlgorithm(char* nameAlgorithm, unsigned int algoCondAccepted) const
    { return object->triggerObjectMatchesByAlgorithm(nameAlgorithm, algoCondAccepted); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByAlgorithm(std::string nameAlgorithm, bool algoCondAccepted=true) const
    { return object->triggerObjectMatchesByAlgorithm(nameAlgorithm, algoCondAccepted); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByAlgorithm(std::string nameAlgorithm, unsigned int algoCondAccepted) const
    { return object->triggerObjectMatchesByAlgorithm(nameAlgorithm, algoCondAccepted); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByCollection(char* coll) const
    { return object->triggerObjectMatchesByCollection(coll); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByCollection(std::string coll) const
    { return object->triggerObjectMatchesByCollection(coll); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByCondition(char* nameCondition) const
    { return object->triggerObjectMatchesByCondition(nameCondition); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByCondition(std::string nameCondition) const
    { return object->triggerObjectMatchesByCondition(nameCondition); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByFilter(char* labelFilter) const
    { return object->triggerObjectMatchesByFilter(labelFilter); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByFilter(std::string labelFilter) const
    { return object->triggerObjectMatchesByFilter(labelFilter); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByFilterID(unsigned int triggerObjectType) const
    { return object->triggerObjectMatchesByFilterID(triggerObjectType); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByPath(char* namePath, bool pathLastFilterAccepted=false, bool pathL3FilterAccepted=true) const
    { return object->triggerObjectMatchesByPath(namePath, pathLastFilterAccepted, pathL3FilterAccepted); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByPath(char* namePath, unsigned int pathLastFilterAccepted, unsigned int pathL3FilterAccepted=1) const
    { return object->triggerObjectMatchesByPath(namePath, pathLastFilterAccepted, pathL3FilterAccepted); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByPath(std::string namePath, bool pathLastFilterAccepted=false, bool pathL3FilterAccepted=true) const
    { return object->triggerObjectMatchesByPath(namePath, pathLastFilterAccepted, pathL3FilterAccepted); }

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByPath(std::string namePath, unsigned int pathLastFilterAccepted, unsigned int pathL3FilterAccepted=1) const
    { return object->triggerObjectMatchesByPath(namePath, pathLastFilterAccepted, pathL3FilterAccepted); }

    // from pat::PATObject<reco::Jet>
    /**
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByType(trigger::TriggerObjectType triggerObjectType) const
    { return object->triggerObjectMatchesByType(triggerObjectType); }
    */

    // from pat::PATObject<reco::Jet>
    const std::vector<pat::TriggerObjectStandAlone>
    triggerObjectMatchesByType(unsigned int triggerObjectType) const
    { return object->triggerObjectMatchesByType(triggerObjectType); }

    // from pat::PATObject<reco::Jet>
    edm::Ptr<reco::Candidate> userCand(std::string key) const
    { return object->userCand(key); }

    // from pat::PATObject<reco::Jet>
    const std::vector<std::string> userCandNames() const
    { return object->userCandNames(); }

    // from pat::PATObject<reco::Jet>
    const std::vector<std::string> userDataNames() const
    { return object->userDataNames(); }

    // from pat::PATObject<reco::Jet>
    const std::string userDataObjectType(std::string key) const
    { return object->userDataObjectType(key); }

    // from pat::PATObject<reco::Jet>
    float userFloat(char* key) const { return object->userFloat(key); }

    // from pat::PATObject<reco::Jet>
    float userFloat(std::string key) const { return object->userFloat(key); }

    // from pat::PATObject<reco::Jet>
    const std::vector<std::string> userFloatNames() const
    { return object->userFloatNames(); }

    // from pat::PATObject<reco::Jet>
    int userInt(std::string key) const { return object->userInt(key); }

    // from pat::PATObject<reco::Jet>
    const std::vector<std::string> userIntNames() const
    { return object->userIntNames(); }

    // from reco::LeafCandidate
    const math::XYZPoint vertex() const { return object->vertex(); }

    // from reco::LeafCandidate
    double vertexChi2() const { return object->vertexChi2(); }

    // from reco::LeafCandidate
    ROOT::Math::SMatrix<double,3,3,ROOT::Math::MatRepSym<double,3> >
    vertexCovariance() const
    { return object->vertexCovariance(); }

    // from reco::LeafCandidate
    double vertexCovariance(int i, int j) const
    { return object->vertexCovariance(i, j); }

    // from reco::LeafCandidate
    double vertexNdof() const { return object->vertexNdof(); }

    // from reco::LeafCandidate
    double vertexNormalizedChi2() const
    { return object->vertexNormalizedChi2(); }

    // from reco::LeafCandidate
    double vx() const { return object->vx(); }

    // from reco::LeafCandidate
    double vy() const { return object->vy(); }

    // from reco::LeafCandidate
    double vz() const { return object->vz(); }

    // from reco::LeafCandidate
    double y() const { return object->y(); }

    // from pat::Jet
    const float zspCorrection() const { return object->zspCorrection(); }
  };
}
#endif
