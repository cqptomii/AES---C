#include "Route.h"
#include "hub.h"
#include "file.h"
#define MATRIX_DIMENSION 4
int main() {
    _setmode(_fileno(stdout), 0x00020000);
    int mode=0,type=0;char quit_response;
    bool quit=false;
    while(!quit) {
        mode=show_menu();
        if(mode==0){
            return 0;
        }
        else{
            if(mode==1){
                type=show_menu2(mode);
                if(!type){
                    return 0;
                }
                else {
                    if (type == 1) {
                        encrypt_file();
                    }
                    else {
                        if (type == 2) {
                            encrypt_stdin();
                        }
                    }
                }
            }
            else{
                if(mode==2){
                    type=show_menu2(mode);
                    if(!type){
                        return 0;
                    }
                    else {
                        if (type == 1) {
                            decrypt_file();
                        }
                        else {
                            if (type == 2) {
                                decrypt_stdin();
                            }
                        }
                    }
                }
            }
        }
        printf("Would you close the program ?  (Y/N)\n");
        scanf("%1c",&quit_response);
        fflush(stdin);
        while(tolower(quit_response)!='n' && tolower(quit_response)!='y'){
            printf("Would you close the program ?  (Y/N)\n");
            scanf("%1c",&quit_response);
        }
        if(quit_response=='y'){
            quit=true;
        }
    }




    /*
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
     */
    return 0;
}
