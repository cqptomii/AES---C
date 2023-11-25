//
// Created by tomfr on 16/09/2023.
//

#ifndef AES_MIXCOLUM_H
#define AES_MIXCOLUM_H
void mixColumns(int dim,unsigned char chiffre[dim][dim]);
void mixColumn(unsigned char column[]);
void invMixColumns(int dim,unsigned char chiffre[dim][dim]);
void invMixColumn(unsigned char Column[]);
#endif //AES_MIXCOLUM_H
