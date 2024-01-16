{
    // TFile *f0 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run017.root");
    // TFile *f1 = TFile :: Open("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/data/run015.root");
    

    // TFile *f0 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas021.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas012.root");
    // TFile *f2 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_cas/cas005.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_hal/hal00.root");


   
    // labo PC
    TFile *f0 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_don/don081.root");
    // TFile *f1 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_don/don063.root");
    // TFile *f2 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_don/don059.root");
    // TFile *f3 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_don/don055.root");
    // TFile *f4 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_don/don059.root");
    // TFile *f5 = TFile :: Open("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/data/data_spr/spr059.root");
    // TFile *f1 = TFile :: Open("C:/Users/posei/Desktop/tokken/winscp/data_test/data_hal/hal00.root");
    
    
    
    f0->cd();
    // T->Draw("t[0]>>h0(100,1250,1800)");
    // T->Draw("a[0]>>h0");
    // c1->SetLogy();
    T->Draw("a[0]-1264.5>>h0(600,-100,500)");

    

    // h0->Scale(h0->GetEntries()/h1->GetEntries());   

    // h0->SetLineColor(2);
    h0->Draw();

    fitGaussians2(h0, 0, 300);

    
    c1->SetLogy();
    // c1->GetYaxis()->SetRangeUser(0, 1000000);
    
//     // c1->Print("/mnt/c/Users/posei/Desktop/tokken/winscp/data_test/output/run013_015.pdf");
//     c1->Print("C:/Users/posei/Desktop/tokken/winscp/data_test/output/hal008_009_a[3].pdf");
    // c1->Print("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/output/output_don/don025(red)-033(blue)-036(green)-039(black)-030(pink)_a[0].png");
    // c1->Print("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/output/output_don/don060(red)-053(blue)-054(green)-055(black)_a[0].png");
    // c1->Print("C:/Users/niiyama/Desktop/Kyotaro_Nishi/root/root_analysis/output/output_don/don069-gfit(PCfit)_a[0].png");
}

#include <TF1.h>
#include <TLine.h>

void fitGaussian(TH1F* hist, Double_t rangeMin, Double_t rangeMax) {
    // ガウスフィットの初期値を設定
    TF1 *fitFunc = new TF1("fitFunc", "gaus", rangeMin, rangeMax);
    fitFunc->SetParameter(0, hist->GetMaximum());  // Amplitude
    fitFunc->SetParameter(1, hist->GetMean());      // Mean
    fitFunc->SetParameter(2, hist->GetRMS());       // Sigma

    // ヒストグラムに対してガウスフィットを実行
    hist->Fit(fitFunc, "Q");

    // フィット結果を取得して表示
    Double_t amplitude = fitFunc->GetParameter(0);
    Double_t mean = fitFunc->GetParameter(1);
    Double_t sigma = fitFunc->GetParameter(2);

    // フィット結果の情報を描画
    TPaveText *fitInfo = new TPaveText(0.6, 0.7, 0.9, 0.9, "NDC");
    fitInfo->AddText(Form("Amplitude: %.2f", amplitude));
    fitInfo->AddText(Form("Mean: %.2f", mean));
    fitInfo->AddText(Form("Sigma: %.2f", sigma));
    fitInfo->SetFillColor(0);
    fitInfo->Draw();

    // ガウスフィットした関数を描画
    fitFunc->SetLineColor(4);  // 色を指定
    fitFunc->Draw("same");

    // 頂点の位置に縦に補助線を描画
    TLine *line = new TLine(mean, 0, mean, hist->GetMaximum());
    line->SetLineStyle(2);  // 破線
    line->Draw("same");

    delete fitFunc;
}

void fitGaussians1(TH1F* hist, Double_t rangeMin, Double_t rangeMax) {
    // ガウスフィットの初期値を設定
    TF1 *fitFunc = new TF1("fitFunc", "gaus(0) + gaus(3) + gaus(6)", rangeMin, rangeMax);

    // 各ガウスの初期値を設定
    fitFunc->SetParameter(0, hist->GetMaximum());  // Amplitude 1
    fitFunc->SetParameter(1, hist->GetMean());      // Mean 1
    fitFunc->SetParameter(2, hist->GetRMS());       // Sigma 1

    fitFunc->SetParameter(3, hist->GetMaximum());  // Amplitude 2
    fitFunc->SetParameter(4, 58); // Mean 2 
    fitFunc->SetParameter(5, 27.71);       // Sigma 2

    fitFunc->SetParameter(6, hist->GetMaximum());  // Amplitude 3
    fitFunc->SetParameter(7, 118); // Mean 3
    fitFunc->SetParameter(8, 27.71);       // Sigma 3

    // ヒストグラムに対してガウスフィットを実行
    hist->Fit(fitFunc, "Q");

    // 各フィット結果を取得して表示
    for (int i = 0; i < 3; ++i) {
        Double_t amplitude = fitFunc->GetParameter(i * 3);
        Double_t mean = fitFunc->GetParameter(i * 3 + 1);
        Double_t sigma = fitFunc->GetParameter(i * 3 + 2);

        // フィット結果の情報を描画
        TPaveText *fitInfo = new TPaveText(0.6, 0.7 - i * 0.2, 0.9, 0.9 - i * 0.2, "NDC");
        fitInfo->AddText(Form("Amplitude %d: %.2f", i + 1, amplitude));
        fitInfo->AddText(Form("Mean %d: %.2f", i + 1, mean));
        fitInfo->AddText(Form("Sigma %d: %.2f", i + 1, sigma));
        fitInfo->SetFillColor(0);
        fitInfo->Draw();

        // ガウスフィットした関数を描画
        fitFunc->SetLineColor(4 + i);  // 色を指定
        fitFunc->Draw("same");
    }

    delete fitFunc;
}

//変数固定をせずにフィット
void fitGaussians2(TH1F* hist, Double_t rangeMin, Double_t rangeMax) {

    // 合成関数の式を動的に構築
    Int_t npeaks = 4;  // 仮に3つのピークがあると仮定
    TString funcExpression = "0";
    for (Int_t i = 0; i < npeaks; ++i) {
        funcExpression += Form(" + gaus(%d)", i * 3);
    }

    // ガウスフィットの初期値を設定
    TF1 *fitFunc = new TF1("fitFunc", funcExpression.Data(), rangeMin, rangeMax);

    // 各ピークに対して初期値を手動で設定
    fitFunc->SetParameter(0, hist->GetBinContent(hist->FindBin(0)));  // Amplitude 1
    fitFunc->SetParameter(1, 0);  // Mean 1
    fitFunc->SetParameter(2, 3.0);  // Sigma 1

    fitFunc->SetParameter(3, hist->GetBinContent(hist->FindBin(52)));  // Amplitude 2
    fitFunc->SetParameter(4, 52);  // Mean 2
    fitFunc->SetParameter(5, 25.0);  // Sigma 2

    fitFunc->SetParameter(6, hist->GetBinContent(hist->FindBin(104)));  // Amplitude 3
    fitFunc->SetParameter(7, 104);  // Mean 3
    fitFunc->SetParameter(8, 25.0);  // Sigma 3

    fitFunc->SetParameter(9, hist->GetBinContent(hist->FindBin(104)));  // Amplitude 4
    fitFunc->SetParameter(10, 156);  // Mean 4
    fitFunc->SetParameter(11, 25.0);  // Sigma 4

    fitFunc->SetParameter(12, hist->GetBinContent(hist->FindBin(104)));  // Amplitude 4
    fitFunc->SetParameter(13, 156);  // Mean 4
    fitFunc->SetParameter(14, 25.0);  // Sigma 4

    // ヒストグラムに対してガウスフィットを実行
    hist->Fit(fitFunc, "Q");

    // フィット結果を取得して表示
    for (Int_t i = 0; i < npeaks; ++i) {
        Double_t amplitude = fitFunc->GetParameter(i * 3);
        Double_t mean = fitFunc->GetParameter(i * 3 + 1);
        Double_t sigma = fitFunc->GetParameter(i * 3 + 2);

        // フィット結果の情報を描画
        TPaveText *fitInfo = new TPaveText(0.6, 1.0 - i * 0.1, 0.9, 0.9 - i * 0.1, "NDC");
        fitInfo->SetTextSize(0.03);
        fitInfo->AddText(Form("Amplitude %d: %.2f", i + 1, amplitude));
        fitInfo->AddText(Form("Mean %d: %.2f", i + 1, mean));
        fitInfo->AddText(Form("Sigma %d: %.2f", i + 1, sigma));
        fitInfo->SetFillColor(0);
        fitInfo->Draw();

        // ガウスフィットした関数を描画
        fitFunc->SetLineColor(4 + i);  // 色を指定
        fitFunc->Draw("same");

        // 頂点の位置に縦に補助線を描画
        TLine *line = new TLine(mean, 0, mean, hist->GetMaximum());
        line->SetLineStyle(2);  // 破線
        line->Draw("same");
    }

    delete fitFunc;
}

//meanとsigmaを固定
void fitGaussians3(TH1F* hist, Double_t rangeMin, Double_t rangeMax) {

    // 合成関数の式を動的に構築
    Int_t npeaks = 4;  // 仮に3つのピークがあると仮定
    TString funcExpression = "0";
    for (Int_t i = 0; i < npeaks; ++i) {
        funcExpression += Form(" + gaus(%d)", i * 3);
    }

    // ガウスフィットの初期値を設定
    TF1 *fitFunc = new TF1("fitFunc", funcExpression.Data(), rangeMin, rangeMax);

    // 各ピークに対して初期値を手動で設定
    fitFunc->SetParameter(0, hist->GetBinContent(hist->FindBin(0)));  // Amplitude 1
    fitFunc->SetParameter(1, 0);  // Mean 1
    fitFunc->SetParameter(2, 3.0);  // Sigma 1

    fitFunc->SetParameter(3, hist->GetBinContent(hist->FindBin(52)));  // Amplitude 2
    fitFunc->SetParameter(4, 52);  // Mean 2
    fitFunc->SetParameter(5, 25.0);  // Sigma 2

    fitFunc->SetParameter(6, hist->GetBinContent(hist->FindBin(104)));  // Amplitude 3
    fitFunc->SetParameter(7, 104);  // Mean 3
    fitFunc->SetParameter(8, 25.0);  // Sigma 3

    fitFunc->SetParameter(9, hist->GetBinContent(hist->FindBin(104)));  // Amplitude 3
    fitFunc->SetParameter(10, 156);  // Mean 3
    fitFunc->SetParameter(11, 25.0);  // Sigma 3

    // Meanを固定
    fitFunc->FixParameter(1, 0);
    fitFunc->FixParameter(4, 70.48);
    fitFunc->FixParameter(7, 70.48 * 2);
    fitFunc->FixParameter(10, 70.48 * 3);

    // Sigmaを固定
    fitFunc->FixParameter(5, 33.19);
    fitFunc->FixParameter(8, 33.19);
    fitFunc->FixParameter(11, 33.19);

    // ヒストグラムに対してガウスフィットを実行
    hist->Fit(fitFunc, "Q");

    // フィット結果を取得して表示
    for (Int_t i = 0; i < npeaks; ++i) {
        Double_t amplitude = fitFunc->GetParameter(i * 3);
        Double_t mean = fitFunc->GetParameter(i * 3 + 1);
        Double_t sigma = fitFunc->GetParameter(i * 3 + 2);

        // フィット結果の情報を描画
        TPaveText *fitInfo = new TPaveText(0.6, 1.0 - i * 0.1, 0.9, 0.9 - i * 0.1, "NDC");
        fitInfo->SetTextSize(0.03);
        fitInfo->AddText(Form("Amplitude %d: %.2f", i + 1, amplitude));
        fitInfo->AddText(Form("Mean %d: %.2f", i + 1, mean));
        fitInfo->AddText(Form("Sigma %d: %.2f", i + 1, sigma));
        fitInfo->SetFillColor(0);
        fitInfo->Draw();

        // ガウスフィットした関数を描画
        fitFunc->SetLineColor(4 + i);  // 色を指定
        fitFunc->Draw("same");

        // 頂点の位置に縦に補助線を描画
        TLine *line = new TLine(mean, 0, mean, hist->GetMaximum());
        line->SetLineStyle(2);  // 破線
        line->Draw("same");
    }

    delete fitFunc;
}