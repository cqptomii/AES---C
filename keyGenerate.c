//
// Created by tomfr on 18/09/2023.
//
#include "keyGenerate.h"
/** @brief function generateKey generate a key of 128 bits to encrypt data by saved it in a secure file
 **/
void generateKey(){
    FILE *filesave=NULL;
    filesave=fopen("key.txt","w");
    if(!filesave){
        printf("Erreur lors de l'ouverture du fichier ");
    }
    else{

    }
}
/** @brief function keyRecuperation recup key contained into a .txt file
 *  @param key Key Matrix used to encrypt and decrypt data
 *  @param dim key Matrix dimension
 **/
bool keyRecuperation(int dim,unsigned char key[dim][dim]){
}
/** @brief function MatrixFill fill Matrix 4x4 with Hexadecimal values
 *  @param text Matrix using in AES algo
 *  @param dim text Matrix dimension
 *  @param str string read recup in a file
 **/
void matrixFill(int dim,unsigned char text[dim][dim],const unsigned char str[MAX_STRING_LENGTH]){
    int index=0;
    for(int i=0;i< 4;i++){
        for(int j=0;j<4;j++){
            text[i][j]=str[index];
            index++;
        }
    }
}