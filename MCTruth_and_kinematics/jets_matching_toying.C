#define jets_matching_toying_cxx
// The class definition in jets_matching_toying.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("jets_matching_toying.C")
// root> T->Process("jets_matching_toying.C","some options")
// root> T->Process("jets_matching_toying.C+")
//


#include "jets_matching_toying.h"
#include <TH2.h>
#include <TStyle.h>

void jets_matching_toying::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   watch.Start();

   // axes names
   deltaR_vs_deltaM_Hjj->SetXTitle("#DeltaM");
   deltaR_vs_deltaM_Hjj->SetYTitle("#DeltaR");
   deltaR_vs_pT_Hjj->SetXTitle("p_{T}^{(H)} [GeV]");
   deltaR_vs_pT_Hjj->SetYTitle("#DeltaR(H,jj)");
   deltaM_vs_pT_Hjj->SetXTitle("pT");
   deltaM_vs_pT_Hjj->SetYTitle("#DeltaM");
   deltaR_vs_deltaM_Hj->SetXTitle("#DeltaM");
   deltaR_vs_deltaM_Hj->SetYTitle("#DeltaR");
   deltaR_vs_pT_Hj->SetXTitle("p_{T}^{(H)} [GeV]");
   deltaR_vs_pT_Hj->SetYTitle("#DeltaR(J,H)");
   deltaM_vs_pT_Hj->SetXTitle("p_{T}^{(H)} [GeV]");
   deltaM_vs_pT_Hj->SetYTitle("#DeltaM(H,J)");
   deltaRjj_vs_pT_Hjj->SetXTitle("p_{T}^{(H)} [GeV]");
   deltaRjj_vs_pT_Hjj->SetYTitle("#DeltaR(j,j)");
   distribHj_deltaM->SetXTitle("#DeltaM(H,J) [GeV]");
   distribHjj_deltaM->SetXTitle("#DeltaM(H,jj) [GeV]");
   deltaRjj_pT1->SetXTitle("#DeltaR(j,j)");
}

void jets_matching_toying::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t jets_matching_toying::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetEntry(entry);

   // filling of the TLorentzVectors
   v_H.SetPtEtaPhiE(*bH_pt,*bH_eta,*bH_phi,*bH_e);
   v_quark1.SetPtEtaPhiE(*genb1_pt,*genb1_eta,*genb1_phi,*genb1_e);
   v_quark2.SetPtEtaPhiE(*genb2_pt,*genb2_eta,*genb2_phi,*genb2_e);
   v_quark_tot = v_quark1 + v_quark2;
   v_fatjet.SetPtEtaPhiE(*fatjet_pt,*fatjet_eta,*fatjet_phi,*fatjet_e);

   // reset of bestR befor the next iteration
   bestR_HJ = 50;
   bestR_Hjj = 50;

   // runs on all the entries of the vector in the file to take the first jet of the couple
   for (size_t i = 0; i < genjets_pt.GetSize(); ++i) {
      // fill the vector of the first jet
      v_jet1.SetPtEtaPhiE(genjets_pt[i],genjets_eta[i],genjets_phi[i],genjets_e[i]);

      // runs on all the other entries of the vector in the file to take the second jet of the couple
      for (size_t c = i + 1; c < genjets_pt.GetSize(); ++c) {
        // fill the vector of the second jet
        v_jet2.SetPtEtaPhiE(genjets_pt[c],genjets_eta[c],genjets_phi[c],genjets_e[c]);

        // fill the total vector (i.e. sum of the two jets of the couple)
        v_tot = v_jet1 + v_jet2;

        // we impose the condition on the reciprocal magnitude of the jets
        if (v_jet1.Mag()/v_jet2.Mag() > 0.05 && v_jet1.Mag()/v_jet2.Mag() < 20) {
          if (v_H.DeltaR(v_tot) <= soglia_deltaR) {
            if (v_H.DeltaR(v_tot) <= bestR_Hjj) {
              v_jet1_best = v_jet1;
              v_jet2_best = v_jet2;
              v_tot_best = v_tot;

              bestR_Hjj = v_H.DeltaR(v_tot_best);
            }
          }
        }
      }

      // increment the counter to control if we are reading all the entries of every vector in the file
      ++k;
    }

    // we have only one fatjet for every event, tehrefore we do the geometric match of the HJ category
    // out of the for cycle
    // we impose the cut on the pT of the AK8 jet
    if (v_fatjet.Pt() > 15) {
      if (v_H.DeltaR(v_fatjet) <= soglia_deltaR) {
        if (v_H.DeltaR(v_fatjet) <= bestR_HJ) {
          v_jet1_HJbest = v_fatjet;

          bestR_HJ = v_H.DeltaR(v_jet1_HJbest);
        }
      }
    }

    // increment the counter to control if we are reading all the events
    ++j;

//-------------------------------------------------------------------------------------------------
// SELECTION OF THE BEST MATCH BETWEEN HJ AND Hjj
// EVERY PLOT IS FILLED WITH THE BEST MATCH FOUND FOR EVERY EVENT

  if (bestR_HJ == 50 && bestR_Hjj == 50) {
    ++NOMATCH;
  }

  if (bestR_HJ != 50 || bestR_Hjj != 50) {
    // we select the best geometric match found
    if (bestR_HJ < bestR_Hjj) {
      ++HJ_is_best_R;

      // all HJ plots are filled here
      deltaR_vs_pT_Hj->Fill(*bH_pt,v_jet1_HJbest.DeltaR(v_H));
      deltaM_vs_pT_Hj->Fill(*bH_pt,*bH_mass-v_jet1_HJbest.Mag());
      deltaR_vs_deltaM_Hj->Fill(*bH_mass-v_jet1_HJbest.Mag(),v_jet1_HJbest.DeltaR(v_H));

      distribHj_deltaM->Fill(*bH_mass-v_jet1_HJbest.Mag());
      distribHj_deltaR->Fill(v_jet1_HJbest.DeltaR(v_H)); // non fondamentale, solo per vedere come sono distribuite le
                                                         // deltaR nel caso del match geometrico

      Hj_tree->Fill(v_jet1_HJbest.DeltaR(v_H),*bH_mass-v_jet1_HJbest.Mag());
    } else {
      ++Hjj_is_best_R;

      // all Hjj plots are filled here
      deltaR_vs_pT_Hjj->Fill(*bH_pt,v_tot_best.DeltaR(v_H));
      deltaM_vs_pT_Hjj->Fill(*bH_pt,*bH_mass-v_tot_best.Mag());
      deltaR_vs_deltaM_Hjj->Fill(*bH_mass-v_tot_best.Mag(),v_tot_best.DeltaR(v_H));
      deltaRjj_vs_pT_Hjj->Fill(*bH_pt,v_jet1_best.DeltaR(v_jet2_best));

      deltaR_jet1_jet2->Fill(v_jet1_best.DeltaR(v_jet2_best));
      distribHjj_deltaM->Fill(*bH_mass-v_tot_best.Mag());
      distribHjj_deltaR->Fill(v_tot_best.DeltaR(v_H)); // non fondamentale, solo per vedere come sono distribuite
                                                       // le deltaR nel caso del match geometrico


      if (*bH_pt < 150) {
        deltaRjj_pT1->Fill(v_jet1_best.DeltaR(v_jet2_best));
      }
      if (*bH_pt > 150 && *bH_pt < 300) {
        deltaRjj_pT2->Fill(v_jet1_best.DeltaR(v_jet2_best));
      }
      if (*bH_pt > 300 && *bH_pt < 450) {
        deltaRjj_pT3->Fill(v_jet1_best.DeltaR(v_jet2_best));
      }
      if (*bH_pt > 450 && *bH_pt < 600) {
        deltaRjj_pT4->Fill(v_jet1_best.DeltaR(v_jet2_best));
      }
      if (*bH_pt > 600 && *bH_pt < 1260) {
        deltaRjj_pT5->Fill(v_jet1_best.DeltaR(v_jet2_best));
      }

      // for this control we don't need to order the jets because they are already ordered w.r.t pT in the file
      rhojj_control_pT->Fill(v_jet1_best.Pt()/v_jet2_best.Pt());
      rhojj_control_M->Fill(v_jet1_best.Mag()/v_jet2_best.Mag());
      rhojj_control_pT1->Fill(v_jet2_best.Pt()/v_jet1_best.Pt());
      rhojj_control_M1->Fill(v_jet2_best.Mag()/v_jet1_best.Mag());

      control_j1->Fill(v_jet1_best.DeltaR(v_quark1));
      control_j2->Fill(v_jet2_best.DeltaR(v_quark2));

      Hjj_tree->Fill(v_tot_best.DeltaR(v_H),*bH_mass-v_tot_best.Mag());
    }

    // another way to control the best match is to select, as the best geomwtric match, the one that gives the best
    // invariant mass reconstruction
    if (abs(v_jet1_HJbest.Mag()-v_H.Mag()) < abs(v_tot_best.Mag()-v_H.Mag())) {
      ++HJ_is_best_M;
    } else {
      ++Hjj_is_best_M;
    }
  }


   return kTRUE;
}

void jets_matching_toying::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void jets_matching_toying::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   // we save the data
   file->Write();


   //we draw all the plots and the canvas
   gStyle->SetPalette(kBird);
   gStyle->SetOptStat(0);
   gStyle->SetStatX(.90);
   gStyle->SetStatY(.90);

   c1->Divide(2,1);
   c1->cd(1);
   deltaR_vs_deltaM_Hjj->Draw("colz");
   c1->cd(2);
   deltaR_vs_deltaM_Hjj->ProjectionX("deltaM projection")->Draw(); // this has to be identical to (***)
   c1->Print("deltaR_vs_deltaM_Hjj_toying.png");

   c2->Divide(1,1);
   c2->cd(1);
   deltaR_vs_pT_Hjj->Draw("colz");
   c2->Print("deltaR_vs_pT_Hjj_toying.png");

   c3->Divide(1,1);
   c3->cd(1);
   deltaR_vs_deltaM_Hj->Draw("colz");
   c3->Print("deltaR_vs_deltaM_HJ_toying.png");

   c4->Divide(1,1);
   c4->cd(1);
   deltaR_vs_pT_Hj->Draw("colz");
   c4->Print("deltaR_vs_pT_HJ_toying.png");

   gStyle->SetOptStat("men");
   c17->Divide(3,1);
   c17->cd(1);
   deltaR_vs_pT_Hj->ProjectionY("p_{T}^{(H)} 0-290",7,23,"o")->Draw();
   c17->cd(2);
   deltaR_vs_pT_Hj->ProjectionY("p_{T}^{(H)} 290-428",24,34,"o")->Draw();
   c17->cd(3);
   deltaR_vs_pT_Hj->ProjectionY("p_{T}^{(H)} 428-1260",35,70,"o")->Draw();
   c17->Print("deltaR_vs_pT_HJ_projections.png");


   c5->Divide(2,1);
   c5->cd(1);
   distribHj_deltaM->Draw(); // (***)
   c5->cd(2);
   distribHj_deltaR->Draw();
   c5->Print("HJ_distributions_toying.png");

   c6->Divide(3,1);
   c6->cd(1);
   distribHjj_deltaM->Draw();
   c6->cd(2);
   distribHjj_deltaR->Draw();
   c6->cd(3);
   deltaR_jet1_jet2->Draw();
   c6->Print("Hjj_distributions_toying.png");

   c7->Divide(1,1);
   c7->cd(1);
   deltaM_vs_pT_Hj->Draw("colz");
   c7->Print("deltaM_vs_pT_HJ_toying.png");

   c8->Divide(1,1);
   c8->cd(1);
   deltaM_vs_pT_Hjj->Draw("colz");
   c8->Print("deltaM_vs_pT_Hjj_toying.png");

   c9->Divide(1,1);
   c9->cd(1);
   deltaRjj_vs_pT_Hjj->Draw("colz");
   c9->Print("deltaRjj_vs_pT_Hjj_toying.png");

   c10->Divide(5,4);
   c10->cd(1);
   deltaM_vs_pT_Hjj->ProjectionY("pT 0-25",0,1,"o")->Draw();
   c10->cd(2);
   deltaM_vs_pT_Hjj->ProjectionY("pT 25-50",2,3,"o")->Draw();
   c10->cd(3);
   deltaM_vs_pT_Hjj->ProjectionY("pT 50-75",4,5,"o")->Draw();
   c10->cd(4);
   deltaM_vs_pT_Hjj->ProjectionY("pT 75-100",6,7,"o")->Draw();
   c10->cd(5);
   deltaM_vs_pT_Hjj->ProjectionY("pT 100-125",8,9,"o")->Draw();
   c10->cd(6);
   deltaM_vs_pT_Hjj->ProjectionY("pT 125-150",10,11,"o")->Draw();
   c10->cd(7);
   deltaM_vs_pT_Hjj->ProjectionY("pT 150-175",12,13,"o")->Draw();
   c10->cd(8);
   deltaM_vs_pT_Hjj->ProjectionY("pT 175-200",14,15,"o")->Draw();
   c10->cd(9);
   deltaM_vs_pT_Hjj->ProjectionY("pT 200-225",16,17,"o")->Draw();
   c10->cd(10);
   deltaM_vs_pT_Hjj->ProjectionY("pT 225-250",18,19,"o")->Draw();
   c10->cd(11);
   deltaM_vs_pT_Hjj->ProjectionY("pT 250-275",20,21,"o")->Draw();
   c10->cd(12);
   deltaM_vs_pT_Hjj->ProjectionY("pT 275-300",22,23,"o")->Draw();
   c10->cd(13);
   deltaM_vs_pT_Hjj->ProjectionY("pT 300-325",24,25,"o")->Draw();
   c10->cd(14);
   deltaM_vs_pT_Hjj->ProjectionY("pT 325-350",26,27,"o")->Draw();
   c10->cd(15);
   deltaM_vs_pT_Hjj->ProjectionY("pT 350-375",28,29,"o")->Draw();
   c10->cd(16);
   deltaM_vs_pT_Hjj->ProjectionY("pT 375-400",30,31,"o")->Draw();
   c10->cd(17);
   deltaM_vs_pT_Hjj->ProjectionY("pT 400-425",32,33,"o")->Draw();
   c10->cd(18);
   deltaM_vs_pT_Hjj->ProjectionY("pT 425-450",34,35,"o")->Draw();
   c10->cd(19);
   deltaM_vs_pT_Hjj->ProjectionY("pT 450-475",36,37,"o")->Draw();
   c10->cd(20);
   deltaM_vs_pT_Hjj->ProjectionY("pT 475-500",38,39,"o")->Draw();
   c10->Print("deltaM_vs_pT_profiles_Hjj.png");

   c11->Divide(3,2);
   c11->cd(1);
   deltaR_jet1_jet2->Draw();
   c11->cd(2);
   deltaRjj_pT1->Draw();
   c11->cd(3);
   deltaRjj_pT2->Draw();
   c11->cd(4);
   deltaRjj_pT3->Draw();
   c11->cd(5);
   deltaRjj_pT4->Draw();
   c11->cd(6);
   deltaRjj_pT5->Draw();
   c11->Print("deltaR_jet1-jet2_different_pT.png");

   c12->Divide(2,1);
   c12->cd(1);
   control_j1->Draw();
   c12->cd(2);
   control_j2->Draw();
   c12->Print("jet-quark_control.png");

   c13->Divide(2,2);
   c13->cd(1);
   rhojj_control_pT1->Draw();
   c13->cd(2);
   rhojj_control_M1->Draw();
   c13->cd(3);
   rhojj_control_pT->Draw();
   c13->cd(4);
   rhojj_control_M->Draw();
   c13->Print("combinatory_controll_Hjj.png");

   c15->Divide(2,1);
   c15->cd(1);
   deltaR_jet1_jet2->Draw();
   c15->cd(2);
   deltaRjj_pT1->SetFillColorAlpha(kYellow,0.15);
   deltaRjj_pT1->DrawClone();
   deltaRjj_pT2->SetFillColorAlpha(kGreen-4,0.15);
   deltaRjj_pT2->Draw("same");
   deltaRjj_pT3->SetFillColorAlpha(kBlue,0.25);
   deltaRjj_pT3->DrawClone("same");
   deltaRjj_pT4->SetFillColorAlpha(kRed-4,0.35);
   deltaRjj_pT4->DrawClone("same");
   deltaRjj_pT5->SetFillColorAlpha(kRed+2,0.45);
   deltaRjj_pT5->DrawClone("same");
   leg->AddEntry(deltaRjj_pT1,"p_{T(H)} 0-150","f");
   leg->AddEntry(deltaRjj_pT2,"p_{T(H)} 150-300","f");
   leg->AddEntry(deltaRjj_pT3,"p_{T(H)} 300-450","f");
   leg->AddEntry(deltaRjj_pT4,"p_{T(H)} 450-600","f");
   leg->AddEntry(deltaRjj_pT5,"p_{T(H)} 600-1260","f");
   leg->DrawClone("same");
   c15->Print("deltaRjj_pT_superposed.png");

   c16->Divide(2,1);
   c16->cd(1);
   distribHj_deltaM->Draw();
   c16->cd(2);
   distribHjj_deltaM->Draw();
   c16->Print("deltaM_distributions.png");

   c18->Divide(1,1);
   c18->cd(1);
   distribHj_deltaM->Draw();
   c18->Print("deltaM_HJ.png");

   c19->Divide(1,1);
   c19->cd(1);
   distribHjj_deltaM->Draw();
   c19->Print("deltaM_Hjj.png");


   // we print an output on the terminal
   cout << "\n\n\n***********************************************************************************\n" << endl;
   // we control that the program has done all the cycles
   cout <<  "The number of iterations is: " << j << " (cfr. the number of events)" << endl;
   cout << "The number of iterations is: " << k << " (cfr. the total number of jets in genjets)"<< "\n" << endl;

   // correlation factors coming from the plots
   // THEY DEPEND ON THE BINNING!!!
   cout << "The correlation coefficient from Hj deltaR vs deltaM is: " << deltaR_vs_deltaM_Hj->GetCorrelationFactor() << endl;
   cout << "The correlation coefficient from Hj deltaR vs pT is: " << deltaR_vs_pT_Hj->GetCorrelationFactor() << endl;
   cout << "The correlation coefficient from Hjj deltaR vs deltaM is: " << deltaR_vs_deltaM_Hjj->GetCorrelationFactor() << endl;
   cout << "The correlation coefficient from Hjj deltaR vs pT is: " << deltaR_vs_pT_Hjj->GetCorrelationFactor() << "\n" << endl;

   cout << "NOMATCH = " << NOMATCH<< "\n"  << endl;

   cout << "HJ_is_best_R = " << HJ_is_best_R << endl;
   cout << "Hjj_is_best_R = " << Hjj_is_best_R << "\n" << endl;
   cout << "HJ_is_best_M = " << HJ_is_best_M << endl;
   cout << "Hjj_is_best_M = " << Hjj_is_best_M<< "\n"  << endl;

   // Integral(#bin_iniziale,#bin_finale)
   cout << "Integral of rhojj_control_pT = " << rhojj_control_pT->Integral(50,200) << " (cfr. executable to see where is the cut)" << endl;
   cout << "Integral of rhojj_control_M = " << rhojj_control_M->Integral(50,200) << " (cfr. executable to see where is the cut)\n" << endl;

   cout << "\n\n\n The running time of the program is " << watch.RealTime() << " seconds" << endl;
   cout << "\n***********************************************************************************\n\n\n" << endl;
}
