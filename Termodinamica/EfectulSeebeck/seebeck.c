void seebeck(){
	gStyle->SetOptTitle(kFALSE);
	gStyle->SetOptStat(0);

	TH1F *grIncalzire = new TH1F("Efect Seebeck", "seebeck", 31, 0, 310);
	grIncalzire->SetMarkerStyle(kFullCircle);

	fstream fileIncalzire;
	fileIncalzire.open("dateIncalzire.txt", ios::in);

	while(1){
		double x, y;
		fileIncalzire >> x >> y;
		grIncalzire->Fill(x, y);
		if(fileIncalzire.eof()) break;
	}
	fileIncalzire.close();

	TH1F *grRacire = new TH1F("Efect Seebeck", "seebeck", 31, 0, 310);
	grRacire->SetMarkerStyle(kFullCrossX);

	fstream fileRacire;
	fileRacire.open("dateRacire.txt", ios::in);

	while(1){
		double x, y;
		fileRacire >> x >> y;
		grRacire->Fill(x, y);
		if(fileRacire.eof()) break;
	}
	fileRacire.close();

	// grIncalzire->Fit("pol1");
	grIncalzire->SetAxisRange(0, 310, "X");
	grIncalzire->SetAxisRange(0, 27, "Y");
	grIncalzire->GetXaxis()->SetTitle("t (C)");
	grIncalzire->GetYaxis()->SetTitle("U (mv)");
	grIncalzire->SetMarkerColor(8);
	grIncalzire->SetLineColor(8);
	grIncalzire->SetLineWidth(2);
	// grIncalzire->Scale(1);

	// grRacire->Fit("pol1");
	grRacire->SetAxisRange(0, 310, "X");
        grRacire->SetAxisRange(0, 27, "Y");
	grRacire->GetXaxis()->SetTitle("t (C)");
        grRacire->GetYaxis()->SetTitle("U (mv)");
	grRacire->SetMarkerColor(9);
	grRacire->SetLineColor(9);
	grRacire->SetLineWidth(2);
	grRacire->SetLineStyle(2);
	// grRacire->Scale(1);

	gStyle->SetEndErrorSize(4);

	TCanvas *c1 = new TCanvas();
	
	// grIncalzire->Draw("E1");
	// grRacire->Draw("E1 SAME");
	
	grIncalzire->Draw("HIST P");
	grRacire->Draw("HIST P SAME");
}
