{
    // TFile *f0 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run017.root");
    // TFile *f1 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run015.root");

    // data_hal
    TFile *f0 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_hal/hal005.root");
    TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_hal/hal003.root");
    

    f0->cd();
    // T->Draw("a[5]>>h0(100,1000,3000)");

    // T->Draw("a[0]>>h0(100,1200,1500)","1000<t[0]&&t[0]<3000");

    // T->Draw("a[1]>>h0(100,1000,2500)","1000<t[1]&&t[1]<3000");

    // T->Draw("a[4]>>h0(100,1200,3000)","1000<t[2]&&t[2]<3000");

    // T->Draw("a[5]>>h0(100,1200,3000)","1000<t[3]&&t[3]<3000");

    // T->Draw("t[0]>>h0(100,550,650)");
    // T->Draw("t[1]>>h1(100,0,5000)");
    // T->Draw("t[2]>>h1(100,0,5000)");
    // T->Draw("t[3]>>h1(100,0,5000)");

     
    h0->SetLineColor(2);
    h0->Draw();
    // h0->Fit("gaus");

    // f1->cd();
    // T->Draw("a[0]>>h1(100,0,5000)","","same");

    // // T->Draw("a[0]>>h1(100,1000,1500)","550<t[0]&&t[0]<650","same");
    // // T->Draw("a[1]>>h1(100,1200,1500)","900<t[1]&&t[1]<1500","same"); 
    // // T->Draw("a[1]>>h1(100,1200,1500)","","same"); //021



    // h1->SetLineColor(4);
    // h1->Draw("same");


    // c1->Print("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/output/run013_015.pdf");
    // c1->Print("C:/Users/posei/Desktop/tokken/winscp/data_test/output/hal003_005_a[0].pdf");
}