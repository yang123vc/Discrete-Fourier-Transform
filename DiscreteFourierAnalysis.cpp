/********************************************************
 ** \file DiscreteFourierAnalysis.cpp
 ** Class that does Fourier (inverse) Transforms
 ** Written : S.V. Paulauskas - 15 Jan 2012
 *******************************************************/
#include <cmath>
#include <cstdlib>

#include "DiscreteFourierAnalysis.h"

using namespace std;

//********** DoInverseTransform **********
void DiscreteFourierAnalysis::DoInverseTransform(void)
{
   if(reTrans_.empty()) {
      cout << "You must perform a transform before performing an "
	   << "an inverse transform." << endl << "Exiting...." << endl;
      exit(2);
   }

   double alpha, beta, tempRe, tempIm;
   for(unsigned int b = 0; b < nPts_; b++) {
      alpha = (2.*M_PI*b)/double(nPts_);
      
      tempRe = 0, tempIm = 0;
      for(unsigned int a = 0; a < nPts_; a++) {
	 beta = alpha*a;
	 tempRe += (reTrans_[a] * cos(beta) - imTrans_[a] * sin(beta));
	 tempIm += (imTrans_[a] * cos(beta) + reTrans_[a] * sin(beta));
      }
      tempRe = (sqrt(2*M_PI)/nPts_)*tempRe;
      tempIm = (sqrt(2*M_PI)/nPts_)*tempIm;
      reInv_.push_back(tempRe);
      imInv_.push_back(tempIm);
      modInv_.push_back(sqrt(tempRe*tempRe+tempIm*tempIm));
   }
}


//********** DoTransoform **********
void DiscreteFourierAnalysis::DoTransform(void)
{
   bool hasImaginary = false;
   if(imSig_.empty())
      nPts_=reSig_.size();
   else {
      SignalSizeCheck();
      hasImaginary = true;
   }

   double alpha, beta, tempRe, tempIm;
   for(unsigned int b = 0; b < nPts_; b++) {
      alpha = -(2.*M_PI*b)/double(nPts_);
      
      tempRe = 0, tempIm = 0;
      for(unsigned int a = 0; a < nPts_; a++) {
	 beta = alpha*a;
	 if(!hasImaginary) {
	    tempRe += (reSig_[a] * cos(beta));
	    tempIm += (reSig_[a] * sin(beta));
	 } else {
	    tempRe += (reSig_[a] * cos(beta) + imSig_[a] * sin(beta));
	    tempIm += (imSig_[a] * cos(beta) - reSig_[a] * sin(beta));
	 }
      }
      tempRe = (1/sqrt(2*M_PI))*tempRe;
      tempIm = (1/sqrt(2*M_PI))*tempIm;
      reTrans_.push_back(tempRe);
      imTrans_.push_back(tempIm);
      modTrans_.push_back(sqrt(tempRe*tempRe+tempIm*tempIm));
   }
}


//********** SignalSizeCheck **********
void DiscreteFourierAnalysis::SignalSizeCheck(void)
{
   if(imSig_.size() != reSig_.size()) {
      cout << "The number of points in the Real Signal (" 
	   << reSig_.size() << ") does not match the number of points in" 
	   << "the Imaginary Signal (" << imSig_.size() << ").  "
	   << "Things would be better if that were corrected." << endl;
      exit(2);
   }
}
