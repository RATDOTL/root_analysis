// This script file outputs both TDC and ADC results for a single RUN and fits them with a Gaussian.

{
    TFile *f0 = TFile :: Open("run008.root");

    TCanvas* c1 = new TCanvas("c1","Result",400,600); // Open canavs. Canvus resolution is (400, 600).

    c1 -> Divide(1,2); // Split canvus vertically

    c1 -> cd(1);
    T  -> Draw("t[1] - t[0] >> h0(100,500,800)");   // 
    c1 -> cd(2); // Go to lower canvas
    T  -> Draw("a[1] - a[0] >> h1(100,-1000,1000)");

    h0 -> Fit("gaus");
    h1 -> Fit("gaus");


    //------------- Show graph -------------//
    c1 -> Draw();
    c1 -> Update();
}