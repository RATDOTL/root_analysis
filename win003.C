{
    // TFile *f0 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run017.root");
    // TFile *f1 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run015.root");
    

    // TFile *f0 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas021.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas012.root");
    // TFile *f2 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas005.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_hal/hal00.root");



    // labo PC
    TFile *f0 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data_win/win003.root");
    // TFile *f1 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data_win/win001.root");
    // TFile *f2 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas005.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_hal/hal00.root");
    
    
    
    f0->cd();
    // T->Draw("a[0]>>h0(100,1200,1300)");
    // T->Draw("t[0]");
    // T->Draw("a[1]>>h0(100,1350,1450)");
    // T->Draw("a[2]>>h0(100,0,1000)");
    // T->Draw("a[3]>>h0(100,0,1000)");

    
    // T->Draw("a[0]>>h0(100,1200,1300)","0<t[0]&&t[0]<1000");
    // T->Draw("a[0]>>h0(100,1200,1300)","a[2]>1000");

    T->Draw("a[1]>>h0(100,1350,1450)","250<t[1]&&t[1]<450");
    // T->Draw("a[1]>>h0(100,1350,1450)","a[3]>450");

    // T->Draw("a[4]:a[6]>>h0(100,1200,3000,100,1200,3000)>");

    // T->Draw("a[5]>>h0(100,1200,3000)","400<t[3]&&t[3]<700");

    // T->Draw("t[0]>>h0(100,600,1500)");
    // T->Draw("t[1]>>h0(300,0,700)");
    // T->Draw("t[2]>>h0(300,1000,1500)");
    // T->Draw("t[3]>>h0(400,0,700)");

    // 角度分布
    // T->Draw("a[1]/a[0]:t[1]-t[0]>>h0(2000,-500,500)","500<t[0]&&t[0]<650&&300<t[1]&&t[1]<700");
    // T->Draw("a[1]/a[0]:t[1]-t[0]>>h0(100,-500,500)","500<t[0]&&t[0]<650");


    h0->SetLineColor(2);
    h0->Draw();

    f0->cd();
    // T->Draw("a[0]>>h1(100,1200,1300)","","same");
    // T->Draw("t[0]");
    // T->Draw("a[1]>>h1(100,1350,1450)","","same");
    // T->Draw("a[2]>>h1(100,0,1000)","","same");
    // T->Draw("a[3]>>h1(100,0,1000)"),"","same";

    
    // T->Draw("a[0]>>h1(100,1200,1300)","0<t[0]&&t[0]<1000","same");
    // T->Draw("a[0]>>h1(100,1200,1300)","t[0]>1000","same");

    // T->Draw("a[1]>>h1(100,1350,1450)","250<a[3]&&a[3]<450","same");
    T->Draw("a[1]>>h1(100,1350,1450)","t[1]>450","same");

    // // // // T->Draw("a[0]>>h1(100,0,3000)","","same");

    // // T->Draw("a[0]>>h1(100,1100,2000)","","same");
    // // T->Draw("a[1]>>h1(100,1000,2500)","","same"); 
    // // T->Draw("a[4]>>h1(100,1000,2500)","","same"); 

    // T->Draw("a[4]-1270>>h1(300,0,1500)","","same histogram"); 
    // h1->Scale(h0->GetEntries()/h1->GetEntries());



    h1->SetLineColor(4);
    h1->Draw("same");

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
    // c1->Print("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/output/win003_a[1].png");
// }