//
// Created by tomfr on 18/09/2023.
//

#ifndef AES_KEYGENERATE_H
#define AES_KEYGENERATE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define MAX_STRING_LENGTH 16
bool generateKey();
bool keyRecuperation(int dim,unsigned char key[dim][dim]);
void matrixFill(int dim,unsigned char text[dim][dim],const char str[MAX_STRING_LENGTH]);

#endif //AES_KEYGENERATE_H
