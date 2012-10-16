/*
 * Copyright S.V. Paulauskas 2012
 * stanpaulauskas@gmail.com 
 * Distributed under GNU General Public Licence v3
 */

/** 
 * \file DiscreteFourierAnalysis.hpp
 * A class for performing a Discrete Fourier Transform (DFT)
 * The class also performs the inverse DFT. 
 * \author S.V. Paulauskas
 * \date 15 January 2012
 */
#include <vector>
#include <iostream>

class DiscreteFourierAnalysis {
public:
   DiscreteFourierAnalysis(){};
   ~DiscreteFourierAnalysis(){};
   
   /*! Get the imaginary part of the inverse DFT */
   std::vector<double>* GetImInv(){return &imInv_;};
   /*! Get the imaginary part of the DFT */
   std::vector<double>* GetImTrans(){return &imTrans_;};
   /*! Get the modulus of the inverse DFT */
   std::vector<double>* GetModInv(){return &modInv_;};
   /*! Get the Modulus of the DFT */
   std::vector<double>* GetModTrans(){return &modTrans_;};
   /*! Get the real part of the inverse DFT */
   std::vector<double>* GetReInv(){return &reInv_;};
   /*! Get the real part of the DFT */
   std::vector<double>* GetReTrans(){return &reTrans_;};
   
   /*! Set the imaginary part of the input signal. This part can be 
     of zero size. */
   void SetImSig(std::vector<double> &temp){temp.swap(imSig_);};
   /*! Set the real part of the input signal. */
   void SetReSig(std::vector<double> &temp){temp.swap(reSig_);}; 
   
   /*! Performs the DFT */
   void DoInverseTransform(void);
   /*! Performs the inverse DFT */
   void DoTransform(void);

   /*! Check that the number of points in the real signal match the number of 
     points in the imaginary signal. */
   void SignalSizeCheck(void);
   
 private:
   unsigned int nPts_;
   std::vector<double> imSig_, reSig_, reTrans_, imTrans_, modTrans_, 
      reInv_, imInv_, modInv_;
};
