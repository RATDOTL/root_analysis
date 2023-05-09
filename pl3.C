{
    TGraphErrors* tg1 =
    new TGraphErrors("data.dat","%lg %lg %lg %*lg %*lg");
    TGraphErrors* tg2 =
    new TGraphErrors("data.dat","%lg %*lg %*lg %lg %lg");
    tg1->Draw("ap"); 
    tg2->Draw("p");
    
    tg1->Fit("pol1"); 
    tg2->Fit("pol2");
    
}