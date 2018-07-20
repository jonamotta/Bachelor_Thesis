void performance() {

  TCanvas *c1 = new TCanvas("Performance","Performance",1400,700);
  TCanvas *c2 = new TCanvas("Single performances semi-lep","Single performances semi-lep",1400,700);
  TCanvas *c3 = new TCanvas("Single performances fully lep","Single performances fully lep",1400,700);

  TGraph2D *mappJ = new TGraph2D();
  mappJ->SetTitle("#frac{S}{#sqrt{B}} - HJ category");
  TAxis *XaxisJ = mappJ->GetXaxis();
  TAxis *YaxisJ = mappJ->GetYaxis();
  TAxis *ZaxisJ = mappJ->GetZaxis();
  XaxisJ->SetTitle("inferior #DeltaM"); XaxisJ->SetTitleOffset(2);
  YaxisJ->SetTitle("superior #DeltaM"); YaxisJ->SetTitleOffset(2);
  ZaxisJ->SetTitle(""); ZaxisJ->SetTitleOffset(1.5);

  TGraph2D *mappjj = new TGraph2D();
  mappjj->SetTitle("#frac{S}{#sqrt{B}} - Hjj category");
  TAxis *Xaxisjj = mappjj->GetXaxis();
  TAxis *Yaxisjj = mappjj->GetYaxis();
  TAxis *Zaxisjj = mappjj->GetZaxis();
  Xaxisjj->SetTitle("inferior #DeltaM"); Xaxisjj->SetTitleOffset(2);
  Yaxisjj->SetTitle("superior #DeltaM"); Yaxisjj->SetTitleOffset(2);
  Zaxisjj->SetTitle(""); Zaxisjj->SetTitleOffset(1.5);

  TGraph2D *mapp2J = new TGraph2D();
  mapp2J->SetTitle("");
  TAxis *Xaxis2J = mapp2J->GetXaxis();
  TAxis *Yaxis2J = mapp2J->GetYaxis();
  TAxis *Zaxis2J = mapp2J->GetZaxis();
  Xaxis2J->SetTitle("inferior #DeltaM"); Xaxis2J->SetTitleOffset(2);
  Yaxis2J->SetTitle("superior #DeltaM"); Yaxis2J->SetTitleOffset(2);
  Zaxis2J->SetTitle(""); Zaxis2J->SetTitleOffset(1.5);

  TGraph2D *mapp2jj = new TGraph2D();
  mapp2jj->SetTitle("");
  TAxis *Xaxis2jj = mapp2jj->GetXaxis();
  TAxis *Yaxis2jj = mapp2jj->GetYaxis();
  TAxis *Zaxis2jj = mapp2jj->GetZaxis();
  Xaxis2jj->SetTitle("inferior #DeltaM"); Xaxis2jj->SetTitleOffset(2);
  Yaxis2jj->SetTitle("superior #DeltaM"); Yaxis2jj->SetTitleOffset(2);
  Zaxis2jj->SetTitle(""); Zaxis2jj->SetTitleOffset(1.5);

  TGraph2D *mapp3J = new TGraph2D();
  mapp3J->SetTitle("");
  TAxis *Xaxis3J = mapp3J->GetXaxis();
  TAxis *Yaxis3J = mapp3J->GetYaxis();
  TAxis *Zaxis3J = mapp3J->GetZaxis();
  Xaxis3J->SetTitle("inferior #DeltaM"); Xaxis3J->SetTitleOffset(2);
  Yaxis3J->SetTitle("superior #DeltaM"); Yaxis3J->SetTitleOffset(2);
  Zaxis3J->SetTitle(""); Zaxis3J->SetTitleOffset(1.5);

  TGraph2D *mapp3jj = new TGraph2D();
  mapp3jj->SetTitle("");
  TAxis *Xaxis3jj = mapp3jj->GetXaxis();
  TAxis *Yaxis3jj = mapp3jj->GetYaxis();
  TAxis *Zaxis3jj = mapp3jj->GetZaxis();
  Xaxis3jj->SetTitle("inferior #DeltaM"); Xaxis3jj->SetTitleOffset(2);
  Yaxis3jj->SetTitle("superior #DeltaM"); Yaxis3jj->SetTitleOffset(2);
  Zaxis3jj->SetTitle(""); Zaxis3jj->SetTitleOffset(1.5);

  ifstream BG_fl("fullyLepBG_analysis.txt");
  ifstream BG_sl("semiLepBG_analysis.txt");
  ifstream SIGNAL("signal_analysis.txt");

  long double a, b, c, d, e, f, g, h, i, l, m, n;
  int j = 0;

  while (BG_fl >> a >> b >> c >> d &&
         BG_sl >> e >> f >> g >> h &&
         SIGNAL >> i >> l >> m >> n) {

    if (a == e && e == i && b == f && f == l) {
      mappJ->SetPoint(j,abs(a),b,m/sqrt(c+g));
      mappjj->SetPoint(j,abs(a),b,n/sqrt(d+h));
      mapp2J->SetPoint(j,abs(a),b,m/sqrt(g));
      mapp2jj->SetPoint(j,abs(a),b,n/sqrt(h));
      mapp3J->SetPoint(j,abs(a),b,m/sqrt(c));
      mapp3jj->SetPoint(j,abs(a),b,n/sqrt(d));
    }
    else {
      cout << "DIFFERENT LIMITS FOUND! ABORTING EXECUTION OF THE PROGRAM" << endl;
      break;
    }

    ++j;
  }

  cout << j << endl;

  gStyle->SetPalette(1);
  c1->Divide(2,1);
  c1->cd(1);
  mappJ->SetMarkerStyle(20);
  mappJ->Draw("pcol");
  c1->cd(2);
  mappjj->SetMarkerStyle(20);
  mappjj->Draw("pcol");
  c1->Print("performance_plot.png");

  c2->Divide(2,1);
  c2->cd(1);
  mapp2J->SetMarkerStyle(20);
  mapp2J->Draw("pcol");
  c2->cd(2);
  mapp2jj->SetMarkerStyle(20);
  mapp2jj->Draw("pcol");
  c2->Print("single_performances_plot_semilep.png");
  c3->Divide(2,1);
  c3->cd(1);
  mapp3J->SetMarkerStyle(20);
  mapp3J->Draw("pcol");
  c3->cd(2);
  mapp3jj->SetMarkerStyle(20);
  mapp3jj->Draw("pcol");
  c3->Print("single_performances_plot_fullylep.png");

}
