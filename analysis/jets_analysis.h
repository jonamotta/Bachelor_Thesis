//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May 29 10:06:37 2018 by ROOT version 6.08/06
// from TTree HTauTauTree/small tree for HH analysis
// found on file: VBFHHTo2b2T_27March2018.root
//////////////////////////////////////////////////////////

#ifndef jets_analysis_h
#define jets_analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class jets_analysis : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

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

   jets_analysis(TTree * /*tree*/ =0) { }
   virtual ~jets_analysis() { }
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

   // file dove salva
   TFile *file = new TFile("jets_analysis.root","RECREATE");
   // tree dove salva
   TNtuple *HJ_tree = new TNtuple("HJ_candidates","HJ_candidates","deltaM");
   TNtuple *Hjj_tree = new TNtuple("Hjj_candidates","Hjj_candidates","deltaM:deltaRjj:combinatory");

   // creiamo i vettori
   TLorentzVector v_jet1, v_jet2, v_H, v_tot, v_Jet;
   // vettori per il miglior candidato
   TLorentzVector v_jet1_best, v_jet2_best, v_tot_best;
   // vettori per il miglior match geometrico
   TLorentzVector v_jet1_best_R, v_jet2_best_R, v_tot_best_R;

   // variabile per la scelta del miglior match in Hjj
   double bestM_Hjj = 1000;
   // variabili per il miglior match geometrico della MC_Truth
   double bestR_Hjj = 50;
   double bestR_HJ = 50;

   // variabile per la decidere la soglia da usare in deltaR per il match geometrico
   // deve essere la stessa che si usa nella MC_Truth da cui si scelgono i tagli in massa
   double soglia_deltaR = 0.4;

   // variabile per decidere la soglia sopra la quale accettare un possibile candidato HJ
   double soglia_Jet_pT = 15;

   // creiamo dei counter per:
   //  - avere il numero di iterazioni e vedere se le fa tutte
   //  - avere il numero di candidati HJ
   //  - avere il numero di candidati Hjj
   //  - avere il numero di mancati candidati
   int j = 0, k = 0, l = 0, p = 0;
   //  - avere il numero di match geometrici HJ
   //  - avere il numero di match geometrici Hjj
   //  - avere il numero di mancati match geometrici
   int k_R = 0, l_R = 0, p_R = 0;
   // creiamo un orologio per vedere il tempo di run del programma
   TStopwatch watch;

   // variabili booleane per decidere se il candidato è stato trovato o no
   bool HJ_candidate = false;
   bool Hjj_candidate = false;
   // variabili booleane per decidere se il match geometrico è stato trovato o no
   bool HJ_match_R = false;
   bool Hjj_match_R = false;

   // definiamo la massa dell'Higgs
   double M_H = 125;

   // soglie di scelta dei candidati HJ
   // la scleta dei tagli per il match viene fatta secondo la MC_Truth guardando il grafico della distrib. di deltaM
   // inf_HJ scelto perchè non c'è nulla sotto a quello
   // sup_HJ scelto perchè toglie il piccolo picco a 50
   double inf_HJ = -30, sup_HJ = 20;

   // soglie di scelta dei candidati Hjj
   // la scleta dei tagli per il match viene fatta secondo la MC_Truth guardando il grafico della distrib. di deltaM
   // inf_Hjj scelto perchè ...
   // sup_Hjj scelto perchè ...
   double inf_Hjj = -30, sup_Hjj = 20;

   // soglia UNICA di selezione che viene usata sia per HJ che per Hjj
   // nel begin del .c viene usata per impostare la soglia unica
   // se si usa la soglia unica bisogna cambiare coerentemente gli estremi dei TH1F e TH2F
   double inf_unica = -110, sup_unica = 110;

   // creiamo le booleane che mi dicono chi è il match geometrico migliore tra i due
   bool HJ_is_best_R = false, Hjj_is_best_R = false;
   // creiamo i valori da inserire all'interno della matrice NON normalizzata
   double a = 0, b = 0, c = 0, d = 0;

   // ISTOGRAMMI
   TH1F *HJ_deltaM = new TH1F("HJ deltaM distribution","HJ deltaM distribution",100,inf_HJ,sup_HJ);
   TH1F *HJ_jetPT = new TH1F("HJ jet_pT distribution","HJ jet_pT distribution",100,0,1000);
   TH2F *HJ_deltaM_vs_jetPT = new TH2F("HJ deltaM vs. jetPT","HJ deltaM vs. jetPT",100,0,1000,100,inf_HJ,sup_HJ);
   TH1F *HJ_deltaM_garbage = new TH1F("HJ deltaM garbage","HJ deltaM garbage",100,inf_HJ,sup_HJ);
   TH1F *HJ_jetPT_garbage = new TH1F("HJ jet_pT garbage","HJ jet_pT garbage",100,0,1000);
   TH1F *HJ_deltaM_good = new TH1F("HJ deltaM good","HJ deltaM good",100,inf_HJ,sup_HJ);
   TH1F *HJ_jetPT_good = new TH1F("HJ jet_pT good","HJ jet_pT good",100,0,1000);
   TH1F *HJ_Hjj_truth_pT = new TH1F("HJ Hjj_truth_pT","HJ Hjj_truth_pT",100,0,1000);
   TH1F *HJ_Hjj_truth_deltaM = new TH1F("HJ Hjj_truth_deltaM","HJ Hjj_truth_deltaM",100,-80,30);
   TH1F *test = new TH1F("j_min/j_max from MC Truth","j_min/j_max from MC Truth",100,0,1);
   TH2F *test2 = new TH2F("j_min/j_max vs v_tot_pT from MC Truth","j_min/j_max vs v_tot_pT from MC Truth",100,0,1000,100,0,1);
   TH2F *test3 = new TH2F("M_{J} : M_{jj}","M_{J} : M_{jj}",100,20,200,100,80,180);
   TH1F *test4 = new TH1F("Hjj pT distribution","Hjj pT distribution",100,0,1260);

   TH1F *Hjj_deltaM = new TH1F("Hjj deltaM distribution","Hjj deltaM distribution",100,inf_Hjj,sup_Hjj);
   TH1F *deltaRjj = new TH1F("Hjj deltaR jet1-jet2","Hjj deltaR jet1-jet2",100,0,12);
   TH1F *combinatory = new TH1F("j_min/j_max","j_min/j_max",100,0,1);
   TH1F *combinatory_garbage = new TH1F("combinatroy garbage","combinatroy garbage",100,0,1);
   TH1F *H_expected_pT = new TH1F("Higgs expected pT","Higgs expected pT",100,0,1000);
   TH2F *Hjj_deltaM_vs_totPT = new TH2F("Hjj deltaM vs. jet_totPT","Hjj deltaM vs. jet_totPT",100,0,400,100,inf_Hjj,sup_Hjj);
   TH1F *Hjj_deltaM_garbage = new TH1F("Hjj deltaM garbage","Hjj deltaM garbage",100,inf_Hjj,sup_Hjj);
   TH1F *deltaRjj_garbage = new TH1F("Hjj deltaR jet1-jet2 garbage","Hjj deltaR jet1-jet2 garbage",100,0,12);
   TH1F *Hjj_pT_garbage = new TH1F("Hjj pT_tot garbage","Hjj pT_tot garbage",100,0,1260);
   TH1F *Hjj_deltaM_good = new TH1F("Hjj deltaM good","Hjj deltaM good",100,inf_Hjj,sup_Hjj);
   TH1F *deltaRjj_good = new TH1F("Hjj deltaR jet1-jet2 good","Hjj deltaR jet1-jet2 good",100,0,12);
   TH1F *Hjj_pT_good = new TH1F("Hjj pT_tot good","Hjj pT_tot good",100,0,1260);
   TH1F *Hjj_HJ_truth_pT = new TH1F("Hjj HJ_truth_pT","Hjj HJ_truth_pT",10000,0,1260);
   TH1F *Hjj_HJ_truth_deltaM = new TH1F("Hjj HJ_truth_deltaM","Hjj HJ_truth_deltaM",100,-40,110);

   // deltaR tra jet1 e jet2 per diferenti range di pT
   TH1F *deltaRjj_pT1 = new TH1F("pT 0-150","deltaRjj1",100,0,12.8);
   TH1F *deltaRjj_pT2 = new TH1F("pT 150-300","deltaRjj2",100,0,12.8);
   TH1F *deltaRjj_pT3 = new TH1F("pT 300-450","deltaRjj3",100,0,12.8);
   TH1F *deltaRjj_pT4 = new TH1F("pT 450-600","deltaRjj4",100,0,12.8);
   TH1F *deltaRjj_pT5 = new TH1F("pT 600-1260","deltaRjj5",100,0,12.8);
   TLegend *leg = new TLegend(0.90,0.77,0.70,0.97);

   TH1F *jet1_pT = new TH1F("Hjj p_{T}^{(j1)}","Hjj p_{T}^{(j1)}",1000,0,1260);
   TH1F *jet2_pT = new TH1F("Hjj p_{T}^{(j2)}","Hjj p_{T}^{(j2)}",1000,0,1260);
   TH1F *jet_tot_pT = new TH1F("Hjj p_{T}^{(jj)}","Hjj p_{T}^{(jj)}",1000,0,1260);

   // CANVAS
   TCanvas *c1 = new TCanvas("HJ deltaM vs. jetPT","HJ deltaM vs. jetPT",1400,700);
   TCanvas *c2 = new TCanvas("HJ distributions","HJ distributions",1400,700);
   TCanvas *c3 = new TCanvas("Hjj deltaM vs. jet_totPT","Hjj deltaM vs. jet_totPT",1400,700);
   TCanvas *c4 = new TCanvas("Hjj distributions","Hjj distributions",1400,700);
   TCanvas *c5 = new TCanvas("deltaR_jet1_jet2 at different pT range","deltaR_jet1_jet2 at different pT range",1400,700);
   TCanvas *c6 = new TCanvas("deltaR_jet1_jet2 at different pT","deltaR_jet1_jet2 at different pT",1400,700);
   TCanvas *c7 = new TCanvas("HJ garbage/good distributions","HJ garbage/good distributions",1400,700);
   TCanvas *c8 = new TCanvas("Hjj garbage/good distributions","Hjj garbage/good distributions",1400,700);
   TCanvas *c9 = new TCanvas("test","test",1400,700);
   TCanvas *c10 = new TCanvas("test3","test3",1400,700);
   TCanvas *c11 = new TCanvas("test4","test4",1400,700);
   TCanvas *c12 = new TCanvas("Hjj p_{T}^{(jj)}","Hjj p_{T}^{(jj)}",1400,700);

   ClassDef(jets_analysis,0);

};

#endif

#ifdef jets_analysis_cxx
void jets_analysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t jets_analysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef jets_analysis_cxx
