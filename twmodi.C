#include "setTDRStyle.C"

void twmodi(){

  
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetErrorX(0);
  setTDRStyle();
  
  labelcms  = new TPaveText(0.12,0.88,0.5,0.94,"NDCBR");
  labelcms->SetTextAlign(12);
  labelcms->SetTextSize(0.045);
  labelcms->SetFillColor(kWhite);
  labelcms->AddText("CMS Preliminary");
  labelcms->SetBorderSize(0);
  
  labelsingle  = new TPaveText(0.12,0.82,0.5,0.88,"NDCBR");
  labelsingle->SetTextAlign(12);
  labelsingle->SetTextSize(0.045);
  labelsingle->SetTextFont(42);
  labelsingle->SetFillColor(kWhite);
  labelsingle->AddText("Single top, tW associated production");
  labelsingle->SetBorderSize(0);
  
  
  
  c1 = new TCanvas("c1","",200,10,700,500);


  double lx[25]  = {2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10, 10.5, 11, 11.5, 12, 12.5, 13, 13.5, 14};
  double ltch_central[25] = {0.2267E+01,
			     0.4776E+01,
			     0.8278E+01,
			     0.1288E+02,
			     0.1842E+02,
			     0.2471E+02,
			     0.3226E+02,
			     0.3991E+02,
			     0.4807E+02,
			     0.5721E+02,
			     0.6615E+02,
			     0.7749E+02,
			     0.8761E+02,
			     0.9904E+02,
			     0.1108E+03,
			     0.1231E+03,
			     0.1353E+03,
			     0.1487E+03,
			     0.1619E+03,
			     0.1757E+03,
			     0.1895E+03,
			     0.2052E+03,
			     0.2194E+03,
			     0.2338E+03,
			     0.2488E+03};
  
  double ltch_upper[25] ={0.2403E+01,
			  0.5015E+01,
			  0.8642E+01,
			  0.1342E+02,
			  0.1918E+02,
			  0.2570E+02,
			  0.3355E+02,
			  0.4151E+02,
			  0.4999E+02,
			  0.5950E+02,
			  0.6880E+02,
			  0.8136E+02,
			  0.9094E+02,
			  0.1028E+03,
			  0.1149E+03,
			  0.1277E+03,
			  0.1402E+03,
			  0.1541E+03,
			  0.1674E+03,
			  0.1817E+03,
			  0.1958E+03,
			  0.2120E+03,
			  0.2266E+03,
			  0.2408E+03,
			  0.2565E+03};
  
  double ltch_lower[25]={0.2127E+01,
			 0.4518E+01,
			 0.7897E+01,
			 0.1236E+02,
			 0.1773E+02,
			 0.2385E+02,
			 0.3120E+02,
			 0.3865E+02,
			 0.4662E+02,
			 0.5550E+02,
			 0.6423E+02,
			 0.7529E+02,
			 0.8515E+02,
			 0.9627E+02,
			 0.1078E+03,
			 0.1198E+03,
			 0.1316E+03,
			 0.1447E+03,
			 0.1575E+03,
			 0.1710E+03,
			 0.1844E+03,
			 0.1996E+03,
			 0.2135E+03,
			 0.2275E+03,
			 0.2421E+03};
  
  double ltw_central[25]= {0.1880E+00,
			   0.5040E+00,
			   0.1042E+01,
			   0.1839E+01,
			   0.2920E+01,
			   0.4292E+01,
			   0.5968E+01,
			   0.7958E+01,
			   0.1025E+02,
			   0.1283E+02,
			   0.1574E+02,
			   0.1890E+02,
			   0.2244E+02,
			   0.2614E+02,
			   0.3018E+02,
			   0.3448E+02,
			   0.3906E+02,
			   0.4396E+02,
			   0.4886E+02,
			   0.5424E+02,
			   0.5982E+02,
			   0.6562E+02,
			   0.7170E+02,
			   0.7788E+02,
			   0.8418E+02};
  
  double ltw_upper[25] = {0.2238E+00,
			  0.5846E+00,
			  0.1187E+01,
			  0.2066E+01,
			  0.3247E+01,
			  0.4734E+01,
			  0.6541E+01,
			  0.8669E+01,
			  0.1112E+02,
			  0.1386E+02,
			  0.1691E+02,
			  0.2028E+02,
			  0.2398E+02,
			  0.2789E+02,
			  0.3213E+02,
			  0.3664E+02,
			  0.4143E+02,
			  0.4656E+02,
			  0.5165E+02,
			  0.5727E+02,
			  0.6306E+02,
			  0.6912E+02,
			  0.7543E+02,
			  0.8187E+02,
			  0.8820E+02};

  double ltw_lower[25] = {0.1522E+00,
			  0.4234E+00,
			  0.8969E+00,
			  0.1612E+01,
			  0.2593E+01,
			  0.3850E+01,
			  0.5395E+01,
			  0.7247E+01,
			  0.9384E+01,
			  0.1180E+02,
			  0.1453E+02,
			  0.1752E+02,
			  0.2091E+02,
			  0.2439E+02,
			  0.2823E+02,
			  0.3232E+02,
			  0.3669E+02,
			  0.4136E+02,
			  0.4607E+02,
			  0.5121E+02,
			  0.5658E+02,
			  0.6212E+02,
			  0.6797E+02,
			  0.7389E+02,
			  0.7994E+02};
  
  double tch_central[7], tw_central[7], tch_lower[7], tch_upper[7], tw_lower[7], tw_upper[7], x[7];
  int j = 0;
  for (int i = 0; i< 7; i++){
    j = i + 8;
    
    tch_central[i]= ltch_central[j];
    tw_central[i]= ltw_central[j];
    tch_upper[i]= ltch_upper[j];
    tw_upper[i]= ltw_upper[j];
    tch_lower[i]= ltch_lower[j];
    tw_lower[i]= ltw_lower[j];
    x[i] = lx[j];
  }
  
  
  double etch_lower[7], etch_upper[7], etw_lower[7], etw_upper[7];
  for (int i=0; i< 7; i++){
    etch_lower[i] = tch_central[i]-tch_lower[i];
    etch_upper[i] = tch_upper[i]-tch_central[i];
    etw_lower[i] = tw_central[i]-tw_lower[i];
    etw_upper[i] = tw_upper[i]-tw_central[i];
  }

  // create the TGraphErrors and draw it
  gr = new TGraphAsymmErrors(7,x,tch_central,0,0, etch_lower, etch_upper);
  gr->SetMarkerColor(kBlue-10);
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(1);
  gr->SetLineColor(kBlue-8);
  gr->SetLineWidth(2);
  gr->SetFillColor(kBlue-10);
  gr->SetFillStyle(1001);
  
  grl = new TGraph(7,x,tch_central);
  grl->SetMarkerColor(kBlue-8);
  grl->SetMarkerStyle(20);
  grl->SetMarkerSize(1);
  grl->SetLineColor(kBlue-8);
  grl->SetLineWidth(2);
 

  grtw = new TGraphAsymmErrors(7,x,tw_central,0,0, etw_lower, etw_upper);
  grtw->SetMarkerColor(kCyan-8);
  grtw->SetMarkerStyle(20);
  grtw->SetMarkerSize(1);
  grtw->SetLineColor(kCyan-5);
  grtw->SetLineWidth(2);
  grtw->SetFillColor(kCyan-8);
  grtw->SetFillStyle(1001);
  
  
  grtwl = new TGraph(7,x,tw_central);
  grtwl->SetMarkerColor(kCyan-5);
  grtwl->SetMarkerStyle(20);
  grtwl->SetMarkerSize(1);
  grtwl->SetLineColor(kCyan-5);
  grtwl->SetLineWidth(2);
  

  double tch_7TeV[1] = {67.2};
  double tch_7TeVerror[1] = {6.1};
  double tch_7TeVx[1] = {7};
 
  double tch_8TeV[1] = {80.1};
  double tch_8TeVerror[1] = {13.0};
  double tch_8TeVx[1] = {8};
  
  double tw_7TeV[1] = {16};
  double tw_7TeVlow[1] = {4};
  double tw_7TeVup[1] = {5};
  double tw_7TeVx[1] = {7};
 
  double tw_8TeV[1] = {23.4};
  double tw_8TeVlow[1] = {5.4} ;
  double tw_8TeVup[1] = {5.5};
  double tw_8TeVx[1] = {8};
 
  gr_tch_7TeV = new TGraphAsymmErrors(1,tch_7TeVx,tch_7TeV,0,0, tch_7TeVerror, tch_7TeVerror);
  gr_tch_7TeV->SetMarkerColor(kBlue-6);
  gr_tch_7TeV->SetMarkerStyle(20);
  gr_tch_7TeV->SetMarkerSize(2);
  gr_tch_7TeV->SetLineColor(kBlue-6);
  gr_tch_7TeV->SetLineWidth(3);
  
  gr_tch_8TeV = new TGraphAsymmErrors(1,tch_8TeVx,tch_8TeV,0,0, tch_8TeVerror, tch_8TeVerror);
  gr_tch_8TeV->SetMarkerColor(kBlue-6);
  gr_tch_8TeV->SetMarkerStyle(22);
  gr_tch_8TeV->SetMarkerSize(2);
  gr_tch_8TeV->SetLineColor(kBlue-6);
  gr_tch_8TeV->SetLineWidth(3);
 
  gr_tw_7TeV = new TGraphAsymmErrors(1,tw_7TeVx,tw_7TeV,0,0, tw_7TeVlow, tw_7TeVup);
  gr_tw_7TeV->SetMarkerColor(kCyan-1);
  gr_tw_7TeV->SetMarkerStyle(24);
  gr_tw_7TeV->SetMarkerSize(2);
  gr_tw_7TeV->SetLineColor(kCyan-1);
  gr_tw_7TeV->SetLineWidth(3);
  
  gr_tw_8TeV = new TGraphAsymmErrors(1,tw_8TeVx,tw_8TeV,0,0, tw_8TeVlow, tw_8TeVup);
  gr_tw_8TeV->SetMarkerColor(kCyan-1);
  gr_tw_8TeV->SetMarkerStyle(26);
  gr_tw_8TeV->SetMarkerSize(2);
  gr_tw_8TeV->SetLineColor(kCyan-1);
  gr_tw_8TeV->SetLineWidth(3);
  
  TMultiGraph *mg = new TMultiGraph();
  //mg->Add(gr);
  mg->Add(grtw);
  mg->Draw("AC3");
  
  TMultiGraph *mgl = new TMultiGraph();
  // mgl->Add(grl);
  mgl->Add(grtwl);
  mgl->Draw("L");
  
  TMultiGraph *mgd = new TMultiGraph();
  // mgd->Add(gr_tch_7TeV);
  // mgd->Add(gr_tch_8TeV);
  mgd->Add(gr_tw_7TeV);
  mgd->Add(gr_tw_8TeV);
  mgd->Draw("p");
  
  mg->GetYaxis()->SetRangeUser(1,100); 
 
  c1->SetLogy();
  
  mg->GetXaxis()->SetTitle("Center of mass energy, #sqrt{s} [TeV]"); 
  mg->GetXaxis()->SetNdivisions(14,kTRUE); 
  mg->GetYaxis()->SetTitle("Production cross-section, #sigma [pb]");
  mg->GetYaxis()->CenterTitle();
  
  leg = new TLegend(0.35,0.15,0.8,0.4);
  leg ->SetFillStyle(1001);
  leg ->SetFillColor(kWhite);
  leg ->SetTextSize(0.035);
  leg ->SetTextFont(42);
  leg ->SetBorderSize(0);
  leg ->SetHeader("tW associated production");
  /*leg->AddEntry(gr, "NNLO Kidonakis [arXiv:1210.7813]", "cfl");
    leg->AddEntry(gr_tch_7TeV, "CMS, 1.17 (#mu) / 1.56(e) fb^{-1} JHEP12(2012) 035", "p");
    leg->AddEntry(gr_tch_8TeV, "CMS, 5.0 fb^{-1} (#mu), PAS-TOP-12-011", "p");*/
  leg->AddEntry(grtw, "NNLO Kidonakis [arXiv:1210.7813]", "cfl");
  leg->AddEntry(gr_tw_7TeV, "CMS, 4.9 fb^{-1}, Phys.Rev.Lett 110, 022003 (2013)", "p");
  leg->AddEntry(gr_tw_8TeV, "CMS,12.2 fb^{-1}, PAS-TOP-12-040", "p");
  leg->Draw();
  labelcms->Draw();
  labelsingle->Draw();
 
  
  mg->GetYaxis()->SetRangeUser(5, 50); 
  mg->GetXaxis()->SetNdivisions(4,kTRUE); 
  c1->Update();
  c1->SaveAs("plots/tw_modi.png");

}
