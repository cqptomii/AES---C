#include <stdio.h>
#include "CorpsFini.h"
#include "mixColum.h"
#include "Route.h"
#include "keySchedule.h"
int main() {
    unsigned char tab[4][4]={0x1,0x1,0x1,0x1,
                            0x2,0x3,0x2,0x5,
                            0x1,0x1,0x1,0x1,
                            0x1,0x1,0x1,0x1,};
    unsigned char key[4][4]={'k','k','e','e',
                             'e','y','y','y',
                             0xfe,0xe,'k','e',
                             0x12,0x9,0xde,0xa};
    unsigned char R1[4][4],R2[4][4],R3[4][4],R4[4][4],R5[4][4],R6[4][4],R7[4][4],R8[4][4],R9[4][4],R10[4][4];
    keySche(4,key,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10);
    keySche(4,key,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10);
    return 0;
}
