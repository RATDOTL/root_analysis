{

  TCanvas* c1 = new TCanvas("c1","",0,0,600,600);

  c1->Divide(2,2);

  TFile *file0 = TFile::Open("run003.root");
  file0->cd();

  c1->cd(1);
  T->Draw("t[0]>>h0(1000,0,2000)");
  h0->GetXaxis()->SetTitle("tdc (ch)");

  c1->cd(2);
  T->Draw("t[1]>>h1(1000,0,2000)");
  h1->GetXaxis()->SetTitle("tdc (ch)");

  c1->cd(3);
  T->Draw("t[2]>>h2(1000,0,2000)");
  h2->GetXaxis()->SetTitle("tdc (ch)");

  c1->cd(4);
  T->Draw("t[3]>>h3(1000,0,2000)");
  h3->GetXaxis()->SetTitle("tdc (ch)");

  c1->Print("tdc.pdf");

}
