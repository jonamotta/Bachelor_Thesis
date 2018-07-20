//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Apr  5 18:38:21 2018 by ROOT version 6.08/06
// from TTree HTauTauTree/small tree for HH analysis
// found on file: VBFHHTo2b2T_27March2018.root
//////////////////////////////////////////////////////////

#ifndef jets_matching_toying_h
#define jets_matching_toying_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class jets_matching_toying : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Float_t> rho = {fReader, "rho"};

 //daughters1
   TTreeReaderValue<Float_t> dau1_pt = {fReader, "dau1_pt"};
   TTreeReaderValue<Float_t> dau1_pt_tauup = {fReader, "dau1_pt_tauup"};
   TTreeReaderValue<Float_t> dau1_pt_taudown = {fReader, "dau1_pt_taudown"};
   TTreeReaderValue<Float_t> dau1_eta = {fReader, "dau1_eta"};
   TTreeReaderValue<Float_t> dau1_phi = {fReader, "dau1_phi"};
   TTreeReaderValue<Float_t> dau1_e = {fReader, "dau1_e"};
   TTreeReaderValue<Float_t> dau1_flav = {fReader, "dau1_flav"};
   TTreeReaderValue<Float_t> dau1_dxy = {fReader, "dau1_dxy"};
   TTreeReaderValue<Float_t> dau1_dz = {fReader, "dau1_dz"};
 //genmatched
   TTreeReaderValue<Float_t> genmatched1_pt = {fReader, "genmatched1_pt"};
   TTreeReaderValue<Float_t> genmatched1_eta = {fReader, "genmatched1_eta"};
   TTreeReaderValue<Float_t> genmatched1_phi = {fReader, "genmatched1_phi"};
   TTreeReaderValue<Float_t> genmatched1_e = {fReader, "genmatched1_e"};
   TTreeReaderValue<Float_t> genmatched2_pt = {fReader, "genmatched2_pt"};
   TTreeReaderValue<Float_t> genmatched2_eta = {fReader, "genmatched2_eta"};
   TTreeReaderValue<Float_t> genmatched2_phi = {fReader, "genmatched2_phi"};
   TTreeReaderValue<Float_t> genmatched2_e = {fReader, "genmatched2_e"};
   TTreeReaderValue<Bool_t> hasgenmatch1 = {fReader, "hasgenmatch1"};
   TTreeReaderValue<Bool_t> hasgenmatch2 = {fReader, "hasgenmatch2"};
 //daughters2
   TTreeReaderValue<Float_t> dau2_pt = {fReader, "dau2_pt"};
   TTreeReaderValue<Float_t> dau2_pt_tauup = {fReader, "dau2_pt_tauup"};
   TTreeReaderValue<Float_t> dau2_pt_taudown = {fReader, "dau2_pt_taudown"};
   TTreeReaderValue<Float_t> dau2_eta = {fReader, "dau2_eta"};
   TTreeReaderValue<Float_t> dau2_phi = {fReader, "dau2_phi"};
   TTreeReaderValue<Float_t> dau2_e = {fReader, "dau2_e"};
   TTreeReaderValue<Float_t> dau2_flav = {fReader, "dau2_flav"};
   TTreeReaderValue<Float_t> dau2_dxy = {fReader, "dau2_dxy"};
   TTreeReaderValue<Float_t> dau2_dz = {fReader, "dau2_dz"};
 //bjet1
   TTreeReaderValue<Float_t> bjet1_pt = {fReader, "bjet1_pt"};
   TTreeReaderValue<Float_t> bjet1_eta = {fReader, "bjet1_eta"};
   TTreeReaderValue<Float_t> bjet1_phi = {fReader, "bjet1_phi"};
   TTreeReaderValue<Float_t> bjet1_e = {fReader, "bjet1_e"};
   //TTreeReaderValue<Float_t> bjet1_bID = {fReader, "bjet1_bID"};
   //TTreeReaderValue<Float_t> bjet1_bMVAID = {fReader, "bjet1_bMVAID"};
   TTreeReaderValue<Int_t> bjet1_flav = {fReader, "bjet1_flav"};
   TTreeReaderValue<Float_t> bjet1_pt_raw = {fReader, "bjet1_pt_raw"};
   TTreeReaderValue<Float_t> bjet1_pt_raw_jetup = {fReader, "bjet1_pt_raw_jetup"};
   TTreeReaderValue<Float_t> bjet1_pt_raw_jetdown = {fReader, "bjet1_pt_raw_jetdown"};
   TTreeReaderValue<Bool_t> bjet1_hasgenjet = {fReader, "bjet1_hasgenjet"};
 //bjet2
   TTreeReaderValue<Float_t> bjet2_pt = {fReader, "bjet2_pt"};
   TTreeReaderValue<Float_t> bjet2_eta = {fReader, "bjet2_eta"};
   TTreeReaderValue<Float_t> bjet2_phi = {fReader, "bjet2_phi"};
   TTreeReaderValue<Float_t> bjet2_e = {fReader, "bjet2_e"};
   //TTreeReaderValue<Float_t> bjet2m_bID = {fReader, "bjet2_bID"};
   //TTreeReaderValue<Float_t> bjet2m_bMVAID = {fReader, "bjet2_bMVAID"};
   TTreeReaderValue<Int_t> bjet2_flav = {fReader, "bjet2_flav"};
   TTreeReaderValue<Float_t> bjet2_pt_raw = {fReader, "bjet2_pt_raw"};
   TTreeReaderValue<Float_t> bjet2_pt_raw_jetup = {fReader, "bjet2_pt_raw_jetup"};
   TTreeReaderValue<Float_t> bjet2_pt_raw_jetdown = {fReader, "bjet2_pt_raw_jetdown"};
   TTreeReaderValue<Bool_t> bjet2_hasgenjet = {fReader, "bjet2_hasgenjet"};
 //genb1 e genb2
   TTreeReaderValue<Float_t> genb1_pt = {fReader, "genb1_pt"};
   TTreeReaderValue<Float_t> genb1_eta = {fReader, "genb1_eta"};
   TTreeReaderValue<Float_t> genb1_phi = {fReader, "genb1_phi"};
   TTreeReaderValue<Float_t> genb1_e = {fReader, "genb1_e"};
   TTreeReaderValue<Float_t> genb2_pt = {fReader, "genb2_pt"};
   TTreeReaderValue<Float_t> genb2_eta = {fReader, "genb2_eta"};
   TTreeReaderValue<Float_t> genb2_phi = {fReader, "genb2_phi"};
   TTreeReaderValue<Float_t> genb2_e = {fReader, "genb2_e"};
 //fatjets
   TTreeReaderValue<Int_t> nfatjets = {fReader, "nfatjets"};
   TTreeReaderValue<Float_t> fatjet_pt = {fReader, "fatjet_pt"};
   TTreeReaderValue<Float_t> fatjet_eta = {fReader, "fatjet_eta"};
   TTreeReaderValue<Float_t> fatjet_phi = {fReader, "fatjet_phi"};
   TTreeReaderValue<Float_t> fatjet_e = {fReader, "fatjet_e"};
   TTreeReaderValue<Float_t> fatjet_filteredMass = {fReader, "fatjet_filteredMass"};
   TTreeReaderValue<Float_t> fatjet_prunedMass = {fReader, "fatjet_prunedMass"};
   TTreeReaderValue<Float_t> fatjet_trimmedMass = {fReader, "fatjet_trimmedMass"};
   TTreeReaderValue<Float_t> fatjet_softdropMass = {fReader, "fatjet_softdropMass"};
   TTreeReaderValue<Float_t> fatjet_tau1 = {fReader, "fatjet_tau1"};
   TTreeReaderValue<Float_t> fatjet_tau2 = {fReader, "fatjet_tau2"};
   TTreeReaderValue<Float_t> fatjet_tau3 = {fReader, "fatjet_tau3"};
   TTreeReaderValue<Int_t> fatjet_nsubjets = {fReader, "fatjet_nsubjets"};
 //subjets
   TTreeReaderValue<Float_t> dR_subj1_subj2 = {fReader, "dR_subj1_subj2"};
   TTreeReaderValue<Float_t> subjetjet1_pt = {fReader, "subjetjet1_pt"};
   TTreeReaderValue<Float_t> subjetjet1_eta = {fReader, "subjetjet1_eta"};
   TTreeReaderValue<Float_t> subjetjet1_phi = {fReader, "subjetjet1_phi"};
   TTreeReaderValue<Float_t> subjetjet1_e = {fReader, "subjetjet1_e"};
   //TTreeReaderValue<Float_t> subjetjet1_bID = {fReader, "subjetjet1_bID"};
   TTreeReaderValue<Float_t> subjetjet2_pt = {fReader, "subjetjet2_pt"};
   TTreeReaderValue<Float_t> subjetjet2_eta = {fReader, "subjetjet2_eta"};
   TTreeReaderValue<Float_t> subjetjet2_phi = {fReader, "subjetjet2_phi"};
   TTreeReaderValue<Float_t> subjetjet2_e = {fReader, "subjetjet2_e"};
   //TTreeReaderValue<Float_t> subjetjet2_bID = {fReader, "subjetjet2_bID"};
 //genjet1
   TTreeReaderValue<Float_t> genjet1_pt = {fReader, "genjet1_pt"};
   TTreeReaderValue<Float_t> genjet1_eta = {fReader, "genjet1_eta"};
   TTreeReaderValue<Float_t> genjet1_phi = {fReader, "genjet1_phi"};
   TTreeReaderValue<Float_t> genjet1_e = {fReader, "genjet1_e"};
   TTreeReaderValue<Int_t> genjet1_flav = {fReader, "genjet1_flav"};
 //genjet2
   TTreeReaderValue<Float_t> genjet2_pt = {fReader, "genjet2_pt"};
   TTreeReaderValue<Float_t> genjet2_eta = {fReader, "genjet2_eta"};
   TTreeReaderValue<Float_t> genjet2_phi = {fReader, "genjet2_phi"};
   TTreeReaderValue<Float_t> genjet2_e = {fReader, "genjet2_e"};
   TTreeReaderValue<Int_t> genjet2_flav = {fReader, "genjet2_flav"};
 //tauH
   TTreeReaderValue<Float_t> tauH_pt = {fReader, "tauH_pt"};
   TTreeReaderValue<Float_t> tauH_eta = {fReader, "tauH_eta"};
   TTreeReaderValue<Float_t> tauH_phi = {fReader, "tauH_phi"};
   TTreeReaderValue<Float_t> tauH_e = {fReader, "tauH_e"};
   TTreeReaderValue<Float_t> tauH_mass = {fReader, "tauH_mass"};
   TTreeReaderValue<Float_t> tauH_SVFIT_mass = {fReader, "tauH_SVFIT_mass"};
   TTreeReaderValue<Float_t> tauH_SVFIT_pt = {fReader, "tauH_SVFIT_pt"};
   TTreeReaderValue<Float_t> tauH_SVFIT_eta = {fReader, "tauH_SVFIT_eta"};
   TTreeReaderValue<Float_t> tauH_SVFIT_phi = {fReader, "tauH_SVFIT_phi"};
   TTreeReaderValue<Float_t> tauH_SVFIT_METphi = {fReader, "tauH_SVFIT_METphi"};
   TTreeReaderValue<Float_t> tauH_SVFIT_METrho = {fReader, "tauH_SVFIT_METrho"};
   TTreeReaderValue<Float_t> tauH_SVFIT_mass_up = {fReader, "tauH_SVFIT_mass_up"};
   TTreeReaderValue<Float_t> tauH_SVFIT_mass_down = {fReader, "tauH_SVFIT_mass_down"};
 //bH
   TTreeReaderValue<Float_t> bH_pt = {fReader, "bH_pt"};
   TTreeReaderValue<Float_t> bH_eta = {fReader, "bH_eta"};
   TTreeReaderValue<Float_t> bH_phi = {fReader, "bH_phi"};
   TTreeReaderValue<Float_t> bH_e = {fReader, "bH_e"};
   TTreeReaderValue<Float_t> bH_mass = {fReader, "bH_mass"};
 //HH
   TTreeReaderValue<Float_t> HHsvfit_pt = {fReader, "HHsvfit_pt"};
   TTreeReaderValue<Float_t> HHsvfit_eta = {fReader, "HHsvfit_eta"};
   TTreeReaderValue<Float_t> HHsvfit_phi = {fReader, "HHsvfit_phi"};
   TTreeReaderValue<Float_t> HHsvfit_e = {fReader, "HHsvfit_e"};
   TTreeReaderValue<Float_t> HHsvfit_mass = {fReader, "HHsvfit_mass"};
   TTreeReaderValue<Float_t> HH_pt = {fReader, "HH_pt"};
   TTreeReaderValue<Float_t> HH_eta = {fReader, "HH_eta"};
   TTreeReaderValue<Float_t> HH_phi = {fReader, "HH_phi"};
   TTreeReaderValue<Float_t> HH_e = {fReader, "HH_e"};
   TTreeReaderValue<Float_t> HH_mass = {fReader, "HH_mass"};
   TTreeReaderValue<Float_t> HH_mass_raw = {fReader, "HH_mass_raw"};
   TTreeReaderValue<Float_t> HH_mass_raw_tauup = {fReader, "HH_mass_raw_tauup"};
   TTreeReaderValue<Float_t> HH_mass_raw_taudown = {fReader, "HH_mass_raw_taudown"};
   TTreeReaderValue<Float_t> HHKin_mass = {fReader, "HHKin_mass"};
   TTreeReaderValue<Float_t> HHKin_chi2 = {fReader, "HHKin_chi2"};
   TTreeReaderValue<Float_t> HH_deltaPhi = {fReader, "HH_deltaPhi"};
   TTreeReaderValue<Float_t> HH_deltaR = {fReader, "HH_deltaR"};
   TTreeReaderValue<Float_t> HH_deltaEta = {fReader, "HH_deltaEta"};
   TTreeReaderValue<Float_t> HHsvfit_deltaPhi = {fReader, "HHsvfit_deltaPhi"};
   TTreeReaderValue<Float_t> tauHMet_deltaPhi = {fReader, "tauHMet_deltaPhi"};
   TTreeReaderValue<Float_t> tauHsvfitMet_deltaPhi = {fReader, "tauHsvfitMet_deltaPhi"};
 //coppie varie
   TTreeReaderValue<Float_t> bHMet_deltaPhi = {fReader, "bHMet_deltaPhi"};
   TTreeReaderValue<Float_t> ditau_deltaPhi = {fReader, "ditau_deltaPhi"};
   TTreeReaderValue<Float_t> ditau_deltaEta = {fReader, "ditau_deltaEta"};
   TTreeReaderValue<Float_t> dib_deltaPhi = {fReader, "dib_deltaPhi"};
   TTreeReaderValue<Float_t> dib_deltaEta = {fReader, "dib_deltaEta"};
   TTreeReaderValue<Float_t> ditau_deltaR = {fReader, "ditau_deltaR"};
   TTreeReaderValue<Float_t> dib_deltaR = {fReader, "dib_deltaR"};
   TTreeReaderValue<Float_t> ditau_deltaR_per_tauHsvfitpt = {fReader, "ditau_deltaR_per_tauHsvfitpt"};
   TTreeReaderValue<Float_t> dib_deltaR_per_bHpt = {fReader, "dib_deltaR_per_bHpt"};
   TTreeReaderValue<Float_t> btau_deltaRmin = {fReader, "btau_deltaRmin"};
   TTreeReaderValue<Float_t> btau_deltaRmax = {fReader, "btau_deltaRmax"};
   TTreeReaderValue<Float_t> dau1MET_deltaphi = {fReader, "dau1MET_deltaphi"};
   TTreeReaderValue<Float_t> dau2MET_deltaphi = {fReader, "dau2MET_deltaphi"};
 //jets
   TTreeReaderValue<Float_t> jet20centrality = {fReader, "jet20centrality"};
   TTreeReaderArray<float> jets_pt = {fReader, "jets_pt"};
   TTreeReaderArray<float> jets_eta = {fReader, "jets_eta"};
   TTreeReaderArray<float> jets_phi = {fReader, "jets_phi"};
   TTreeReaderArray<float> jets_e = {fReader, "jets_e"};
   TTreeReaderArray<float> jets_btag = {fReader, "jets_btag"};
   TTreeReaderArray<int> jets_flav = {fReader, "jets_flav"};
   TTreeReaderArray<int> jets_isH = {fReader, "jets_isH"};
   TTreeReaderValue<vector<bool>> jets_hasgenjet = {fReader, "jets_hasgenjet"};
   TTreeReaderValue<Int_t> njets = {fReader, "njets"};
   TTreeReaderValue<Int_t> addjets = {fReader, "addjets"};
   TTreeReaderValue<Int_t> njets20 = {fReader, "njets20"};
   TTreeReaderValue<Int_t> njets50 = {fReader, "njets50"};
   TTreeReaderValue<Int_t> nbjetscand = {fReader, "nbjetscand"};
   TTreeReaderValue<Int_t> njetsBHadFlav = {fReader, "njetsBHadFlav"};
   TTreeReaderValue<Int_t> njetsCHadFlav = {fReader, "njetsCHadFlav"};
   TTreeReaderArray<float> jets_jecUnc = {fReader, "jets_jecUnc"};
 //cose di daughters e bjet
   TTreeReaderValue<Float_t> dau1_jecUnc = {fReader, "dau1_jecUnc"};
   TTreeReaderValue<Float_t> dau2_jecUnc = {fReader, "dau2_jecUnc"};
   TTreeReaderValue<Float_t> bjet1_jecUnc = {fReader, "bjet1_jecUnc"};
   TTreeReaderValue<Float_t> bjet2_jecUnc = {fReader, "bjet2_jecUnc"};
 //genjets
   TTreeReaderArray<float> genjets_pt = {fReader, "genjets_pt"};
   TTreeReaderArray<float> genjets_eta = {fReader, "genjets_eta"};
   TTreeReaderArray<float> genjets_phi = {fReader, "genjets_phi"};
   TTreeReaderArray<float> genjets_e = {fReader, "genjets_e"};
   TTreeReaderArray<int> genjets_flav = {fReader, "genjets_flav"};
 //leptons
   TTreeReaderArray<float> leps_pt = {fReader, "leps_pt"};
   TTreeReaderArray<float> leps_eta = {fReader, "leps_eta"};
   TTreeReaderArray<float> leps_phi = {fReader, "leps_phi"};
   TTreeReaderArray<float> leps_e = {fReader, "leps_e"};
   TTreeReaderArray<int> leps_flav = {fReader, "leps_flav"};
   TTreeReaderValue<Int_t> nleps = {fReader, "nleps"};
 //ancora HH
   TTreeReaderValue<Float_t> HHkinsvfit_bHmass = {fReader, "HHkinsvfit_bHmass"};
   TTreeReaderValue<Float_t> HHkinsvfit_pt = {fReader, "HHkinsvfit_pt"};
   TTreeReaderValue<Float_t> HHkinsvfit_eta = {fReader, "HHkinsvfit_eta"};
   TTreeReaderValue<Float_t> HHkinsvfit_phi = {fReader, "HHkinsvfit_phi"};
   TTreeReaderValue<Float_t> HHkinsvfit_e = {fReader, "HHkinsvfit_e"};
   TTreeReaderValue<Float_t> HHkinsvfit_m = {fReader, "HHkinsvfit_m"};
   TTreeReaderValue<Float_t> MT2 = {fReader, "MT2"};
   TTreeReaderValue<Float_t> MT2_tauup = {fReader, "MT2_tauup"};
   TTreeReaderValue<Float_t> MT2_taudown = {fReader, "MT2_taudown"};
   TTreeReaderValue<Float_t> MT2_jetup = {fReader, "MT2_jetup"};
   TTreeReaderValue<Float_t> MT2_jetdown = {fReader, "MT2_jetdown"};
 //ancora roba di bH
   TTreeReaderValue<Float_t> bH_mass_raw = {fReader, "bH_mass_raw"};
   TTreeReaderValue<Float_t> bH_mass_raw_jetup = {fReader, "bH_mass_raw_jetup"};
   TTreeReaderValue<Float_t> bH_mass_raw_jetdown = {fReader, "bH_mass_raw_jetdown"};
 //ancora roba di HH
   TTreeReaderValue<Float_t> HHKin_mass_raw = {fReader, "HHKin_mass_raw"};
   TTreeReaderValue<Float_t> HHKin_mass_raw_tauup = {fReader, "HHKin_mass_raw_tauup"};
   TTreeReaderValue<Float_t> HHKin_mass_raw_taudown = {fReader, "HHKin_mass_raw_taudown"};
   TTreeReaderValue<Float_t> HHKin_mass_raw_jetup = {fReader, "HHKin_mass_raw_jetup"};
   TTreeReaderValue<Float_t> HHKin_mass_raw_jetdown = {fReader, "HHKin_mass_raw_jetdown"};
   TTreeReaderValue<Float_t> HHKin_mass_raw_chi2 = {fReader, "HHKin_mass_raw_chi2"};
   TTreeReaderValue<Int_t> HHKin_mass_raw_convergence = {fReader, "HHKin_mass_raw_convergence"};
   TTreeReaderValue<Float_t> HHKin_mass_raw_prob = {fReader, "HHKin_mass_raw_prob"};
   TTreeReaderValue<Float_t> HHKin_mass_raw_copy = {fReader, "HHKin_mass_raw_copy"};
   TTreeReaderValue<Float_t> lheht = {fReader, "lheht"};
   TTreeReaderValue<Float_t> topReweight = {fReader, "topReweight"};
 //VBFjets e VBFgenjets
   TTreeReaderValue<Float_t> VBFjet1_pt = {fReader, "VBFjet1_pt"};
   TTreeReaderValue<Float_t> VBFjet1_eta = {fReader, "VBFjet1_eta"};
   TTreeReaderValue<Float_t> VBFjet1_phi = {fReader, "VBFjet1_phi"};
   TTreeReaderValue<Float_t> VBFjet1_e = {fReader, "VBFjet1_e"};
   TTreeReaderValue<Float_t> VBFjet1_btag = {fReader, "VBFjet1_btag"};
   TTreeReaderValue<Int_t> VBFjet1_flav = {fReader, "VBFjet1_flav"};
   TTreeReaderValue<Bool_t> VBFjet1_hasgenjet = {fReader, "VBFjet1_hasgenjet"};
   TTreeReaderValue<Float_t> VBFgenjet1_pt = {fReader, "VBFgenjet1_pt"};
   TTreeReaderValue<Float_t> VBFgenjet1_eta = {fReader, "VBFgenjet1_eta"};
   TTreeReaderValue<Float_t> VBFgenjet1_phi = {fReader, "VBFgenjet1_phi"};
   TTreeReaderValue<Float_t> VBFgenjet1_e = {fReader, "VBFgenjet1_e"};
   TTreeReaderValue<Float_t> VBFjet2_pt = {fReader, "VBFjet2_pt"};
   TTreeReaderValue<Float_t> VBFjet2_eta = {fReader, "VBFjet2_eta"};
   TTreeReaderValue<Float_t> VBFjet2_phi = {fReader, "VBFjet2_phi"};
   TTreeReaderValue<Float_t> VBFjet2_e = {fReader, "VBFjet2_e"};
   TTreeReaderValue<Float_t> VBFjet2_btag = {fReader, "VBFjet2_btag"};
   TTreeReaderValue<Int_t> VBFjet2_flav = {fReader, "VBFjet2_flav"};
   TTreeReaderValue<Bool_t> VBFjet2_hasgenjet = {fReader, "VBFjet2_hasgenjet"};
   TTreeReaderValue<Float_t> VBFgenjet2_pt = {fReader, "VBFgenjet2_pt"};
   TTreeReaderValue<Float_t> VBFgenjet2_eta = {fReader, "VBFgenjet2_eta"};
   TTreeReaderValue<Float_t> VBFgenjet2_phi = {fReader, "VBFgenjet2_phi"};
   TTreeReaderValue<Float_t> VBFgenjet2_e = {fReader, "VBFgenjet2_e"};
   TTreeReaderValue<Float_t> VBFjj_mass_log = {fReader, "VBFjj_mass_log"};
   TTreeReaderValue<Float_t> jj_mass_log = {fReader, "jj_mass_log"};
   TTreeReaderValue<Float_t> VBFjj_mass = {fReader, "VBFjj_mass"};
   TTreeReaderValue<Float_t> VBFjj_deltaEta = {fReader, "VBFjj_deltaEta"};
   TTreeReaderValue<Float_t> VBFjj_HT = {fReader, "VBFjj_HT"};
 //jets e genjets vari
   TTreeReaderValue<Float_t> jet3_pt = {fReader, "jet3_pt"};
   TTreeReaderValue<Float_t> jet3_eta = {fReader, "jet3_eta"};
   TTreeReaderValue<Float_t> jet3_phi = {fReader, "jet3_phi"};
   TTreeReaderValue<Float_t> jet3_e = {fReader, "jet3_e"};
   TTreeReaderValue<Float_t> jet3_btag = {fReader, "jet3_btag"};
   TTreeReaderValue<Int_t> jet3_flav = {fReader, "jet3_flav"};
   TTreeReaderValue<Bool_t> jet3_hasgenjet = {fReader, "jet3_hasgenjet"};
   TTreeReaderValue<Float_t> genjet3_pt = {fReader, "genjet3_pt"};
   TTreeReaderValue<Float_t> genjet3_eta = {fReader, "genjet3_eta"};
   TTreeReaderValue<Float_t> genjet3_phi = {fReader, "genjet3_phi"};
   TTreeReaderValue<Float_t> genjet3_e = {fReader, "genjet3_e"};
   TTreeReaderValue<Float_t> jet4_pt = {fReader, "jet4_pt"};
   TTreeReaderValue<Float_t> jet4_eta = {fReader, "jet4_eta"};
   TTreeReaderValue<Float_t> jet4_phi = {fReader, "jet4_phi"};
   TTreeReaderValue<Float_t> jet4_e = {fReader, "jet4_e"};
   TTreeReaderValue<Float_t> jet4_btag = {fReader, "jet4_btag"};
   TTreeReaderValue<Int_t> jet4_flav = {fReader, "jet4_flav"};
   TTreeReaderValue<Bool_t> jet4_hasgenjet = {fReader, "jet4_hasgenjet"};
   TTreeReaderValue<Float_t> genjet4_pt = {fReader, "genjet4_pt"};
   TTreeReaderValue<Float_t> genjet4_eta = {fReader, "genjet4_eta"};
   TTreeReaderValue<Float_t> genjet4_phi = {fReader, "genjet4_phi"};
   TTreeReaderValue<Float_t> genjet4_e = {fReader, "genjet4_e"};
   TTreeReaderValue<Float_t> jj_mass = {fReader, "jj_mass"};
   TTreeReaderValue<Float_t> jj_deltaEta = {fReader, "jj_deltaEta"};
   TTreeReaderValue<Float_t> jj_HT = {fReader, "jj_HT"};
   TTreeReaderValue<Float_t> jet5_pt = {fReader, "jet5_pt"};
   TTreeReaderValue<Float_t> jet5_eta = {fReader, "jet5_eta"};
   TTreeReaderValue<Float_t> jet5_phi = {fReader, "jet5_phi"};
   TTreeReaderValue<Float_t> jet5_e = {fReader, "jet5_e"};
   TTreeReaderValue<Float_t> jet5_btag = {fReader, "jet5_btag"};
   TTreeReaderValue<Int_t> jet5_flav = {fReader, "jet5_flav"};
   TTreeReaderValue<Bool_t> jet5_hasgenjet = {fReader, "jet5_hasgenjet"};
   TTreeReaderValue<Float_t> jet5_z = {fReader, "jet5_z"};
   TTreeReaderValue<Float_t> jet5_VBF_pt = {fReader, "jet5_VBF_pt"};
   TTreeReaderValue<Float_t> jet5_VBF_eta = {fReader, "jet5_VBF_eta"};
   TTreeReaderValue<Float_t> jet5_VBF_phi = {fReader, "jet5_VBF_phi"};
   TTreeReaderValue<Float_t> jet5_VBF_e = {fReader, "jet5_VBF_e"};
   TTreeReaderValue<Float_t> jet5_VBF_btag = {fReader, "jet5_VBF_btag"};
   TTreeReaderValue<Float_t> jet5_VBF_flav = {fReader, "jet5_VBF_flav"};
   TTreeReaderValue<Bool_t> jet5_VBF_hasgenjet = {fReader, "jet5_VBF_hasgenjet"};
   TTreeReaderValue<Float_t> jet5_VBF_z = {fReader, "jet5_VBF_z"};
   TTreeReaderValue<Float_t> genjet5_VBF_pt = {fReader, "genjet5_VBF_pt"};
   TTreeReaderValue<Float_t> genjet5_VBF_eta = {fReader, "genjet5_VBF_eta"};
   TTreeReaderValue<Float_t> genjet5_VBF_phi = {fReader, "genjet5_VBF_phi"};
   TTreeReaderValue<Float_t> genjet5_VBF_e = {fReader, "genjet5_VBF_e"};
 //LHE
   TTreeReaderValue<Float_t> LHE_H1_pt = {fReader, "LHE_H1_pt"};
   TTreeReaderValue<Float_t> LHE_H1_eta = {fReader, "LHE_H1_eta"};
   TTreeReaderValue<Float_t> LHE_H1_phi = {fReader, "LHE_H1_phi"};
   TTreeReaderValue<Float_t> LHE_H1_e = {fReader, "LHE_H1_e"};
   TTreeReaderValue<Float_t> LHE_H2_pt = {fReader, "LHE_H2_pt"};
   TTreeReaderValue<Float_t> LHE_H2_eta = {fReader, "LHE_H2_eta"};
   TTreeReaderValue<Float_t> LHE_H2_phi = {fReader, "LHE_H2_phi"};
   TTreeReaderValue<Float_t> LHE_H2_e = {fReader, "LHE_H2_e"};
   TTreeReaderValue<Float_t> LHE_HH_mass = {fReader, "LHE_HH_mass"};
   TTreeReaderValue<Float_t> LHE_VBF1_pt = {fReader, "LHE_VBF1_pt"};
   TTreeReaderValue<Float_t> LHE_VBF1_eta = {fReader, "LHE_VBF1_eta"};
   TTreeReaderValue<Float_t> LHE_VBF1_phi = {fReader, "LHE_VBF1_phi"};
   TTreeReaderValue<Float_t> LHE_VBF1_e = {fReader, "LHE_VBF1_e"};
   TTreeReaderValue<Float_t> LHE_VBF2_pt = {fReader, "LHE_VBF2_pt"};
   TTreeReaderValue<Float_t> LHE_VBF2_eta = {fReader, "LHE_VBF2_eta"};
   TTreeReaderValue<Float_t> LHE_VBF2_phi = {fReader, "LHE_VBF2_phi"};
   TTreeReaderValue<Float_t> LHE_VBF2_e = {fReader, "LHE_VBF2_e"};
   TTreeReaderValue<Float_t> LHE_VBFjj_mass = {fReader, "LHE_VBFjj_mass"};

   jets_matching_toying(TTree * /*tree*/ =0) { }
   virtual ~jets_matching_toying() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   // file to save the analyzed events
   TFile *file = new TFile("jets_matching_toying.root","RECREATE");
   // trees to save the analyzed events
   TNtuple *Hj_tree = new TNtuple("Rmatch_HJ_tree","Rmatch_HJ_tree","deltaR:deltaM");
   TNtuple *Hjj_tree = new TNtuple("Rmatch_Hjj_tree","Rmatch_Hjj_tree","deltaR:deltaM");

   // histograms for geometric match of Hjj category
   TH2F *deltaR_vs_deltaM_Hjj = new TH2F("deltaR : deltaM Hjj","deltaR : deltaM Hjj",2501,-2500,2500,100,0,0.4);
   TH2F *deltaR_vs_pT_Hjj = new TH2F("#DeltaR(H,jj) : p_{T}^{(H)} Hjj","#DeltaR(H,jj) : p_{T}^{(H)} Hjj",100,0,1260,100,0,0.4);
   TH2F *deltaM_vs_pT_Hjj = new TH2F("deltaM : pT Hjj","deltaM : pT Hjj",100,0,1260,100,-2500,2500);
   TH2F *deltaRjj_vs_pT_Hjj = new TH2F("#DeltaR(j,j) : p_{T}^{(H)}","#DeltaR(j,j) : p_{T}^{(H)}",100,0,800,100,0,8);
   TH1F *distribHjj_deltaR = new TH1F("deltaR distribution double jet","deltaR distribution double jet",100,0,0.4);
   TH1F *distribHjj_deltaM = new TH1F("#DeltaM - Hjj category","#DeltaM - Hjj category",1001,-1000,1000);
   TH1F *deltaR_jet1_jet2 = new TH1F("#DeltaR(j,j)","",100,0,12.8);
   // deltaR between jet1 and jet2 for different pT ranges
   TH1F *deltaRjj_pT1 = new TH1F("deltaRjj1","",200,0,12.8);
   TH1F *deltaRjj_pT2 = new TH1F("pT 150-300","#DeltaR(j,j)",200,0,12.8);
   TH1F *deltaRjj_pT3 = new TH1F("deltaRjj3","pT 300-450",200,0,12.8);
   TH1F *deltaRjj_pT4 = new TH1F("deltaRjj4","pT 450-600",200,0,12.8);
   TH1F *deltaRjj_pT5 = new TH1F("deltaRjj5","pT 600-1260",200,0,12.8);
   TLegend *leg = new TLegend(0.90,0.57,0.55,0.92);
   // control of the magnitude of jet1 w.r.t jet2
   TH1F *rhojj_control_pT = new TH1F("combinatory control j_max/j_min in pT","combinatory control j_max/j_min in pT",1000,0,80);
   TH1F *rhojj_control_M = new TH1F("WRONG EXTREMES combinatory control j_max/j_min in M","WRONG EXTREMES combinatory control j_max/j_min in M",1000,0,200);
   TH1F *rhojj_control_pT1 = new TH1F("combinatory control j_min/j_max in pT","combinatory control j_min/j_max in pT",100,0,1);
   TH1F *rhojj_control_M1 = new  TH1F("WRONG EXTREMES combinatory control j_min/j_max in M","WRONG EXTREMES combinatory control j_min/j_max in M",10000,0,200);

   // histograms to control the correspondence between the quark and the reconstructed jets
   TH1F *control_j1 = new TH1F("geometric control jet1","geometric control jet1",500,0,12.8);
   TH1F *control_j2 = new TH1F("geometric control jet2","geometric control jet2",500,0,12.8);

   // histograms for geometric match of HJ category
   TH2F *deltaR_vs_deltaM_Hj = new TH2F("deltaR : deltaM HJ","deltaR : deltaM HJ",100,-2500,2500,100,0,0.4);
   TH2F *deltaR_vs_pT_Hj = new TH2F("#DeltaR(J,H) : p_{T}^{(H)}","",100,0,1260,100,0,0.2);
   TH2F *deltaM_vs_pT_Hj = new TH2F("#DeltaM : p_{T}^{(H)} - HJ category","#DeltaM : p_{T}^{(H)} - HJ category",100,0,1260,100,50,50);
   TH1F *distribHj_deltaR = new TH1F("deltaR distribution single jet","deltaR distribution single jet",100,0,0.4);
   TH1F *distribHj_deltaM = new TH1F("#DeltaM - HJ category","#DeltaM - HJ category",100,-50,50);

   // vectors we use for the analysis
   TLorentzVector v_jet1, v_jet2, v_H, v_tot, v_quark1, v_quark2, v_quark_tot, v_fatjet;
   // vectors containing the best match between HJ and Hjj category
   TLorentzVector v_jet1_best, v_jet2_best, v_tot_best;
   TLorentzVector v_jet1_HJbest;
   double bestR_HJ = 50;
   double bestR_Hjj = 50;

   // variables fo the thresholds
   double soglia_deltaR = 0.4;
   double soglia_genb1_pT = -10000;

   // counters to control the number of iterations
   int j = 0, k = 0;
   // watch to control the run time of the program
   TStopwatch watch;

   int NOMATCH = 0;

   int HJ_is_best_R = 0, Hjj_is_best_R = 0;
   int HJ_is_best_M = 0, Hjj_is_best_M = 0;

   // canvas for the histograms
   TCanvas *c1 = new TCanvas("deltaR : deltaM Hjj","deltaR : deltaM Hjj",1400,700);
   TCanvas *c2 = new TCanvas("#DeltaR : p_{T}^{(H)} Hjj","#DeltaR : p_{T}^{(H)} Hjj",1400,700);
   TCanvas *c3 = new TCanvas("deltaR : deltaM Hj","deltaR : deltaM Hj",1400,700);
   TCanvas *c4 = new TCanvas("deltaR : pT Hj","deltaR : pT Hj",1400,700);
   TCanvas *c5 = new TCanvas("HJ deltaM/R distributions","HJ deltaM/R distributions",1400,700);
   TCanvas *c6 = new TCanvas("Hjj deltaM/R distributions","Hjj deltaM/R distributions",1400,700);
   TCanvas *c7 = new TCanvas("deltaM : pT Hjj","deltaM : pT Hjj",1400,700);
   TCanvas *c8 = new TCanvas("deltaM : pT Hj","deltaM : pT Hj",1400,700);
   TCanvas *c9 = new TCanvas("deltaR jet1-jet2 : pT Hjj","deltaR jet1-jet2 : pT Hjj",900,700);
   TCanvas *c10 = new TCanvas("deltaM : pT profiles Hjj","deltaM : pT profiles Hjj",1500,900);
   TCanvas *c11 = new TCanvas("deltaR jet1-jet2 different pT","deltaR jet1-jet2 different pT",1400,700);
   TCanvas *c12 = new TCanvas("jet-quark control","jet-quark control",1400,700);
   TCanvas *c13 = new TCanvas("combinatory control","combinatory control",1400,700);
   TCanvas *c15 = new TCanvas("deltaR jet1-jet2 superposed","deltaR jet1-jet2 superposed",1400,700);
   TCanvas *c16 = new TCanvas("deltaM distributions HJ & Hjj","deltaM distributions HJ & Hjj",1400,700);
   TCanvas *c17 = new TCanvas("projection deltaR_HJ : pT H","projection deltaR_HJ : pT H",1400,700);
   TCanvas *c18 = new TCanvas("deltaM HJ","deltaM HJ",800,800);
   TCanvas *c19 = new TCanvas("deltaM Hjj","deltaM Hjj",800,800);



   ClassDef(jets_matching_toying,0);

};

#endif

#ifdef jets_matching_toying_cxx
void jets_matching_toying::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t jets_matching_toying::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef jets_matching_toying_cxx
