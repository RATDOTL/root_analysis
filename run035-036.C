{
    // TFile *f0 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run017.root");
    // TFile *f1 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run015.root");

    // data_run
    TFile *f0 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_run/run035.root");
    TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_run/run036.root");

    f0->cd();

    // T->Draw("a[1]>>h0(100,1100,1500)");

    // T->Draw("a[0]>>h0(100,1200,1600)","800<t[0]&&t[0]<1200"); //
    T->Draw("a[1]>>h0(100,1100,1500)","1300<t[1]&&t[1]<1350"); //021
    
    
    // T->Draw("t[0]>>h0(100,800,1200)");
    // T->Draw("t[1]>>h0(100,1300,1350)"); 

    
    h0->SetLineColor(2);
    h0->Draw();
    // h0->Fit("gaus");

    f1->cd();
    // T->Draw("a[0]>>h1(100,1200,1600)","","same"); //020
    T->Draw("a[1]>>h1(100,1100,1500)","","same"); //021
    // // T->Draw("a[1]>>h1(100,1200,1500)","","same"); //021

    // T->Draw("t[1]>>h0(100,1000,2000)"); 


    h1->SetLineColor(4);
    h1->Draw("same");


    // c1->Print("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/output/run013_015.pdf");
    c1->Print("C:/Users/posei/Desktop/tokken/winscp/data_test/output/run035-036_a[1].pdf");
}