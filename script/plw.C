{

  TFile *file0 = TFile::Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data/run014.root");
  TFile *file1 = TFile::Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data/run013.root");

  file0->cd();
  T->Draw("a[1]>>h07(200,1000,1600)","");
  h07->SetLineColor(2);

  file1->cd();
  T->Draw("a[1]>>h12(200,1000,1600)","");
  h12->Scale(0.1);

  file1->cd();
  h12->Draw("");
  h12->Draw("same histogram");
  file0->cd();
  h07->Draw("same");

}
