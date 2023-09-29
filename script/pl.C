{
    TFile *f0 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run015.root");
    // T->Draw("t[0]-t[1]>>h3(100,1000,420)","t[0]>280 && t[1]>0");
    T->Draw("a[1]>>h1(1000,0,1400)");
    // f0->Fit("gaus");
    // c1->Print("C:/Users/posei/Desktop/tokken/winscp/data_test/output/run008.pdf");
}