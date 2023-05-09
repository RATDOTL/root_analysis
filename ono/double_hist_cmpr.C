// This script file compares the results of two RUNs for each of TDC and ADC.

{
    //------------------- Input RUN data ----------------------//
    TFile *f0 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data/run007.root");
    TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data/run008.root");

    TCanvas* c1 = new TCanvas("c1","Result1",700,900);
    c1 -> Divide(1,2);

    //-------------------------- TDC --------------------------//
    c1 -> cd(1);
    f0 -> cd();
    T  -> Draw("t[1] - t[0] >> h0(100,0,1000)");
    h0 -> SetLineColor(2);
    h0 -> Draw();

    f1 -> cd();
    T  -> Draw("t[1] - t[0] >> h1(100,500,1000)","","same");
    h1 -> SetLineColor(4);
    h1 -> Draw("same");

    h0 -> Fit("gaus");
    h1 -> Fit("gaus");
    h0 -> Draw();
    h1 -> Draw("sames");


    //------------------------- ADC -------------------------//
    c1 -> cd(2);
    f0 -> cd();
    T  -> Draw("a[1] - a[0] >> h2(100,-500,500)");
    h2 -> SetLineColor(2);
    h2 -> Draw();

    f1 -> cd();
    T  -> Draw("a[1] - a[0] >> h3(100,-500,500)","","same");
    h3 -> SetLineColor(4);
    h3 -> Draw("same");

    h2 -> Fit("gaus");
    h3 -> Fit("gaus");
    h2 -> Draw();
    h3 -> Draw("sames");
}