//
// Created by tomfr on 19/09/2023.
//

#ifndef AES_ROUTE_H
#define AES_ROUTE_H
void AES_128(int dim,unsigned char key[dim][dim],unsigned char text[dim][dim]);
void invAES_128(int dim,unsigned char key[dim][dim],unsigned char text[dim][dim]);
#endif //AES_ROUTE_H
