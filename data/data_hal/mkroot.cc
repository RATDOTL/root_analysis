int mkroot(int hal){

  char filename[500];
  char ifilename[500], ofilename[500];
  sprintf(filename, "hal%03d", hal);
  sprintf(ifilename, "./%s.dat", filename); //入力データファイル名を指
  sprintf(ofilename, "./%s.root", filename); //出力ファイル名を指定

  // ====== Create new ROOT file =========
  TFile* ofile = new TFile(ofilename, "recreate"); //出力ファイルを生成
  TTree* tnew = new TTree("T", "adc_tdc");   // tree を準備
  
  Int_t halid, evid = 0;
  const int num_channel = 8;
  Float_t a[num_channel], t[num_channel];

  tnew->Branch("halid", &halid, "halid/I"); //Tree のブランチ(枝)に halid を登録
  tnew->Branch("evid", &evid, "evid/I");//Tree のブランチ(枝)に イベント番号 を登録
  tnew->Branch("a", a, "a[8]/F"); //Tree のブランチ(枝)に ADC (a[0], a[1], ..., a[7])を登録
  tnew->Branch("t", t, "t[8]/F"); //Tree のブランチ(枝)に TDC (t[0], t[1], ..., t[7])を登録

  // ===== Open input data file ==============  
  ifstream* ifile = new ifstream(ifilename);
  if(!*ifile) {
    cout << "not found input file :" << ifilename << endl;
    exit(1); //ファイルを開けなければ終了
  }

  while(!ifile->eof()) { //ファイルの最後までループを回す
    halid = hal; // halid は与えられた hal 番号を代入
    for(int i = 0; i < num_channel; i++) *ifile >> a[i]; //入力データの最初の8つの数字を ADC (配列 a[0],...,a[7])に代入
    for(int i = 0; i < num_channel; i++) *ifile >> t[i]; //入力データの最初の8つの数字を TDC (配列 t[0],...,t[7])に代入

    tnew->Fill(); // tree にこのイベントのデータを詰める。
    evid++; // イベント番号を1増やす。
  }

  // ===== write data to tree =============
  tnew->Write();
  ofile->Close();

  cout << "input file:"  << ifilename << " --> "
       << "output file:" << ofilename << endl;

  return 0;
  
}
