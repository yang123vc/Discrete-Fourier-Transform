#include <iostream>
#include <fstream>
#include <string>

#include <cmath>
#include <cstdlib>
//#include <cstring>

#include "DiscreteFourierAnalysis.h"

using namespace std;

int main(int argc, char* argv[])
{
   double junk, junk1;
   vector<double> reSignal;
   string fileName = argv[1];
   
   //Read in Data
   ifstream inputFile;
   inputFile.open (fileName.c_str());
   if(inputFile.is_open()) {
      while(inputFile.good()) {
	 double temp = 0;
	 inputFile >> junk >> temp >> junk1;
	 reSignal.push_back(temp);
      }
   }else {
      cout << "Unable to open input file.  Exiting...." << endl;
      exit(2);
   }
   inputFile.close();

   DiscreteFourierAnalysis dft;
   dft.SetReSig(reSignal);
   
   dft.DoTransform();
   dft.DoInverseTransform();
   
   vector<double> *reTrans  = dft.GetReTrans();
   vector<double> *imTrans  = dft.GetImTrans();
   vector<double> *modTrans = dft.GetModTrans();
   
   vector<double> *reInv  = dft.GetReInv();
   vector<double> *imInv  = dft.GetImInv();
   vector<double> *modInv = dft.GetModInv();
   
   ofstream outputTrans;
   outputTrans.open("trans.dat");
   if(outputTrans.is_open()) {
   for(unsigned int a = 0; a < reTrans->size(); a++)
      outputTrans << a << " " << reTrans->at(a) << " " 
	   << imTrans->at(a) << " " << modTrans->at(a) << endl;
   }else {
      cout << "Unable to open output file for Transform.  Exiting...." << endl;
      exit(2);
   }
   outputTrans.close();

   ofstream outputInv;
   outputInv.open("inv.dat");
   if(outputInv.is_open()) {
      for(unsigned int a = 0; a < reInv->size(); a++)
	 outputInv << a << " " << reInv->at(a) << " " 
		   << imInv->at(a) << " " << modInv->at(a) << endl;
   }else {
      cout << "Unable to open output file for Inverse Transform.  Exiting...." 
	   << endl;
      exit(2);
   }
   outputInv.close();
}
