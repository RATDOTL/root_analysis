{

  //TFile *f0 = TFile::Open("run040.root");
  TChain* chain = new TChain("T");
  chain->Add("run039.root");
  chain->Add("run040.root");

  TCanvas *c1 = new TCanvas("c1", "", 0, 0, 600, 600);

  gPad->DrawFrame(0., 0., 1., 1.);

  char buf1[100], buf2[100];
 
  c1->Clear();
  c1->Draw();
  c1->Divide(2,3);
  
  for( int ch=0; ch<6; ch++){
   
  c1->cd(ch+1);
    
  //    sprintf(buf1, "a[%d]>>h%d(1000,0,5000)", ch, ch);
  sprintf(buf1, "a[%d]>>h%d(500,0,5000)", ch, ch);
    
   // gPad->SetLogy();
    //T->Draw(buf1, "a[0]>1500&&a[1]>1400");
    T->Draw(buf1 );
    c1->Modified();
  }

  c1->Print("adc040.pdf");

}
