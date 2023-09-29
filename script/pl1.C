{
    TFile *f0 = TFile::Open("run011.root");
    TCanvas* c1 = new TCanvas("c1","title",400,600);
    c1->Divide(1,2); 
    c1->cd(1);
    T->Draw("t[0]>>h0(1000,0,5000)"); 
    c1->cd(2); 
    T->Draw("a[1]>>h1(1000,0,5000)"); 
}