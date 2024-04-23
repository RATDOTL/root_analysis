{
    // TFile *f0 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run017.root");
    // TFile *f1 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run015.root");
    

    // TFile *f0 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas021.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas012.root");
    // TFile *f2 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas005.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_hal/hal00.root");



    // labo PC
    TFile *f0 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_wintest/test002.root");
    // TFile *f1 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_wintest/win012.root");
    // TFile *f2 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas005.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_hal/hal00.root");


    f0->cd();
    // T->Draw("t[1]>>h0(100,600,700)");
    // T->Draw("a[1]");
    // T->Draw("a[1]>>h0(100,1300,1500)");
    // T->Draw("a[2]>>h0(100,0,1000)");
    // T->Draw("a[3]>>h0(100,0,1000)");

    
    T->Draw("a[0]>>h0(100,1200,1600)","320<=t[0]&&t[0]<=360");
    // T->Draw("a[1]>>h0(100,1250,1800)","t[1]<=700");


    h0->SetLineColor(2);
    h0->Draw();

    f1->cd();
    // T->Draw("a[0]>>h1(100,1250,1500)","","same hiestogram");
    // T->Draw("t[0]");
    // T->Draw("a[1]>>h1(100,1350,1450)","","same");
    // T->Draw("a[2]>>h1(100,0,1000)","","same");
    // T->Draw("a[3]>>h1(100,0,1000)"),"","same";

    
    T->Draw("a[0]>>h1(100,1200,1600)","!(320<=t[0]&&t[0]<=360)","same histogram");
    // T->Draw("a[1]>>h1(100,1250,1800)","!(t[1]<=700)","same histogram");

    // // // // T->Draw("a[0]>>h1(100,0,3000)","","same");

    // // T->Draw("a[0]>>h1(100,1100,2000)","","same");
    // // T->Draw("a[1]>>h1(100,1000,2500)","","same"); 
    // // T->Draw("a[4]>>h1(100,1000,2500)","","same"); 

    // T->Draw("a[4]-1270>>h1(300,0,1500)","","same histogram"); 
    // h1->Scale(h0->GetEntries()/h1->GetEntries());



    h1->SetLineColor(4);
    h1->Draw("same histogram");

    // f2->cd();
    // // // // T->Draw("a[0]>>h1(100,0,3000)","","same");

    // // T->Draw("a[0]>>h1(100,1100,2000)","","same");
    // // T->Draw("a[1]>>h1(100,1000,2500)","","same"); 
    // // T->Draw("a[4]>>h1(100,1000,2500)","","same"); 
    // T->Draw("a[6]>>h2(200,1200,1600)","","same histogram"); 
    // h2->Scale(h0->GetEntries()/h2->GetEntries());



    // h2->SetLineColor(6);
    // h2->Draw("same histogram");


//     // c1->Print("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/output/run013_015.pdf");
//     c1->Print("C:/Users/posei/Desktop/tokken/winscp/data_test/output/hal008_009_a[3].pdf");
    // c1->Print("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/output/win011_a[0].png");
// }