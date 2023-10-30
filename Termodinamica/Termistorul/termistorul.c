void termistorul(){
	TCanvas *c1 = new TCanvas("c1","Rezistenta in functie de temperatura",200,10,700,500);
	c1->SetGrid();

	Int_t n = 16;
	Float_t x[] = { 33.7, 33.5, 32.9, 32.4, 31.9, 31.4, 30.9, 30.4, 30.0, 29.5, 29.1, 28.7, 28.3, 27.9, 27.5, 27.1 };
	Float_t y[] = { 8.35, 8.12, 8.06, 7.92, 7.79, 7.67, 6.97, 6.89, 6.85, 6.73, 6.62, 6.50, 6.40, 6.33, 6.23, 6.11 };


	TGraph *gr = new TGraph(n,x,y);
	gr->Draw("A*");
	gr->Fit("pol1");

	gr->GetXaxis()->SetTitle("1/T [K^-1] * 10^-4");
	gr->GetYaxis()->SetTitle("lnR");
	gr->SetTitle("Termistorul : ln R in functie de temperatura");

	Double_t slope = gr->GetFunction("pol1")->GetParameter(1) * 10000;
	cout << "Panta este: " << slope << "K" << '\n';

	Double_t deltaE = 2*slope*8.6*0.00001;
cout << "Lungimea bandei interzise este: " << deltaE << "eV" << '\n';

	c1->SaveAs("termistorul.pdf");
}
