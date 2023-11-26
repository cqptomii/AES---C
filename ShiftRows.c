//
// Created by tomfr on 15/09/2023.
//
#include "ShiftRows.h"
/** @brief function shiftR shift values of the Matrix chiffre
 *  @param dim size of Matrix
 *  @param chiffre Matrix which contain clear data
 **/
void shiftR(int dim, unsigned char chiffre[dim][dim]){
unsigned char recup=chiffre[1][3];
chiffre[1][3]=chiffre[1][0];
chiffre[1][0]=chiffre[1][1];
chiffre[1][1]=chiffre[1][2];
chiffre[1][2]=recup;

recup=chiffre[2][3];
chiffre[2][3]=chiffre[2][1];
chiffre[2][1]=recup;
recup=chiffre[2][2];
chiffre[2][2]=chiffre[2][0];
chiffre[2][0]=recup;

recup=chiffre[3][3];
chiffre[3][3]=chiffre[3][2];
chiffre[3][2]=chiffre[3][1];
chiffre[3][1]=chiffre[3][0];
chiffre[3][0]=recup;
}
/** @brief function invShiftR shift values of the Matrix chiffre in opposite way than shiftR
 * @param dim size of Matrix
 *  @param chiffre Matrix which contain cipher data
 **/
void invShiftR(int dim, unsigned char chiffre[dim][dim]){
unsigned char recup= chiffre[1][3];
chiffre[1][3]=chiffre[1][2];
chiffre[1][2]=chiffre[1][1];
chiffre[1][1]=chiffre[1][0];
chiffre[1][0]=recup;

recup=chiffre[2][3];
chiffre[2][3]=chiffre[2][1];
chiffre[2][1]=recup;
recup=chiffre[2][2];
chiffre[2][2]=chiffre[2][0];
chiffre[2][0]=recup;

recup=chiffre[3][3];
chiffre[3][3]=chiffre[3][0];
chiffre[3][0]=chiffre[3][1];
chiffre[3][1]=chiffre[3][2];
chiffre[3][2]=recup;
}