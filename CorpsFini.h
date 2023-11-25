//
// Created by tomfr on 14/09/2023.
//

#ifndef AES_CORPSFINI_H
#define AES_CORPSFINI_H
#include "string.h"
#include "math.h"
#include "stdio.h"
#include "math.h"
unsigned char multFini(int binary1,int binary2);
void convDecBin(int D1,int D2,int result[]);
void divisEucli(int coefFinal[],int index[]);
void getInterPoly(int coef[],int coefFinal[],int index[]);
void multFiniInit(int index[],int coefFinal[]);
void multFiniGetPoly(const int coef[],int coefFinal[]);
int searchHighPoly(const int coef[],const int index[]);
int convBinToDec(const int coefFinal[],int index[]);
void multFiniInv(int Result[]);
void RecupBin(int Bin1[],int Bin2[]);
#endif //AES_CORPSFINI_H
