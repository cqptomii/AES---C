//
// Created by tomfr on 26/11/2023.
//

#ifndef AES_FILE_H
#define AES_FILE_H
#include "file.h"
#include "Route.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define MAX_STRING_LENGTH 16
#define MAX_LENGTH_KEYPATH 1024
bool encrypt_file();
bool decrypt_file();
void encrypt_stdin();
void decrypt_stdin();
bool readInFile(FILE *file,char *get_data,int indexFile);
bool readCiphered(FILE *file,char get_data[16],int indexFile);
void writeInFile(FILE *file,int dim,unsigned char data_write[dim][dim]);
bool generateKey();
bool keyRecuperation(int dim,unsigned char key[dim][dim]);
#endif //AES_FILE_H
