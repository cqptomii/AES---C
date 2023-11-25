//
// Created by tomfr on 19/09/2023.
//

#ifndef AES_ROUTE_H
#define AES_ROUTE_H
void cipher(int dim,unsigned char key[dim][dim],unsigned char text[dim][dim]);
void invCypher(int dim,unsigned char key[dim][dim],unsigned char text[dim][dim]);
#endif //AES_ROUTE_H
