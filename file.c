//
// Created by tomfr on 26/11/2023.
//
#include "file.h"
bool encrypt_file(){
    unsigned char key[4][4];
    keyRecuperation(4,key);


}
bool decrypt_file(){
    unsigned char key[4][4];
    keyRecuperation(4,key);

}
void encrypt_stdin(){
    unsigned char key[4][4];
    keyRecuperation(4,key);

}
void decrypt_stdin(){
    unsigned char key[4][4];
    keyRecuperation(4,key);

}
/** @brief function generateKey generate a key of 128 bits to encrypt data by saved it in a secure file
 * @return false if cannot open keyFile , yes
 **/
bool generateKey(){
    FILE *keyFile=NULL;
    char keyPath[MAX_LENGTH_KEYPATH]; // need (.txt type at the end)
    wprintf(L"--- Generating ciphering key of 128 bytes ( 16 caracs ) ---\n\n");
    wprintf(L"Enter the path where the txt file would be created : ");
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
            keyElement=(char) (rand() % 94 + 33);
            if(isdigit(keyElement)){
                fprintf(keyFile,"%d",keyElement);
            }
            else {
                fprintf(keyFile, "%c", keyElement);
            }
            ++i;
        }
        fclose(keyFile);
        return true;
    }
}
/** @brief function keyRecuperation recup key contained into a .txt file
 *  @param key Key Matrix used to encrypt and decrypt data
 *  @param dim key Matrix dimension
 *  @return false if cannot open keyFile , yes
 **/
bool keyRecuperation(int dim,unsigned char key[dim][dim]){
    char keyTempPath[MAX_LENGTH_KEYPATH];
    char cle[MAX_STRING_LENGTH];
    FILE *keyFile=NULL;
    short key_answer=0;
    wprintf(L"  ┌───────────────────────────────────────┐  \n");
    wprintf(L"  |           Key recupération            |  \n");
    wprintf(L"  |    1- In a file.txt                   |  \n");
    wprintf(L"  |    2- In stdin                        |  \n");
    wprintf(L"  └───────────────────────────────────────┘  \n \n");
    scanf("%1hd",&key_answer);
    fflush(stdin);
    while(key_answer<1 || key_answer>2){
        system("cls");
        wprintf(L"  ┌───────────────────────────────────────┐  \n");
        wprintf(L"  |           Key recupération            |  \n");
        wprintf(L"  |    1- In a file.txt                   |  \n");
        wprintf(L"  |    2- In stdin                        |  \n");
        wprintf(L"  └───────────────────────────────────────┘  \n \n");
        scanf("%1hd",&key_answer);
        fflush(stdin);
    }
    if(key_answer==1) {
        wprintf(L"Enter key Path : ");
        scanf("%s", keyTempPath);
        fflush(stdin);
        keyFile = fopen(keyTempPath, "r");
        if (keyFile) {
            fgets(cle, MAX_LENGTH_KEYPATH, keyFile);
            matrixFill(4, key, cle);
            fclose(keyFile);
            return true;
        } else {
            return false;
        }
    }
    else{
        wprintf(L"Enter 16 characters max in order to create the key : \n ");
        scanf("%16s", cle);
        fflush(stdin);
        matrixFill(4,key,cle);
        return true;
    }
}