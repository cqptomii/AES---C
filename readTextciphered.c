//
// Created by tomfr on 27/11/2023.
//
#include "readTextciphered.h"
/** @brief function cipher which encrypt the data by using AES-128 algorithm
 *  @param dim size of Matrix
 *  @param key Matrix which contain the key
 *  @param text Matrix which contain clear data
 **/
FILE *selectFile(){
    char pathSelected[1024];FILE *file=NULL;
    printf("--- Select File which would be read ---\n\n");
    printf(" Path : ");
    scanf("%s",pathSelected);
    file= fopen(pathSelected,"w");
    if(file){
        return file;
    }
    else{
        return NULL;
    }
}
bool readInFile(FILE *file){
}