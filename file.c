//
// Created by tomfr on 26/11/2023.
//
#include "file.h"
/** @brief function encrypt_file encrypt a file
 *  @return true if encryption succes,else false
 **/
bool encrypt_file(){
    // obtention of the key
    unsigned char key[4][4];
    unsigned char text[4][4];
    if(keyRecuperation(4,key)) {
        // obetention of the clear text
        char file_path[MAX_LENGTH_KEYPATH];
        char file_name[31];
        wprintf(L"Enter the name and the path of the file which would be ciphered : \n");
        wprintf(L"name : ");
        scanf("%20s", file_name);
        wprintf(L"\n");
        wprintf(L"path : ");
        scanf("%s", file_path);
        fflush(stdin);
        system("cls");
        strcat(file_name, "_crypt.txt");
        // Files opening
        FILE *read_file = fopen(file_path, "r");
        FILE *write_file = fopen(file_name, "a+");
        int read_index = 0;
        if (read_file != NULL && write_file != NULL) {
            // ciphering + writing
            char *clear_text = malloc(sizeof(char) * 16);
            while (readInFile(read_file, clear_text, read_index) == true) {
                matrixFill(4, text, clear_text);
                AES_128(4, key, text);
                writeInFile(write_file, 4, text);
                ++read_index;
            }
            fclose(read_file);
            fclose(write_file);
            remove(file_path); // Suppression of clear text
            free(clear_text);

            return true;
        } else {
            wprintf(L"Error during files opening \n");
            return false;
        }
    }else{
        wprintf(L"Error during key opening \n");
        return false;
    }

}
/** @brief function decrypt_file decrypt a file
 *  @return true if decryption succes,else false
 **/
bool decrypt_file(){
    unsigned char key[4][4];
    unsigned char text[4][4];
    char file_path[MAX_LENGTH_KEYPATH];
    if(keyRecuperation(4,key)) {
        wprintf(L"Enter the path of the file which would be decrypted : \n");
        wprintf(L"path : ");
        scanf("%s", file_path);
        fflush(stdin);
        system("cls");
        // Files opening
        FILE *read_file = fopen(file_path, "r");
        int read_index = 0;
        if (read_file) {
            char *ciphered_text = malloc(sizeof(char) * 16);
            while (readCiphered(read_file, ciphered_text, read_index)) {
                matrixFill(4, text, ciphered_text);
                invAES_128(4, key, text);
                for (int i = 0; i < 4; i++) {
                    for (int k = 0; k < 4; k++) {
                        wprintf(L"%c", text[i][k]);
                    }
                }
                wprintf(L"\n");
                ++read_index;
            }
            fclose(read_file);
            free(ciphered_text);
            return true;
        } else {
            wprintf(L"Error during files opening \n");
            return false;
        }
    }
    else{
        wprintf(L"Error during key opening \n");
        return false;
    }
}
/** @brief function encrypt_stdin encrypt enter of the user into a file
 *  @return true if encryption succes,else false
 **/
bool encrypt_stdin(){
    unsigned char key[4][4];
    unsigned char text[4][4];
    if(keyRecuperation(4,key)){
        char topic[10];
        int length=0;
        wprintf(L"  Enter the topic show on ciphered file : ");
        scanf("%10s",topic);
        fflush(stdin);
        wprintf(L"  Enter length of your text encrypted : ");
        scanf("%d",&length);
        fflush(stdin);
        char *clear_text=(char*) malloc(sizeof(char )*length);
        wprintf(L"  Enter your text : \n");
        scanf("%s",clear_text);
        fflush(stdin);

        char filename[20];
        strcat(filename,topic);
        strcat(filename,"_crypt.txt");
        FILE *write_data= fopen(filename,"a+");
        if(write_data){
            int read_index=0;
            while(read_index<length){
                // fill the matrix text
                for(int i=0;i< 4;i++){
                    for(int j=0;j<4;j++){
                        text[i][j]=clear_text[read_index];
                        read_index++;
                    }
                }
                AES_128(4,key,text);
                writeInFile(write_data,4,text);
            }
            //key save
            char key_name[18];
            strcat(key_name,"key_");
            strcat(key_name,topic);
            strcat(key_name,".txt");
            FILE *write_key= fopen(key_name,"w");
            if(write_key){
                for(int i=0;i<4;i++){
                    for(int k=0;k<4;k++){
                        fprintf(write_key,"%c",key[i][k]);
                    }
                }
                fclose(write_key);
            }
            else{
                wprintf(L"Cannot save the key into a new file \n");
                return false;
            }
            fclose(write_data);
            return true;
        }
        else{
            wprintf(L"Error during file opening \n");
            return false;
        }
    }
    else{
        wprintf(L"Error during key recuperation \n");
    }

}
/** @brief function readInFile read 16 caracs in the file
 *  @param file contained file opened
 *  @param getData array which contained 16 caracs
 *  @param indexFile index know are we in the file
 *  @return true if there are data to encrypt else false
 **/
bool readInFile(FILE *file,char *get_data,int indexFile){
    fseek(file,(16*indexFile),SEEK_SET);
    if(fgets(get_data, MAX_STRING_LENGTH+1, file)){
        return true;
    }else{
        return false;
    }

}
/** @brief function readCiphered read 16 numbers in the file and convert these numbers into character
 *  @param file contained file opened
 *  @param getData array which contained 16 caracs
 *  @param indexFile index know are we in the file
 *  @return true if there are data to encrypt else false
 **/
bool readCiphered(FILE *file,char get_data[16],int indexFile){
    fseek(file,0,SEEK_SET);
    // Check if we are at the EOF
    indexFile*=16;
    int verif;
    for(int i=0;i<indexFile;i++){
        fscanf(file,"%d \n",&verif);
    }
    int convert = 0;
    if(fscanf(file,"%d \n",&convert)==1){
        get_data[0]=convert;
        for (int k = 1; k < 16; k++) {
            fscanf(file, "%d \n", &convert);
            get_data[k] = convert;
        }
        return true;
    }
    else{
        return false;
    }
}
/** @brief function writeInFile write ciphered text in a File.txt
 *  @param file contained file opened
 *  @param dim Matrix dimension
 *  @param data_write array which contain ciphered data
 *  @return
 **/
void writeInFile(FILE *file,int dim,unsigned char data_write[dim][dim]){
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            fprintf(file,"%d\n",data_write[i][k]);
        }
    }
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