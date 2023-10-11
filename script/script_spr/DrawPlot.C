{

	TH1D * hADC[8];
	TH1D * hTDC[8];

	char hname[255];

	for(int i=0; i<8; i++){
		sprintf(hname,"hADC_%02d",i);
		hADC[i] = new TH1D(hname,hname,100,0,2500);
		sprintf(hname,"hTDC_%02d",i);
		hTDC[i] = new TH1D(hname,hname,100,0,4500);

	}

	float a[8];
	float t[8];


	TChain * chain = new TChain("T");
	chain->LoadTree(0);
	chain->Add("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_spr/spr022.root");
	chain->SetBranchAddress("a",a);
	chain->SetBranchAddress("t",t);

	for(int iEvent=0; iEvent<chain->GetEntries(); iEvent++){
		if(iEvent%100==0) cout<<iEvent<<" events"<<endl;
		chain->GetEntry(iEvent);
		
		for(int ch=0; ch<8; ch++){
			hADC[ch]->Fill(a[ch]);
			hTDC[ch]->Fill(t[ch]);
		}

	}



	gROOT->SetStyle("Plain");


	TCanvas * c0 = new TCanvas("c0","c0",1200,700);
	c0->Divide(4,2);

	for(int i=0; i<8; i++){
		c0->cd(i+1);
		hADC[i]->Draw();
	}


	TCanvas * c1 = new TCanvas("c1","c1",1200,700);
	c1->Divide(4,2);

	for(int i=0; i<8; i++){
		c1->cd(i+1);
		hTDC[i]->Draw();
	}

// c0->Print("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/output/output_spr/spr027_ADC_HV(2000).png");
// c1->Print("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/output/output_spr/spr027_TDC_HV(2000).png");
}

