/** \file DiscreteFourierAnalysis.h
 * Performs the Discrete Fourier (Inverse) Transform
 * Written : S.V. Paulauskas - 15 Jan 2012
 */
#include <vector>
#include <iostream>
class DiscreteFourierAnalysis 
{
 public:
   DiscreteFourierAnalysis(){};
   ~DiscreteFourierAnalysis(){};
   
   //Get methods
   std::vector<double>* GetImInv(){return &imInv_;};
   std::vector<double>* GetImTrans(){return &imTrans_;};
   std::vector<double>* GetModInv(){return &modInv_;};
   std::vector<double>* GetModTrans(){return &modTrans_;};
   std::vector<double>* GetReInv(){return &reInv_;};
   std::vector<double>* GetReTrans(){return &reTrans_;};

   //Set methods
   void SetImSig(std::vector<double> &temp){temp.swap(imSig_);};
   void SetReSig(std::vector<double> &temp){temp.swap(reSig_);}; 

   //The meaty methods
   void DoInverseTransform(void);
   void DoTransform(void);

   //The Miscellaneous methods
   void SignalSizeCheck(void);

 private:
   unsigned int nPts_;
   std::vector<double> imSig_, reSig_, reTrans_, imTrans_, modTrans_, 
      reInv_, imInv_, modInv_;
};
