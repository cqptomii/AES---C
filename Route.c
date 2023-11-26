//
// Created by tomfr on 19/09/2023.
//
#include "Route.h"
#include "keySchedule.h"
#include "ShiftRows.h"
#include "Subbyte.h"
#include "mixColum.h"
/** @brief function cipher which encrypt the data by using AES-128 algorithm
 ** @param dim size of Matrix
 *  @param key Matrix which contain the key
 *  @param text Matrix which contain clear data
 **/
void cipher(int dim,unsigned char key[dim][dim],unsigned char text[dim][dim]){
    unsigned char R1[4][4],R2[4][4],R3[4][4],R4[4][4],R5[4][4],R6[4][4],R7[4][4],R8[4][4],R9[4][4],R10[4][4];
    keySche(4,key,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10);

    addRoundkey(4,text,key);
    for (int i=0;i<9;i++){
        Sbox(4,text);
        shiftR(4,text);
        mixColumns(4,text);
        switch (i) {
            case 0:
                addRoundkey(4,text,R1);
                break;
            case 1:
                addRoundkey(4,text,R2);
                break;
            case 2:
                addRoundkey(4,text,R3);
                break;
            case 3:
                addRoundkey(4,text,R4);
                break;
            case 4:
                addRoundkey(4,text,R5);
                break;
            case 5:
                addRoundkey(4,text,R6);
                break;
            case 6:
                addRoundkey(4,text,R7);
                break;
            case 7:
                addRoundkey(4,text,R8);
                break;
            case 8:
                addRoundkey(4,text,R9);
                break;
            default:
                break;
        }
    }
    Sbox(4,text);
    shiftR(4,text);
    addRoundkey(4,text,R10);
}
/** @brief function invCypher which decrypt the data
 ** @param dim size of Matrix
 *  @param key Matrix which contain the key
 *  @param text Matrix which contain ciphered data
 **/
void invCypher(int dim,unsigned char key[dim][dim],unsigned char text[dim][dim]){
    unsigned char R1[4][4],R2[4][4],R3[4][4],R4[4][4],R5[4][4],R6[4][4],R7[4][4],R8[4][4],R9[4][4],R10[4][4];
    keySche(4,key,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10);

    addRoundkey(4,text,R10);
    invShiftR(4,text);
    invSBox(4,text);
    for (int i=0;i<9;i++){
        switch (i) {
            case 0:
                addRoundkey(4,text,R9);
                break;
            case 1:
                addRoundkey(4,text,R8);
                break;
            case 2:
                addRoundkey(4,text,R7);
                break;
            case 3:
                addRoundkey(4,text,R6);
                break;
            case 4:
                addRoundkey(4,text,R5);
                break;
            case 5:
                addRoundkey(4,text,R4);
                break;
            case 6:
                addRoundkey(4,text,R3);
                break;
            case 7:
                addRoundkey(4,text,R2);
                break;
            case 8:
                addRoundkey(4,text,R1);
                break;
            default:
                break;
        }
        invMixColumns(4,text);
        invShiftR(4,text);
        invSBox(4,text);
    }
    addRoundkey(4,text,key);
}