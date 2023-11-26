#include <stdio.h>
#include "CorpsFini.h"
#include "mixColum.h"
#include "Route.h"
#include "keySchedule.h"
#include "ShiftRows.h"
int main() {
    unsigned char tab[4][4]={0x1,0x1,0x1,0x1,
                            0x2,0x3,0x2,0x5,
                            0x1,0x1,0x1,0x1,
                            0x1,0x1,0x1,0x1,};
    unsigned char key[4][4]= {0x02,0x23,0x21,0x45,
                              0x02,0x23,0x21,0x45,
                              0x02,0x23,0x21,0x45,
                              0x02,0x23,0x21,0x45};
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            printf("%d /",tab[i][k]);
        }
        printf("\n");
    }
    printf("\n\n");
    cipher(4,key,tab);
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            printf("%d /",tab[i][k]);
        }
        printf("\n");
    }
    printf("\n\n");
    invCypher(4,key,tab);
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            printf("%d /",tab[i][k]);
        }
        printf("\n");
    }
    return 0;
}
