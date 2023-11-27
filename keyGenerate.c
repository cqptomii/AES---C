//
// Created by tomfr on 18/09/2023.
//
#define MAX_LENGTH_KEYPATH 1024
#include "keyGenerate.h"
/** @brief function generateKey generate a key of 128 bits to encrypt data by saved it in a secure file
 **/
bool generateKey(){
    FILE *keyFile=NULL;
    char keyPath[MAX_LENGTH_KEYPATH]; // need (.txt type at the end)
    printf("--- Generating ciphering key of 128 bytes ( 16 caracs ) ---\n\n");
    printf("Enter the path where the txt file would be created : ");
    scanf("%s",keyPath);
    fflush(stdin);

    keyFile=fopen(keyPath,"w");
    if(!keyFile){
        return false;
    }
    else{
        unsigned short i=0;
        char keyElement;
        srand(time(NULL));

        while(i<MAX_STRING_LENGTH){
            keyElement=(char) (rand() % 127 + 33);
            fprintf(keyFile,"%c",keyElement);
            ++i;
        }
        return true;
    }
}
/** @brief function keyRecuperation recup key contained into a .txt file
 *  @param key Key Matrix used to encrypt and decrypt data
 *  @param dim key Matrix dimension
 **/
bool keyRecuperation(int dim,unsigned char key[dim][dim]){
    char keyPath[MAX_LENGTH_KEYPATH];
    char cle[MAX_STRING_LENGTH];
    FILE *keyFile=NULL;
    printf("---- Key recuperation ---- \n\n");
    printf("Enter key Path : ");
    scanf("%s",keyPath);
    fflush(stdin);
    keyFile= fopen(keyPath,"r");
    if(keyFile){
        fgets(cle,MAX_STRING_LENGTH,keyFile);
        matrixFill(4,key,cle);
        return true;
    }
    else{
        return false;
    }
}
/** @brief function MatrixFill fill Matrix 4x4 with Hexadecimal values
 *  @param text Matrix using in AES algo
 *  @param dim text Matrix dimension
 *  @param str string read recup in a file
 **/
void matrixFill(int dim,unsigned char text[dim][dim],const char str[MAX_STRING_LENGTH]){
    int index=0;
    for(int i=0;i< 4;i++){
        for(int j=0;j<4;j++){
            text[i][j]=str[index];
            index++;
        }
    }
}
/** @brief function hubAlgorithm show the hub menu of encryption algorithm
 */
int hubAlgorithm(){
    printf("---- Hub menu of AES-128 algorithm ----\n");
    printf(" 0 - Quit \n");
    printf(" 1 - Encrypt Data \n");
    printf(" 2 - Decrypt Data \n\n");
    int response;
    printf(" Enter number: ");
    scanf("%d",&response);
    fflush(stdin);
    return response;
}