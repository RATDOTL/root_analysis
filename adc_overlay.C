{

  TFile *f0 = TFile::Open("run003.root");
  TFile *f1 = TFile::Open("run004.root");

  TCanvas *c1 = new TCanvas("c1", "", 0, 0, 600, 600);

  gPad->DrawFrame(0., 0., 1., 1.);

  char buf1[100], buf2[100];
 
  c1->Clear();
  c1->Draw();
  c1->Divide(2,2);
  
  for( int ch=0; ch<4; ch++){
    
    c1->cd(ch+1);
    
    sprintf(buf1, "a[%d]>>h%d(1000,0,4096)", ch, ch);
    
    T->Draw(buf1);
    gPad->SetLogy();
    c1->Modified();
  }

  c1->Print("adc.pdf");

}
