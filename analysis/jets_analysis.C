#define jets_analysis_cxx
// The class definition in jets_analysis.h has been generated automatically
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
// root> T->Process("jets_analysis.C")
// root> T->Process("jets_analysis.C","some options")
// root> T->Process("jets_analysis.C+")
//


#include "jets_analysis.h"
#include <TH2.h>
#include <TStyle.h>

void jets_analysis::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   watch.Start();

   // comment these two lines if we want to use different threshold for the HJ and Hjj categories
//   inf_HJ = inf_unica; inf_Hjj = inf_unica;
//   sup_HJ = sup_unica; sup_Hjj = sup_unica;

   combinatory_garbage->SetFillColor(kRed);
   test3->SetXTitle("M_{jj}");
   test3->SetYTitle("M_{J}");
}

void jets_analysis::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t jets_analysis::Process(Long64_t entry)
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
   v_Jet.SetPtEtaPhiE(*fatjet_pt,*fatjet_eta,*fatjet_phi,*fatjet_e);

   // reset of bestR, of bestM and of the booleans before the analysis of the next event
   bestM_Hjj = 1000;
   SJ_candidate = false;
   Sjj_candidate = false;
   bestR_HJ = 50;
   bestR_Hjj = 50;
   HJ_match_R = false;
   Hjj_match_R = false;
   HJ_is_best_R = false;
   Hjj_is_best_R = false;

   // we have only one fatjet for every event, tehrefore we do the geometric match of the SJ category
   // out of the for cycle
   // we impose the cut on the pT of the AK8 jet
   if (v_Jet.Pt() > soglia_Jet_pT) {
     if ((M_H - v_Jet.Mag()) >= inf_HJ && (M_H - v_Jet.Mag()) <= sup_HJ) {
       SJ_candidate = true;

       // fill histograms and trees
       HJ_deltaM->Fill(M_H - v_Jet.Mag());
       HJ_jetPT->Fill(*fatjet_pt);
       HJ_deltaM_vs_jetPT->Fill(*fatjet_pt,M_H - v_Jet.Mag());
       HJ_tree->Fill(M_H - v_Jet.Mag());

       // increment the counter to see how many SJ candidates we find
       ++k;
     }

     // we look for the best geometric match as in the MC_Truth
     if (v_H.DeltaR(v_Jet) <= soglia_deltaR) {
          bestR_HJ = v_H.DeltaR(v_Jet);

          HJ_match_R = true;
     }
   }

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

       // we look for the best Sjj candidate
       // when we already have an SJ candidate we don't need to do this
       if (SJ_candidate == false) {
         // we impose the condition on the reciprocal magnitude of the jets
         if (v_jet1.Mag()/v_jet2.Mag() > 0.05 && v_jet1.Mag()/v_jet2.Mag() < 20) {
           if ((M_H - v_tot.Mag()) >= inf_Hjj && (M_H - v_tot.Mag()) <= sup_Hjj) {
             if (abs(M_H - v_tot.Mag()) < bestM_Hjj) {
               bestM_Hjj = abs(M_H - v_tot.Mag());
               v_tot_best = v_tot;
               v_jet1_best = v_jet1;
               v_jet2_best = v_jet2;

               Sjj_candidate = true;
             }
           }
         }
       }

       // we look for the best geometric match as in the MC_Truth
       if (v_H.DeltaR(v_tot) <= soglia_deltaR) {
         if (v_H.DeltaR(v_tot) <= bestR_Hjj) {
           v_jet1_best_R = v_jet1;
           v_jet2_best_R = v_jet2;
           v_tot_best_R = v_tot;
           bestR_Hjj = v_H.DeltaR(v_tot_best_R);

           Hjj_match_R = true;
         }
       }
     }
   }

   test4->Fill(v_tot_best_R.Pt());

   // Sjj histograms
   if (Sjj_candidate == true) {
     Hjj_deltaM->Fill(M_H - v_tot_best.Mag());
     deltaRjj->Fill(v_jet1_best.DeltaR(v_jet2_best));
     Hjj_deltaM_vs_totPT->Fill(v_tot.Pt(),M_H - v_tot.Mag());
     // ricontrollare questa formula
     H_expected_pT->Fill(M_H/(v_jet1_best.DeltaR(v_jet2_best)*sqrt(v_jet1_best.Mag()/M_H*(1-v_jet1_best.Mag()/M_H))));

     // we must order in magnitide the two AK4 jets
     if (v_jet1_best.Mag() < v_jet2_best.Mag()) {
       combinatory->Fill(v_jet1_best.Mag()/v_jet2_best.Mag());
     } else {
       combinatory->Fill(v_jet2_best.Mag()/v_jet1_best.Mag());
     }

     // increment the counter to see how many Sjj candidate we find
     ++l;
   }

   // we count the number of events without candidates
   if (SJ_candidate == false && Sjj_candidate == false) {
     ++p;
   }

   // we choose the best geometric match between the HJ and Hjj categories (therefore is made based on the geometric matches)
   if (HJ_match_R == true || Hjj_match_R == true) {
     if (bestR_HJ < bestR_Hjj) {
       // we count how many HJ we have
       ++k_R;
       HJ_is_best_R = true;
     } else {
       // we count how many Hjj we have
       ++l_R;
       Hjj_is_best_R = true;
     }
   }

   // we count the number of events without geometric matches
   if (HJ_match_R == false && Hjj_match_R == false) {
     ++p_R;
   }

   // fill the COMPARISON MATRIX
   if (SJ_candidate == true && HJ_is_best_R == true) {
     a = a + 1;

     // some histos to look how the events in this category behave
     HJ_deltaM_good->Fill(125-v_Jet.Mag());
     HJ_jetPT_good->Fill(v_Jet.Pt());
   }
   if (SJ_candidate == true && Hjj_is_best_R == true) {
     b = b + 1;

     // histos to look how the events in this category behave
     HJ_deltaM_garbage->Fill(125 - v_Jet.Mag());
     HJ_jetPT_garbage->Fill(v_Jet.Pt());

     // histos to look how in the MCTruth the events in this category behave
     // these must be compared to the two above
     HJ_Hjj_truth_pT->Fill(v_tot_best_R.Pt());
     HJ_Hjj_truth_deltaM->Fill(*bH_mass - v_tot_best_R.Mag());

     if (v_jet1_best_R.Mag() < v_jet2_best_R.Mag()) {
       test->Fill(v_jet1_best_R.Mag()/v_jet2_best_R.Mag());
       test2->Fill(v_tot_best_R.Pt(),v_jet1_best_R.Mag()/v_jet2_best_R.Mag());
     } else {
       test->Fill(v_jet2_best_R.Mag()/v_jet1_best_R.Mag());
       test2->Fill(v_tot_best_R.Pt(),v_jet2_best_R.Mag()/v_jet1_best_R.Mag());
     }

     test3->Fill(v_tot_best_R.Mag(),v_Jet.Mag());

   }
   if (Sjj_candidate == true && HJ_is_best_R == true) {
     c = c + 1;

     // to be compared to the combinatory
     if (v_jet1_best.Mag() < v_jet2_best.Mag()) {
       combinatory_garbage->Fill(v_jet1_best.Mag()/v_jet2_best.Mag());
     } else {
       combinatory_garbage->Fill(v_jet2_best.Mag()/v_jet1_best.Mag());
     }

     // histos to look how the events in this category behave
     Hjj_deltaM_garbage->Fill(125 - v_tot_best.Mag());
     deltaRjj_garbage->Fill(v_jet1_best.DeltaR(v_jet2_best));
     Hjj_pT_garbage->Fill(v_tot_best.Pt());

     // histos to look how in the MCTruth the events in this category behave
     // these must be compared to the three above
     Hjj_HJ_truth_pT->Fill(v_Jet.Pt());
     Hjj_HJ_truth_deltaM->Fill(*bH_mass - v_Jet.Mag());

     jet1_pT->Fill(v_jet1_best.Pt());
     jet2_pT->Fill(v_jet2_best.Pt());
     jet_tot_pT->Fill(v_tot_best.Pt());
   }
   if (Sjj_candidate == true && Hjj_is_best_R == true) {
     d = d + 1;

     // histos to look how the events in this category behave
     Hjj_deltaM_good->Fill(125 - v_tot_best.Mag());
     deltaRjj_good->Fill(v_jet1_best.DeltaR(v_jet2_best));
     Hjj_pT_good->Fill(v_tot_best.Pt());
   }

     // histos of deltaRjj for different pT ranges
     if (v_tot_best.Pt() < 150) {
       deltaRjj_pT1->Fill(v_jet1_best.DeltaR(v_jet2_best));
     }
     if (v_tot_best.Pt() > 150 && v_tot_best.Pt() < 300) {
       deltaRjj_pT2->Fill(v_jet1_best.DeltaR(v_jet2_best));
     }
     if (v_tot_best.Pt() > 300 && v_tot_best.Pt() < 450) {
       deltaRjj_pT3->Fill(v_jet1_best.DeltaR(v_jet2_best));
     }
     if (v_tot_best.Pt() > 450 && v_tot_best.Pt() < 600) {
       deltaRjj_pT4->Fill(v_jet1_best.DeltaR(v_jet2_best));
     }
     if (v_tot_best.Pt() > 600 && v_tot_best.Pt() < 1260) {
       deltaRjj_pT5->Fill(v_jet1_best.DeltaR(v_jet2_best));
     }


   // increment the counter to control if we are reading all the events
   ++j;

   return kTRUE;
}


void jets_analysis::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void jets_analysis::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   // we save the data
   file->Write();


   //we draw all the plots and the canvas
   gStyle->SetStatX(.90);
   gStyle->SetStatY(.94);
   c1->Divide(1,1);
   c1->cd(1);
   HJ_deltaM_vs_jetPT->Draw("colz");
   c1->Print("HJ_deltaM_vs_jetPT.png");

   c2->Divide(2,1);
   c2->cd(1);
   HJ_jetPT->Draw();
   c2->cd(2);
   HJ_deltaM->Draw();
   c2->Print("HJ_distributions.png");

   c3->Divide(1,1);
   c3->cd(1);
   Hjj_deltaM_vs_totPT->Draw("colz");
   c3->Print("Hjj_deltaM_vs_jetPT.png");

   c4->Divide(2,2);
   c4->cd(1);
   Hjj_deltaM->Draw();
   c4->cd(2);
   deltaRjj->Draw();
   c4->cd(3);
   combinatory->Draw();
   c4->cd(4);
   combinatory_garbage->DrawClone("Same");
   c4->Print("Hjj_distributions.png");

   c5->Divide(3,2);
   c5->cd(1);
   deltaRjj->Draw();
   c5->cd(2);
   deltaRjj_pT1->Draw();
   c5->cd(3);
   deltaRjj_pT2->Draw();
   c5->cd(4);
   deltaRjj_pT3->Draw();
   c5->cd(5);
   deltaRjj_pT4->Draw();
   c5->cd(6);
   deltaRjj_pT5->Draw();
   c5->Print("deltaR_jet1-jet2_different_pT.png");

   c6->Divide(1,1);
   c6->cd(1);
   deltaRjj_pT2->SetFillColorAlpha(kGreen-7,0.15);
   deltaRjj_pT2->Draw();
   deltaRjj_pT1->SetFillColorAlpha(kYellow,0.15);
   deltaRjj_pT1->DrawClone("same");
   deltaRjj_pT3->SetFillColorAlpha(kBlue,0.25);
   deltaRjj_pT3->DrawClone("same");
   deltaRjj_pT4->SetFillColorAlpha(kRed-4,0.35);
   deltaRjj_pT4->DrawClone("same");
   deltaRjj_pT5->SetFillColorAlpha(kRed+2,0.45);
   deltaRjj_pT5->DrawClone("same");
   leg->AddEntry(deltaRjj_pT1,"jj_pT 0-150","f");
   leg->AddEntry(deltaRjj_pT2,"jj_pT 150-300","f");
   leg->AddEntry(deltaRjj_pT3,"jj_pT 300-450","f");
   leg->AddEntry(deltaRjj_pT4,"jj_pT 450-600","f");
   leg->AddEntry(deltaRjj_pT5,"jj_pT 600-1260","f");
   leg->DrawClone("same");
   c6->Print("deltaRjj_pT_superposed.png");

   c7->Divide(2,3);
   c7->cd(1);
   HJ_jetPT_good->Draw();
   c7->cd(2);
   HJ_deltaM_good->Draw();
   c7->cd(3);
   HJ_jetPT_garbage->Draw();
   c7->cd(4);
   HJ_deltaM_garbage->Draw();
   c7->cd(5);
   HJ_Hjj_truth_pT->Draw();
   c7->cd(6);
   HJ_Hjj_truth_deltaM->Draw();
   c7->Print("HJ_garbage_good.png");

   c8->Divide(3,3);
   c8->cd(1);
   Hjj_deltaM_good->Draw();
   c8->cd(2);
   deltaRjj_good->Draw();
   c8->cd(3);
   Hjj_pT_good->Draw();
   c8->cd(4);
   Hjj_deltaM_garbage->Draw();
   c8->cd(5);
   deltaRjj_garbage->Draw();
   c8->cd(6);
   Hjj_pT_garbage->Draw();
   c8->cd(7);
   Hjj_HJ_truth_deltaM->Draw();
   c8->cd(9);
   Hjj_HJ_truth_pT->Draw();
   c8->Print("Hjj_garbage_good.png");

   c9->Divide(2,1);
   c9->cd(1);
   test->Draw();
   c9->cd(2);
   test2->Draw("colz");
   c9->Print("test.png");

   c10->Divide(1,1);
   c10->cd(1);
   test3->Draw("colz");
   c10->Print("MJ:Mjj.png");

   c11->Divide(1,1);
   c11->cd(1);
   test4->Draw();
   c11->Print("Hjj_pT_distrib.png");

   c12->Divide(3,1);
   c12->cd(1);
   jet1_pT->Draw();
   c12->cd(2);
   jet2_pT->Draw();
   c12->cd(3);
   jet_tot_pT->Draw();
   c12->Print("jj_pT_garbage.png");


   // we print an output on the terminal
   cout << "\n\n\n***********************************************************************************\n" << endl;
   // we control that the program has done all the cycles
   cout << j << "\titerations done (should be the number of events 25569)\n" << endl;

   cout << "MASS CONSTRAINTS" << endl;
   cout << "inf_HJ = " << inf_HJ << "\tsup_HJ = " << sup_HJ << endl;
   cout << "inf_Hjj = " << inf_Hjj << "\tsup_Hjj = " << sup_Hjj << "\n" << endl;

   cout << k << "\tHJ candidates found" << endl;
   cout << l << "\tHjj candidates found" << endl;
   cout << p << "\tevents without HJ or Hjj candidates\n" << endl;

   cout << k_R << "\tHJ geometrical matches found" << endl;
   cout << l_R << "\tHjj geometrical matches found" << endl;
   cout << p_R << "\tevents without HJ or Hjj geometrical matches" << endl;

   cout << "\nEFFICIENCIES" << endl;
   cout << "e_tot = " << double(k+l)/double(j) <<
           "\te_HJ = " << double(k)/double(j) <<
           "\te_Hjj = " << double(l)/double(j) << endl;
   cout << "e_r_HJ = " << (double(k)/double(j))/(double(k+l)/double(j)) <<
          "\te_r_Hjj = " << (double(l)/double(j))/(double(k+l)/double(j)) << endl;

   cout << "\n\n\nCOMPARISON MATRIX" << endl;
   cout << "-----------------------------------" << endl;
   cout << "| \tHJ\tHjj" << endl;
   cout << "| SJ \t" << a << "\t" << b <<  endl;
   cout << "| Sjj\t" << c << "\t" << d << endl;
   cout << "-----------------------------------" << endl;

   cout << "\n\n\nEFFICIENCY MATRIX" << endl;
   cout << "-------------------------------------------" << endl;
   cout << "| \tHJ\tHjj" << endl;
   cout << "| SJ \t" << a/k_R << "\t" << b/l_R << endl;
   cout << "| Sjj\t" << c/k_R << "\t" << d/l_R <<  endl;
   cout << "-------------------------------------------" << endl;

   cout << "\n\n\n The running time of the program is " << watch.RealTime() << " seconds" << endl;
   cout << "\n***********************************************************************************\n\n\n" << endl;
}
