// This script file compares the results of two RUNs.

{
    //--------------------- first data ---------------------//
    TFile *f0 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data/run011.root");
    TCanvas* c1 = new TCanvas("c1","Result1",400,600);
    f0 -> cd();
    c1 -> Divide(1,2);
    c1 -> cd(1);
    T  -> Draw("t[1] - t[0] >> h0(100,0,1000)");
    h0 -> Fit("gaus");
    c1 -> cd(2); // Go to lower canvas
    T  -> Draw("a[1] - a[0] >> h1(100,-500,500)");
    h1 -> Fit("gaus");
    c1 -> Draw();

    //--------------------- second data ---------------------//
    TFile *f1 = TFile :: Open("run008.root");
    TCanvas* c2 = new TCanvas("c2","Result2",400,600);
    f1 -> cd();
    c2 -> Divide(1,2);
    c2 -> cd(1);
    T  -> Draw("t[1] - t[0] >> h2(100,0,1000)");
    h2 -> Fit("gaus");
    c2 -> cd(2); // Go to lower canvas
    T  -> Draw("a[1] - a[0] >> h3(100,-500,500)");
    h3 -> Fit("gaus");
    c2 -> Draw();
}