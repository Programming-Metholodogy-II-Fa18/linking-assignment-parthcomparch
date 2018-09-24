#include <iostream>
#include "string"
#include <math.h>
using namespace std;
 string ProblemFourA(string S){
     int i = 0;
     while (S[i] != '\0')
     {
         ++i;
     }
     int Length = i;
     for(int j=0; j < Length/2; ++j)
     {
         char temp = S[j];
         S[j] = S[Length-j-1];
         S[Length-j-1] = temp;
     }
     for(int k =0; k<Length; k++)
     {
         cout<<S[k];
     }
     return S;
 }


