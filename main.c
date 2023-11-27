#include "Route.h"
#include <stdio.h>
#define MATRIX_DIMENSION 4
int main() {
    unsigned char tab[4][4]={'t','o','u','t',
                            'e','t',0x2,0x5,
                            0x1,0x1,0x1,0x1,
                            0x1,0x1,0x1,0x1,};
    unsigned char key[4][4]= {0x02,0x23,0x21,0x45,
                              0x02,0x23,0x21,0x45,
                              0x02,0x23,0x21,0x45,
                              0x02,0x23,0x21,0x45};
    printf("key : \n");
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            printf("%d /",key[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            printf("%d /",tab[i][k]);
        }
        printf("\n");
    }
    printf("\n\n");
    AES_128(4,key,tab);
    printf("ciphered Data \n");
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            printf("%d /",tab[i][k]);
        }
        printf("\n");
    }
    printf("\n\n");
    invAES_128(4,key,tab);
    printf("inverse \n");
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            printf("%d /",tab[i][k]);
        }
        printf("\n");
    }
    return 0;
}
