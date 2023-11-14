{
    // TFile *f0 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run017.root");
    // TFile *f1 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run015.root");
    

    // TFile *f0 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas021.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas012.root");
    // TFile *f2 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas005.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_hal/hal00.root");


   
    // labo PC
    TFile *f0 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_don/don060.root");
    TFile *f1 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_don/don047.root");
    TFile *f2 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_don/don048.root");
    TFile *f3 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_don/don049.root");
    TFile *f4 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_don/don059.root");
    TFile *f5 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_spr/spr059.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_hal/hal00.root");
    
    
    
    f0->cd();
    // T->Draw("t[3]>>h0(100,1250,1800)");
    // T->Draw("a[0]>>h0");
    // c1->SetLogy();
    T->Draw("a[0]-1265>>h0(100,0,400)");
    // T->Draw("a[2]>>h0(100,1400,1600)");
    // T->Draw("a[3]>>h0(100,1250,1500)");

    // T->Draw("a[0]>>h0(100,1200,1600)","1000<t[0]&&t[0]<2000");

    // T->Draw("a[1]>>h0(100,1250,1600)","1000<t[1]&&t[1]<2000");

    // T->Draw("a[2]>>h0(100,1400,1550)","4000<t[2]&&t[2]<4500");

    // h0->Scale(h0->GetEntries()/h1->GetEntries());   

    h0->SetLineColor(2);
    h0->Draw();

    f1->cd();

    T->Draw("a[0]-1265>>h1(100,0,400)","","same histogram");
    // T->Draw("t[0]");
    // T->Draw("a[1]>>h1(100,1350,1450)","","same");
    // T->Draw("a[2]>>h1(100,0,1000)","","same");
    // T->Draw("a[3]>>h1(100,0,1000)"),"","same";

    // c1->SetLogy();

    
    // T->Draw("a[0]>>h1(100,1200,1600)","!(1000<t[0]&&t[0]<2000)","same");

    // T->Draw("a[1]>>h1(100,1250,1600)","!(1000<t[1]&&t[1]<2000)","same");

    // h1->Scale(h0->GetEntries()/h1->GetEntries());    

    // h1->Scale(h0->GetEntries()/h1->GetEntries());
    h1->SetLineColor(4);
    h1->Draw("same histogram");

    f2->cd();

    T->Draw("a[0]-1265>>h2(100,0,400)","","same histogram");
    // T->Draw("t[0]");
    // T->Draw("a[1]>>h1(100,1350,1450)","","same");
    // T->Draw("a[2]>>h1(100,0,1000)","","same");
    // T->Draw("a[3]>>h1(100,0,1000)"),"","same";

    // c1->SetLogy();

    
    // T->Draw("a[0]>>h1(100,1200,1600)","!(1000<t[0]&&t[0]<2000)","same");

    // T->Draw("a[1]>>h1(100,1250,1600)","!(1000<t[1]&&t[1]<2000)","same");

    // h1->Scale(h0->GetEntries()/h1->GetEntries());


    


    h2->SetLineColor(3);
    h2->Draw("same histogram");

    f3->cd();

    T->Draw("a[0]-1265>>h3(100,0,400)","","same histogram");
    // // // // T->Draw("a[0]>>h1(100,0,3000)","","same");

    // // T->Draw("a[0]>>h1(100,1100,2000)","","same");
    // // T->Draw("a[1]>>h1(100,1000,2500)","","same"); 

    // h2->Scale(h0->GetEntries()/h2->GetEntries());



    h3->SetLineColor(1);
    h3->Draw("same histogram");
    
    f4->cd();

    T->Draw("a[0]-1265>>h4(100,0,400)","","same histogram");
    // // // // T->Draw("a[0]>>h1(100,0,3000)","","same");

    // // T->Draw("a[0]>>h1(100,1100,2000)","","same");
    // // T->Draw("a[1]>>h1(100,1000,2500)","","same"); 

    // h2->Scale(h0->GetEntries()/h2->GetEntries());



    h4->SetLineColor(6);
    h4->Draw("same histogram");

    f5->cd();

    // T->Draw("a[4]-1375>>h5(100,0,400)","","same histogram");
    T->Draw("a[5]-1384>>h5(100,0,400)","","same histogram");
    // // // // T->Draw("a[0]>>h1(100,0,3000)","","same");

    // // T->Draw("a[0]>>h1(100,1100,2000)","","same");
    // // T->Draw("a[1]>>h1(100,1000,2500)","","same"); 
    
    // h2->Scale(h0->GetEntries()/h2->GetEntries());



    h5->SetLineColor(7);
    h5->Draw("same histogram");

    
    c1->SetLogy();
    c1->GetYaxis()->SetRangeUser(0, 10000);
    
//     // c1->Print("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/output/run013_015.pdf");
//     c1->Print("C:/Users/posei/Desktop/tokken/winscp/data_test/output/hal008_009_a[3].pdf");
    // c1->Print("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/output/output_don/don025(red)-033(blue)-036(green)-039(black)-030(pink)_a[0].png");
    // c1->Print("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/output/output_don/don060(red)-053(blue)-054(green)-055(black)_a[0].png");
    c1->Print("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/output/output_don/don060(red)-047(blue)-048(green)-049(black)-059(pink)_a[0]-spr059a[5](lightBlue).png");
}