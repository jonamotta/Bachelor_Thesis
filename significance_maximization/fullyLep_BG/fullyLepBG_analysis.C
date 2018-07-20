#define fullyLepBG_analysis_cxx
// The class definition in fullyLepBG_analysis.h has been generated automatically
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
// root> T->Process("fullyLepBG_analysis.C")
// root> T->Process("fullyLepBG_analysis.C","some options")
// root> T->Process("fullyLepBG_analysis.C+")
//


#include "fullyLepBG_analysis.h"
#include <TH2.h>
#include <TStyle.h>

void fullyLepBG_analysis::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   watch.Start();
}

void fullyLepBG_analysis::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t fullyLepBG_analysis::Process(Long64_t entry)
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

if (*pairType == 0) {

   // commentare le due linee seguenti se si vogliono utilizzare soglie differenti per HJ e Hjj
   // devo resettarle al valore iniziale per ogni evento, altrimenti fa selezione con estremi sbagliati
   inf_HJ = inf_unica; inf_Hjj = inf_unica;
   sup_HJ = sup_unica; sup_Hjj = sup_unica;

   // c'è solo un fatjet(AK8) per evento quindi si setta una volta sola
   v_Jet.SetPtEtaPhiE(*fatjet_pt,*fatjet_eta,*fatjet_phi,*fatjet_e);

   // facciamo un ciclo for che permetta di fare più di una analisi per volta con differenti tagli in massa
   // funziona abbastanza a mano
   for (size_t N = 0; N < 10; N++) {
     // reset dei dei bestM e delle booleane prima che si analizzi l'evento con tagli differenti
     bestM_Hjj = 1000;
     HJ_candidate = false;
     Hjj_candidate = false;

     // c'è solo un fatjet(AK8) per evento quindi si setta fa il match una volta sola per ogni taglio
     if ((M_H - v_Jet.Mag()) >= inf_HJ && (M_H - v_Jet.Mag()) <= sup_HJ) {
       HJ_candidate = true;
     }

     // il primo ciclo for gira su tutte le entrate del vettore per prendere il primo dei due jet da studiare
     for (size_t i = 0; i < genjets_pt.GetSize(); ++i) {
       // riempiamo il primo TLorentzVector con i dati relativi al primo jet
       v_jet1.SetPtEtaPhiE(genjets_pt[i],genjets_eta[i],genjets_phi[i],genjets_e[i]);

       // il secondo ciclo for gira su tutte le altre entrate del vettore per prendere il secondo vettore
       // della coppia da analizzare
       for (size_t c = i + 1; c < genjets_pt.GetSize(); ++c) {
         // riempiamo il secondo TLorentzVector con i dati relativi al secondo jet della coppia da studiare
         v_jet2.SetPtEtaPhiE(genjets_pt[c],genjets_eta[c],genjets_phi[c],genjets_e[c]);

         // riempiamo il TLorentzVector totale dei due jets
         v_tot = v_jet1 + v_jet2;

         // cerchiamo il miglior candidato Hjj
         // quando ho già un buon candidato HJ non mi serve di entrare a vedere cosa fa Hjj
         if (HJ_candidate == false) {
           // inseriamo un if che butti via direttamente i casi in cui i due jets sono molto diversi in massa invatriante
           // perchè mi aspetto che siano ragionevolmente vicini
           if (v_jet1.Mag()/v_jet2.Mag() > 0.05 && v_jet1.Mag()/v_jet2.Mag() < 20) {
             if ((M_H - v_tot.Mag()) >= inf_Hjj && (M_H - v_tot.Mag()) <= sup_Hjj) {
               if (abs(M_H - v_tot.Mag()) < bestM_Hjj) {
                 bestM_Hjj = abs(M_H - v_tot.Mag());
                 v_tot_best = v_tot;
                 v_jet1_best = v_jet1;
                 v_jet2_best = v_jet2;

                 Hjj_candidate = true;
               }
             }
           }
         }
       }
     }

     // tutti questi if servono per mettere nelle giuste categorie le giuste selezioni fatte con i differenti tagli
     if (N == 0) {
       if (HJ_candidate == true || Hjj_candidate == true) {
         ++sel0;
         inf0 = inf_HJ;
         sup0 = sup_HJ;
       }
       if (HJ_candidate == true) {
         ++sel0J;
       }
       if (Hjj_candidate == true) {
         ++sel0jj;
       }
     }
     if (N == 1) {
       if (HJ_candidate == true || Hjj_candidate == true) {
         ++sel1;
         inf1 = inf_HJ;
         sup1 = sup_HJ;
       }
       if (HJ_candidate == true) {
         ++sel1J;
       }
       if (Hjj_candidate == true) {
         ++sel1jj;
       }
     }
     if (N == 2) {
       if (HJ_candidate == true || Hjj_candidate == true) {
         ++sel2;
         inf2 = inf_HJ;
         sup2 = sup_HJ;
       }
       if (HJ_candidate == true) {
         ++sel2J;
       }
       if (Hjj_candidate == true) {
         ++sel2jj;
       }
     }
     if (N == 3) {
       if (HJ_candidate == true || Hjj_candidate == true) {
         ++sel3;
         inf3 = inf_HJ;
         sup3 = sup_HJ;
       }
       if (HJ_candidate == true) {
         ++sel3J;
       }
       if (Hjj_candidate == true) {
         ++sel3jj;
       }
     }
     if (N == 4) {
       if (HJ_candidate == true || Hjj_candidate == true) {
         ++sel4;
         inf4 = inf_HJ;
         sup4 = sup_HJ;
       }
       if (HJ_candidate == true) {
         ++sel4J;
       }
       if (Hjj_candidate == true) {
         ++sel4jj;
       }
     }
     if (N == 5) {
       if (HJ_candidate == true || Hjj_candidate == true) {
         ++sel5;
         inf5 = inf_HJ;
         sup5 = sup_HJ;
       }
       if (HJ_candidate == true) {
         ++sel5J;
       }
       if (Hjj_candidate == true) {
         ++sel5jj;
       }
     }
     if (N == 6) {
       if (HJ_candidate == true || Hjj_candidate == true) {
         ++sel6;
         inf6 = inf_HJ;
         sup6 = sup_HJ;
       }
       if (HJ_candidate == true) {
         ++sel6J;
       }
       if (Hjj_candidate == true) {
         ++sel6jj;
       }
     }
     if (N == 7) {
       if (HJ_candidate == true || Hjj_candidate == true) {
         ++sel7;
         inf7 = inf_HJ;
         sup7 = sup_HJ;
       }
       if (HJ_candidate == true) {
         ++sel7J;
       }
       if (Hjj_candidate == true) {
         ++sel7jj;
       }
     }
     if (N == 8) {
       if (HJ_candidate == true || Hjj_candidate == true) {
         ++sel8;
         inf8 = inf_HJ;
         sup8 = sup_HJ;
       }
       if (HJ_candidate == true) {
         ++sel8J;
       }
       if (Hjj_candidate == true) {
         ++sel8jj;
       }
     }
     if (N == 9) {
       if (HJ_candidate == true || Hjj_candidate == true) {
         ++sel9;
         inf9 = inf_HJ;
         sup9 = sup_HJ;
       }
       if (HJ_candidate == true) {
         ++sel9J;
       }
       if (Hjj_candidate == true) {
         ++sel9jj;
       }
     }

     // cambiamo i valori dei tagli in massa
     inf_HJ = inf_HJ + 10; inf_Hjj = inf_Hjj + 10;
     //sup_HJ = sup_HJ - 10; sup_Hjj = sup_Hjj - 10;

     // incrementiamo il contatore per vedere se fa tutti i cicli correttamente
     ++k;
   }
}
   // incrementiamo il contatore per vedere se legge tutti gli eventi
   ++j;

   return kTRUE;
}

void fullyLepBG_analysis::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void fullyLepBG_analysis::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

   // scriviamo i dati separati per categorizzazione J e jj in un file
   std::ofstream file;
   file.open("fullyLepBG_analysis.txt", std::ios::app); // file aperto in "append mode" per poter scrivere senza cancellare
   file << inf0 << " " << sup0 << " " << (sel0J*L*XS_fullyLep)/j << " " << (sel0jj*L*XS_fullyLep)/j << endl;
   file << inf1 << " " << sup1 << " " << (sel1J*L*XS_fullyLep)/j << " " << (sel1jj*L*XS_fullyLep)/j << endl;
   file << inf2 << " " << sup2 << " " << (sel2J*L*XS_fullyLep)/j << " " << (sel2jj*L*XS_fullyLep)/j << endl;
   file << inf3 << " " << sup3 << " " << (sel3J*L*XS_fullyLep)/j << " " << (sel3jj*L*XS_fullyLep)/j << endl;
   file << inf4 << " " << sup4 << " " << (sel4J*L*XS_fullyLep)/j << " " << (sel4jj*L*XS_fullyLep)/j << endl;
   file << inf5 << " " << sup5 << " " << (sel5J*L*XS_fullyLep)/j << " " << (sel5jj*L*XS_fullyLep)/j << endl;
   file << inf6 << " " << sup6 << " " << (sel6J*L*XS_fullyLep)/j << " " << (sel6jj*L*XS_fullyLep)/j << endl;
   file << inf7 << " " << sup7 << " " << (sel7J*L*XS_fullyLep)/j << " " << (sel7jj*L*XS_fullyLep)/j << endl;
   file << inf8 << " " << sup8 << " " << (sel8J*L*XS_fullyLep)/j << " " << (sel8jj*L*XS_fullyLep)/j << endl;
   file << inf9 << " " << sup9 << " " << (sel9J*L*XS_fullyLep)/j << " " << (sel9jj*L*XS_fullyLep)/j << endl;
   file.close();

   // scriviamo i dati senza categorizzazione J e jj in un altro file (T sta per totale)
   std::ofstream file_T;
   file_T.open("fullyLepBG_analysis_T.txt", std::ios::app); // file aperto in "append mode" per poter scrivere senza cancellare
   file_T << inf0 << " " << sup0 << " " << sel0 << " " << (sel0*L*XS_fullyLep)/j << endl;
   file_T << inf1 << " " << sup1 << " " << sel1 << " " << (sel1*L*XS_fullyLep)/j << endl;
   file_T << inf2 << " " << sup2 << " " << sel2 << " " << (sel2*L*XS_fullyLep)/j << endl;
   file_T << inf3 << " " << sup3 << " " << sel3 << " " << (sel3*L*XS_fullyLep)/j << endl;
   file_T << inf4 << " " << sup4 << " " << sel4 << " " << (sel4*L*XS_fullyLep)/j << endl;
   file_T << inf5 << " " << sup5 << " " << sel5 << " " << (sel5*L*XS_fullyLep)/j << endl;
   file_T << inf6 << " " << sup6 << " " << sel6 << " " << (sel6*L*XS_fullyLep)/j << endl;
   file_T << inf7 << " " << sup7 << " " << sel7 << " " << (sel7*L*XS_fullyLep)/j << endl;
   file_T << inf8 << " " << sup8 << " " << sel8 << " " << (sel8*L*XS_fullyLep)/j << endl;
   file_T << inf9 << " " << sup9 << " " << sel9 << " " << (sel9*L*XS_fullyLep)/j << endl;
   file_T.close();

   cout << "\n\n\n***********************************************************************************\n" << endl;

   // vediamo se ha fatto tutti i cicli correttamnete o se si è perso qualcosa
   cout << j << "\tevents read (should be the number of events 25569)" << endl;
   cout << k << "\titerations done (should be the number of events 25569*N)\n" << endl;

   cout << "\ninf=" << inf0 << "\tsup=" << sup0 << "\t#sel=" << sel0 << "\tS=" << (sel0*L*XS_fullyLep)/j << endl;
   cout << "inf=" << inf1 << "\tsup=" << sup1 << "\t#sel=" << sel1 << "\tS=" << (sel1*L*XS_fullyLep)/j << endl;
   cout << "inf=" << inf2 << "\tsup=" << sup2 << "\t#sel=" << sel2 << "\tS=" << (sel2*L*XS_fullyLep)/j<< endl;
   cout << "inf=" << inf3 << "\tsup=" << sup3 << "\t#sel=" << sel3 << "\tS=" << (sel3*L*XS_fullyLep)/j<< endl;
   cout << "inf=" << inf4 << "\tsup=" << sup4 << "\t#sel=" << sel4 << "\tS=" << (sel4*L*XS_fullyLep)/j<< endl;
   cout << "inf=" << inf5 << "\tsup=" << sup5 << "\t#sel=" << sel5 << "\tS=" << (sel5*L*XS_fullyLep)/j<< endl;
   cout << "inf=" << inf6 << "\tsup=" << sup6 << "\t#sel=" << sel6 << "\tS=" << (sel6*L*XS_fullyLep)/j<< endl;
   cout << "inf=" << inf7 << "\tsup=" << sup7 << "\t#sel=" << sel7 << "\tS=" << (sel7*L*XS_fullyLep)/j<< endl;
   cout << "inf=" << inf8 << "\tsup=" << sup8 << "\t#sel=" << sel8 << "\tS=" << (sel8*L*XS_fullyLep)/j<< endl;
   cout << "inf=" << inf9 << "\tsup=" << sup9 << "\t#sel=" << sel9 << "\tS=" << (sel9*L*XS_fullyLep)/j<< endl;

   cout << "\n\n\n The running time of the program is " << watch.RealTime() << " seconds" << endl;
   cout << "\n***********************************************************************************\n\n\n" << endl;

}
