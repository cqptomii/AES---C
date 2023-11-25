//
// Created by tomfr on 15/09/2023.
//

#ifndef AES_KEYSCHEDULE_H
#define AES_KEYSCHEDULE_H
void rotWord(unsigned char vect[]);
void subWord(unsigned char vect[]);
void keySche(int dim,unsigned char K[dim][dim],unsigned char R1[dim][dim],unsigned char R2[dim][dim],unsigned char R3[dim][dim],unsigned char R4[dim][dim],unsigned char R5[dim][dim],unsigned char R6[dim][dim],unsigned char R7[dim][dim],unsigned char R8[dim][dim],unsigned char R9[dim][dim],unsigned char R10[dim][dim]);
void initKeySche(int dim1,int dim2,unsigned char tabKeySche[dim1][dim2],unsigned char K[dim1][dim1]);
void getFirstCol(int *index,int dim1,int dim2,const unsigned char rotCon[],unsigned char tabKeySch[dim1][dim2]);
void getInterCol(int dim1,int dim2,unsigned char tabKeySch[dim1][dim2],int *index);
void addRoundkey(int dim,unsigned char chiffre[dim][dim],unsigned char mat2[dim][dim]);
#endif //AES_KEYSCHEDULE_H
