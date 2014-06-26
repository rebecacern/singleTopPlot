#include "TStyle.h"
#include "TPaveText.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TAxis.h"
#include "setTDRStyle.C"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

void readFile(const char * fileName, std::vector<double> & sqrts, std::vector<double> & sigma, unsigned int & len) {
  using namespace std;
  string line;
  double s, x;
  ifstream dataFile (fileName);
  if (dataFile.is_open()) {
    sqrts.clear(); sigma.clear();
    while (getline (dataFile, line) ) {
      stringstream ss(line);
      ss >> s >> x;
      sqrts.push_back(s);
      sigma.push_back(x);
    }
    dataFile.close();
    if (len > 0 && len != sqrts.size()) { cerr << "Inconsistend file size: " << len << "!=" << sqrts.size() << endl; exit(1); }
    if (len == 0) len = sqrts.size();
  }
  else { cerr << "Unable to open file: " << fileName << endl; exit(1); }
}

void full(){
  using namespace std;
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetErrorX(0);
  setTDRStyle();
  
  TPaveText * labelcms  = new TPaveText(0.12, 0.88, 0.5, 0.94, "NDCBR");
  labelcms->SetTextAlign(12);
  labelcms->SetTextSize(0.045);
  labelcms->SetFillColor(kWhite);
  labelcms->AddText("CMS Preliminary");
  labelcms->SetBorderSize(0);
  
  TPaveText * labelsingle  = new TPaveText(0.12,0.82,0.5,0.88,"NDCBR");
  labelsingle->SetTextAlign(12);
  labelsingle->SetTextSize(0.045);
  labelsingle->SetTextFont(42);
  labelsingle->SetFillColor(kWhite);
  labelsingle->AddText("Single top-quark production");
  labelsingle->SetBorderSize(0);
  
  TPaveText * labeltch  = new TPaveText(0.80,0.89,0.9,0.89,"NDCBR");
  labeltch->SetTextAlign(12);
  labeltch->SetTextSize(0.035);
  labeltch->SetTextFont(62);
  labeltch->SetTextColor(kBlue-8);
  labeltch->SetFillColor(kWhite);
  labeltch->AddText("t-channel");
  labeltch->SetBorderSize(0);
  
  TPaveText * labeltw  = new TPaveText(0.80,0.80,0.95,0.80,"NDCBR");
  labeltw->SetTextAlign(12);
  labeltw->SetTextSize(0.035);
  labeltw->SetTextFont(62);
  labeltw->SetTextColor(kCyan-5);
  labeltw->SetFillColor(kWhite);
  labeltw->AddText("tW");
  labeltw->SetBorderSize(0);
  
  TPaveText * labelsch  = new TPaveText(0.80,0.67,0.95,0.67,"NDCBR");
  labelsch->SetTextAlign(12);
  labelsch->SetTextSize(0.035);
  labelsch->SetTextFont(62);
  labelsch->SetTextColor(kRed-5);
  labelsch->SetFillColor(kWhite);
  labelsch->AddText("s-channel");
  labelsch->SetBorderSize(0);
  
  TCanvas * c1 = new TCanvas("c1", "", 200, 10, 800, 600);
  vector<double> sqrts, sigma;
  unsigned int len = 0;
  const unsigned int len_max = 100;
  double x[len_max]; 
  double sch_central[len_max], sch_upper[len_max], sch_lower[len_max];
  double tch_central[len_max], tch_upper[len_max], tch_lower[len_max];
  double tw_central[len_max], tw_upper[len_max], tw_lower[len_max];
  readFile("schNNLO172.5central.dat", sqrts, sigma, len);
  copy(sqrts.begin(), sqrts.end(), x);
  copy(sigma.begin(), sigma.end(), sch_central);
  readFile("schNNLO172.5upper.dat", sqrts, sigma, len); 
  copy(sigma.begin(), sigma.end(), sch_upper);
  readFile("schNNLO172.5lower.dat", sqrts, sigma, len);
  copy(sigma.begin(), sigma.end(), sch_lower);
  readFile("tchNNLO172.5central.dat", sqrts, sigma, len);
  copy(sigma.begin(), sigma.end(), tch_central);
  readFile("tchNNLO172.5upper.dat", sqrts, sigma, len);
  copy(sigma.begin(), sigma.end(), tch_upper);
  readFile("tchNNLO172.5lower.dat", sqrts, sigma, len);
  copy(sigma.begin(), sigma.end(), tch_lower);
  readFile("tWNNLO172.5central.dat", sqrts, sigma, len);
  copy(sigma.begin(), sigma.end(), tw_central);
  readFile("tWNNLO172.5upper.dat", sqrts, sigma, len);
  copy(sigma.begin(), sigma.end(), tw_upper);
  readFile("tWNNLO172.5lower.dat", sqrts, sigma, len);
  copy(sigma.begin(), sigma.end(), tw_lower);
			 
  double etch_lower[len_max], etch_upper[len_max], etw_lower[len_max], etw_upper[len_max], esch_lower[len_max], esch_upper[len_max];
  for (int i = 0; i < len; ++i){
    etch_lower[i] = tch_central[i] - tch_lower[i];
    etch_upper[i] = tch_upper[i] - tch_central[i];
    etw_lower[i] = tw_central[i] - tw_lower[i];
    etw_upper[i] = tw_upper[i] - tw_central[i];
    esch_lower[i] = sch_central[i] - sch_lower[i];
    esch_upper[i] = sch_upper[i] - sch_central[i];
  }

  TGraphAsymmErrors * gr = new TGraphAsymmErrors(len, x, tch_central, 0, 0, etch_lower, etch_upper);
  gr->SetMarkerColor(kBlue-10);
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(1);
  gr->SetLineColor(kBlue-8);
  gr->SetLineWidth(2);
  gr->SetFillColor(kBlue-10);
  gr->SetFillStyle(1001);
  
  TGraph * grl = new TGraph(len,x,tch_central);
  grl->SetMarkerColor(kBlue-8);
  grl->SetMarkerStyle(20);
  grl->SetMarkerSize(1);
  grl->SetLineColor(kBlue-8);
  grl->SetLineWidth(2);

  TGraphAsymmErrors* grtw = new TGraphAsymmErrors(len,x,tw_central,0,0, etw_lower, etw_upper);
  grtw->SetMarkerColor(kCyan-8);
  grtw->SetMarkerStyle(20);
  grtw->SetMarkerSize(1);
  grtw->SetLineColor(kCyan-5);
  grtw->SetLineWidth(2);
  grtw->SetFillColor(kCyan-8);
  grtw->SetFillStyle(1001);
  
  TGraph * grtwl = new TGraph(len,x,tw_central);
  grtwl->SetMarkerColor(kCyan-5);
  grtwl->SetMarkerStyle(20);
  grtwl->SetMarkerSize(1);
  grtwl->SetLineColor(kCyan-5);
  grtwl->SetLineWidth(2);
  
  TGraphAsymmErrors* grsch = new TGraphAsymmErrors(len,x,sch_central,0,0, esch_lower, esch_upper);
  grsch->SetMarkerColor(kRed-8);
  grsch->SetMarkerStyle(20);
  grsch->SetMarkerSize(1);
  grsch->SetLineColor(kRed-5);
  grsch->SetLineWidth(2);
  grsch->SetFillColor(kRed-8);
  grsch->SetFillStyle(1001);
  
  TGraph * grschl = new TGraph(len,x,sch_central);
  grschl->SetMarkerColor(kRed-5);
  grschl->SetMarkerStyle(20);
  grschl->SetMarkerSize(1);
  grschl->SetLineColor(kCyan-5);
  grschl->SetLineWidth(2);

  double tch_7TeV[1] = {67.2};
  double tch_7TeVerror[1] = {6.1};
  double tch_7TeVx[1] = {7};
 
  double tch_8TeV[1] = {83.6};
  double tch_8TeVerror[1] = {7.75};
  double tch_8TeVx[1] = {8};
  
  double tch_8TeV_comb[1] = {85};
  double tch_8TeVerror_comb[1] = {12};
  double tch_8TeVx_comb[1] = {8.1};
  
  double tw_7TeV[1] = {16};
  double tw_7TeVlow[1] = {4};
  double tw_7TeVup[1] = {5};
  double tw_7TeVx[1] = {7};
 
  double tw_8TeV[1] = {23.4};
  double tw_8TeVlow[1] = {5.4} ;
  double tw_8TeVup[1] = {5.5};
  double tw_8TeVx[1] = {8};
  /*  
  double sch_7TeV[1] = {16};
  double sch_7TeVlow[1] = {4};
  double sch_7TeVup[1] = {5};
  double sch_7TeVx[1] = {7};
  */
  double sch_8TeV[1] = {6.2};
  double sch_8TeVlow[1] = {5.1} ;
  double sch_8TeVup[1] = {8.0};
  double sch_8TeVx[1] = {8};
 
  const double markerSize = 1.2;
  TGraphAsymmErrors * gr_tch_7TeV = new TGraphAsymmErrors(1,tch_7TeVx,tch_7TeV,0,0, tch_7TeVerror, tch_7TeVerror);
  gr_tch_7TeV->SetMarkerColor(kBlue-6);
  gr_tch_7TeV->SetMarkerStyle(20);
  gr_tch_7TeV->SetMarkerSize(markerSize);
  gr_tch_7TeV->SetLineColor(kBlue-6);
  gr_tch_7TeV->SetLineWidth(3);
  
  TGraphAsymmErrors * gr_tch_8TeV = new TGraphAsymmErrors(1,tch_8TeVx,tch_8TeV,0,0, tch_8TeVerror, tch_8TeVerror);
  gr_tch_8TeV->SetMarkerColor(kBlue-6);
  gr_tch_8TeV->SetMarkerStyle(22);
  gr_tch_8TeV->SetMarkerSize(markerSize);
  gr_tch_8TeV->SetLineColor(kBlue-6);
  gr_tch_8TeV->SetLineWidth(3);
 
  TGraphAsymmErrors * gr_tch_8TeV_comb = new TGraphAsymmErrors(1,tch_8TeVx_comb,tch_8TeV_comb,0,0, tch_8TeVerror_comb, tch_8TeVerror_comb);
  gr_tch_8TeV_comb->SetMarkerColor(kMagenta);
  gr_tch_8TeV_comb->SetMarkerStyle(23);
  gr_tch_8TeV_comb->SetMarkerSize(markerSize);
  gr_tch_8TeV_comb->SetLineColor(kMagenta);
  gr_tch_8TeV_comb->SetLineWidth(3);
 
  TGraphAsymmErrors * gr_tw_7TeV = new TGraphAsymmErrors(1,tw_7TeVx,tw_7TeV,0,0, tw_7TeVlow, tw_7TeVup);
  gr_tw_7TeV->SetMarkerColor(kCyan-1);
  gr_tw_7TeV->SetMarkerStyle(24);
  gr_tw_7TeV->SetMarkerSize(markerSize);
  gr_tw_7TeV->SetLineColor(kCyan-1);
  gr_tw_7TeV->SetLineWidth(3);
  
  TGraphAsymmErrors * gr_tw_8TeV = new TGraphAsymmErrors(1,tw_8TeVx,tw_8TeV,0,0, tw_8TeVlow, tw_8TeVup);
  gr_tw_8TeV->SetMarkerColor(kCyan-1);
  gr_tw_8TeV->SetMarkerStyle(26);
  gr_tw_8TeV->SetMarkerSize(markerSize);
  gr_tw_8TeV->SetLineColor(kCyan-1);
  gr_tw_8TeV->SetLineWidth(3);
  
  /*
  TGraphAsymmErrors * gr_sch_7TeV = new TGraphAsymmErrors(1,sch_7TeVx,sch_7TeV,0,0, sch_7TeVlow, sch_7TeVup);
  gr_sch_7TeV->SetMarkerColor(kCyan-1);
  gr_sch_7TeV->SetMarkerStyle(24);
  gr_sch_7TeV->SetMarkerSize(markerSize);
  gr_sch_7TeV->SetLineColor(kCyan-1);
  gr_sch_7TeV->SetLineWidth(3);
  */
  
  TGraphAsymmErrors * gr_sch_8TeV = new TGraphAsymmErrors(1,sch_8TeVx,sch_8TeV,0,0, sch_8TeVlow, sch_8TeVup);
  gr_sch_8TeV->SetMarkerColor(kRed-1);
  gr_sch_8TeV->SetMarkerStyle(23);
  gr_sch_8TeV->SetMarkerSize(markerSize);
  gr_sch_8TeV->SetLineColor(kRed-1);
  gr_sch_8TeV->SetLineWidth(3);
  
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(gr);
  mg->Add(grtw);
  mg->Add(grsch);
  mg->Draw("AC3");
  
  TMultiGraph *mgl = new TMultiGraph();
  mgl->Add(grl);
  mgl->Add(grtwl);
  mgl->Add(grsch);
  mgl->Draw("L");
  
  TMultiGraph *mgd = new TMultiGraph();
  mgd->Add(gr_tch_7TeV);
  mgd->Add(gr_tch_8TeV);
  mgd->Add(gr_tw_7TeV);
  mgd->Add(gr_tw_8TeV);
  //  mgd->Add(gr_sch_7TeV);
  mgd->Add(gr_sch_8TeV);
  mgd->Draw("p");
  
  mg->GetYaxis()->SetRangeUser(0.01, 800); 
 
  c1->SetLogy();
  
  mg->GetXaxis()->SetTitle("#sqrt{s} [TeV]"); 
  mg->GetXaxis()->SetNdivisions(14,kTRUE); 
  mg->GetYaxis()->SetTitle("#sigma [pb]");
  //mg->GetYaxis()->CenterTitle();
  
  TLegend * leg = new TLegend(0.40,0.15,0.86,0.45);
  leg ->SetFillStyle(1001);
  leg ->SetFillColor(kWhite);
  leg ->SetTextSize(0.028);
  leg ->SetTextFont(42);
  leg ->SetBorderSize(0);
  leg->AddEntry(gr, "Approx. NNLO Kidonakis, PRD 83, 091503 (2011)", "cfl");
  leg->AddEntry(gr_tch_7TeV, "CMS, JHEP12(2012) 035", "p");
  leg->AddEntry(gr_tch_8TeV, "CMS, JHEP06(2014) 090", "p");
  leg->AddEntry(grtw, "Approx. NNLO Kidonakis, PRD 82, 054018 (2010)", "cfl");
  leg->AddEntry(gr_tw_7TeV, "CMS, Phys.Rev.Lett 110, 022003 (2013)", "p");
  leg->AddEntry(gr_tw_8TeV, "CMS, Phys.Rev.Lett.112, 231802 (2014)", "p");
  leg->AddEntry(grsch, "Approx. NNLO Kidonakis, PRD 81, 054028 (2010)", "cfl");
  //  leg->AddEntry(gr_sch_7TeV, "CMS, Phys.Rev.Lett 110, 022003 (2013)", "p");
  leg->AddEntry(gr_sch_8TeV, "CMS, PAS-TOP-13-009 (FC interval)", "p");
  leg->Draw();
  labelcms->Draw();
  labelsingle->Draw();
  labeltch->Draw();
  labeltw->Draw();
  labelsch->Draw();
  
  mg->GetXaxis()->SetLabelSize(0.04); 
  mg->GetXaxis()->SetTitleOffset(1.1); 
  mg->GetYaxis()->SetLabelSize(0.04); 
  c1->Update();
  c1->SaveAs("plots/singletopJune26.png");
  c1->SaveAs("plots/singletopJune26.pdf");
  c1->SaveAs("plots/singletopJune26.eps");
}
