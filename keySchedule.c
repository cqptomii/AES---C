//
// Created by tomfr on 15/09/2023.
//
#include "keySchedule.h"
/** @brief function rotWord shift elements present on a column of the matrix
 *  @param vect column of 4x4 Matrix represent as a vector
 **/
void rotWord(unsigned char vect[]){
    unsigned char recup= vect[0];
    vect[0]=vect[1];
    vect[1]=vect[2];
    vect[2]=vect[3];
    vect[3]=recup;
}
/** @brief function subWord will subsituate elements present on a column of the matrix
 * @param vect column of 4x4 Matrix represent as a vector
 **/
void subWord(unsigned char vect[]){
    unsigned char index;
    unsigned char sBox[256]={0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
                             0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
                             0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
                             0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
                             0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
                             0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
                             0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
                             0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
                             0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
                             0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
                             0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
                             0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
                             0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
                             0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
                             0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
                             0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16,};
    for( int i =0;i<4;i++){
        index=vect[i];
        vect[i]=sBox[index];
    }

}
/** @brief function keySche create keyschedule and 10 RoundKey
 *  @param dim size of Matrix
 *  @param K Matrix which contain the key
 *  @param R1-R10 Round Key 1 to 10 ( each a 4x4 Matrix)
 **/
void keySche(int dim,unsigned char K[dim][dim],unsigned char R1[dim][dim],unsigned char R2[dim][dim],unsigned char R3[dim][dim],unsigned char R4[dim][dim],unsigned char R5[dim][dim],unsigned char R6[dim][dim],unsigned char R7[dim][dim],unsigned char R8[dim][dim],unsigned char R9[dim][dim],unsigned char R10[dim][dim]){
    unsigned char tabKeySche[4][44]={0};
    int rotConIndex=0,interColIndex=5;
    unsigned char rotCon[10]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1B,0x36};
    initKeySche(4,44,tabKeySche,K);
    for( int i=0;i<10;i++){
        getFirstCol(&rotConIndex,4,44,rotCon,tabKeySche);
        getInterCol(4,44,tabKeySche,&interColIndex);
    }
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            R1[i][j]=tabKeySche[i][4+j];
            R2[i][j]=tabKeySche[i][8+j];
            R3[i][j]=tabKeySche[i][12+j];
            R4[i][j]=tabKeySche[i][16+j];
            R5[i][j]=tabKeySche[i][20+j];
            R6[i][j]=tabKeySche[i][24+j];
            R7[i][j]=tabKeySche[i][28+j];
            R8[i][j]=tabKeySche[i][32+j];
            R9[i][j]=tabKeySche[i][36+j];
            R10[i][j]=tabKeySche[i][40+j];
        }
    }
}
/** @brief function getInterCol calculate elements on other column than first of the roundKey
 *  @param dim1 number of line of tabKeySch Matrix
 *  @param dim2 number of column of tabKeySch Matrix
 *  @param tabKeySch Matrix which represent the entire KeySchedule
 *  @param index Pointer to update the position on the Matrix
 **/
void getInterCol(int dim1,int dim2,unsigned char tabKeySch[dim1][dim2],int *index){
    for(int i=0;i<3;i++){
        for(int j=0;j<dim1;j++){
            tabKeySch[j][*index] = tabKeySch[j][*index-1] ^ tabKeySch[j][*index-4];
        }
        *index+=1;
    }
    *index+=1;
}
/** @brief function getFirstCol calculate elements on the first column of the roundKey
 *  @param index Pointer to update the position on the Matrix
 *  @param dim1 number of line of tabKeySch Matrix
 *  @param dim2 number of column of tabKeySch Matrix
 *  @param rotCon vector used to calculate first element
 *  @param tabKeySch Matrix which represent the entire KeySchedule
 **/
void getFirstCol(int *index,int dim1,int dim2,const unsigned char rotCon[],unsigned char tabKeySch[dim1][dim2]){
    int targetIndex=*index * 4 + 4;
    int rotConIndex=targetIndex-1;
    int addIndex=targetIndex-4;
    unsigned char keySubWord[4];

    for(int j=0;j<dim1;j++){
        keySubWord[j]=tabKeySch[j][rotConIndex];
    }
    rotWord(keySubWord);
    subWord(keySubWord);

    for(int i=0;i<dim1;i++){
        if(!i){
            tabKeySch[i][targetIndex]= tabKeySch[i][addIndex] ^ keySubWord[i] ^ rotCon[*index];
        }
        else{
            tabKeySch[i][targetIndex]= tabKeySch[i][addIndex] ^ keySubWord[i];
        }
    }
    *index+=1;
}
/** @brief function initKeySche copy the key in the keySchedule
 *  @param dim1 number of line of tabKeySch Matrix
 *  @param dim2 number of column of tabKeySch Matrix
 *  @param tabKeySch Matrix which represent the entire KeySchedule
 *  @param K Matrix which contain the key
 **/
void initKeySche(int dim1,int dim2,unsigned char tabKeySche[dim1][dim2],unsigned char K[dim1][dim1]){
    for(int i=0;i<dim1;i++){
        for(int j=0;j<dim1;j++){
            tabKeySche[i][j]=K[i][j];
        }
    }
}
/** @brief function addRoundkey add the round key on the text which would be ciphered
 *  @param dim dimension of text Matrix
 *  @param chiffre Matrix which represent the ciphered text
 *  @param roundKey matrix which represent the roundKey added
 **/
void addRoundkey(int dim,unsigned char chiffre[dim][dim],unsigned char roundKey[dim][dim]){
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            chiffre[i][j] = chiffre[i][j] ^ roundKey[i][j];
        }
    }
}