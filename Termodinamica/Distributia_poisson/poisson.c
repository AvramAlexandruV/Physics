void poisson(){
	
	// h - histogram | 2 - dimension | f - floating point numbers
	
	gStyle->SetOptTitle(kFALSE);
	gStyle->SetOptStat(0);

	TH1F *histKc = new TH1F("Distributia Poisson", "Kc", 32, 0, 32);
        TH1F *histKe = new TH1F("Distributia Poisson", "Ke", 32, 0, 32);

	TF1 *f = new TF1("f", "[0] * TMath::Poisson((x/[2]), ([1]/[2]))", 0, 32);

	histKc->GetXaxis()->SetTitle("n");
	histKc->GetYaxis()->SetTitle("K");

	histKe->GetXaxis()->SetTitle("n");
	histKe->GetYaxis()->SetTitle("K");

	TCanvas *c1 = new TCanvas();

	histKc->SetAxisRange(2, 24, "X");
	histKc->SetAxisRange(0, 34, "Y");

	histKe->SetAxisRange(2, 24, "X");
	histKe->SetAxisRange(0, 34, "Y");

	// ----- Histograma pentru Ke ----- //

	float Kc[21] = { 0.12, 0.48, 1.38, 3.20, 6.20, 10.28, 14.90, 19.22, 22.28, 23.50, 22.72, 22.28, 16.80, 12.98, 9.42, 6.42, 4.14, 2.52, 1.46, 0.82, 0.42 };

	for(int i = 0; i < 21; i++){
		histKc->Fill(i + 2, Kc[i]);
		std::cout<<"(" << i+2 << " " << Kc[i] << ")" << '\n';
	}
	
	// histKc->SetLineStyle(10);
	
	histKc->SetMarkerStyle(26);
	histKc->SetLineColor(9);
	histKc->SetLineWidth(2);

	// ----- Histograma pentru Kc ----- //
	
	float Ke[21] = { 0, 0, 2, 4, 7, 9, 22, 18, 31, 2, 22, 18, 13, 17, 10, 6, 6, 2, 5, 1, 2 };

	for(int i = 0; i < 21; i++){
		histKe->Fill(i + 2, Ke[i]);
		std::cout<<"(" << i+2 << " " << Ke[i] << ")" << '\n';
	}

	// histKe->SetLineStyle(10);
	
	histKe->SetMarkerStyle(29);
	histKe->SetLineColor(1);
	histKe->SetLineWidth(2);
	 

	// Fitting the histogram to the Poisson function
	 
	// histKe->Fit("f", "S");
	// histKc->Fit("f", "S");
	
	// Draw histograms
	
	// histKc->Draw("HIST ");
	// histKe->Draw("HIST SAME");

	// Draw only points
	
	// histKc->Draw("HIST P");
        // histKe->Draw("HIST P SAME");

	// Draw connected points

	histKc->Draw("HIST L P");
	histKe->Draw("HIST L P SAME");
	
	c1->SaveAs("distributia_poisson.pdf");
}
