//
// Created by tomfr on 29/11/2023.
//
#include "hub.h"

int show_menu(){
    int response=0;
    wprintf(L"  ┌───────────────────────────────────────┐  \n");
    wprintf(L"  |           AES-128 Algorithm           |  \n");
    wprintf(L"  |    1- Encrypt Data                    |  \n");
    wprintf(L"  |    2- Decrypt Data                    |  \n");
    wprintf(L"  |    0- Quitter                         |  \n");
    wprintf(L"  └───────────────────────────────────────┘  \n \n");
    scanf("%1d",&response);
    fflush(stdin);
    while(response<0 || response>2){
        system("cls");
        wprintf(L"  ┌───────────────────────────────────────┐  \n");
        wprintf(L"  |           AES-128 Algorithm           |  \n");
        wprintf(L"  |    1- Encrypt Data                    |  \n");
        wprintf(L"  |    2- Decrypt Data                    |  \n");
        wprintf(L"  |    0- Quitter                         |  \n");
        wprintf(L"  └───────────────────────────────────────┘  \n \n");
        scanf("%1d",&response);
        fflush(stdin);
    }
}
int show_menu2(int mode){
    int type=0;
    if(mode==1){
        wprintf(L"  ┌───────────────────────────────────────┐  \n");
        wprintf(L"  |           AES-128 Algorithm           |  \n");
        wprintf(L"  |    1- Encrypt file.txt                |  \n");
        wprintf(L"  |    2- Encrypt stdin                   |  \n");
        wprintf(L"  |    0- Quitter                         |  \n");
        wprintf(L"  └───────────────────────────────────────┘  \n \n");
        scanf("%1d",&type);
        fflush(stdin);
        while(type<0 || type>2){
            system("cls");
            wprintf(L"  ┌───────────────────────────────────────┐  \n");
            wprintf(L"  |           AES-128 Algorithm           |  \n");
            wprintf(L"  |    1- Encrypt file.txt                |  \n");
            wprintf(L"  |    2- Encrypt stdin                   |  \n");
            wprintf(L"  |    0- Quitter                         |  \n");
            wprintf(L"  └───────────────────────────────────────┘  \n \n");
            scanf("%1d",&type);
            fflush(stdin);
        }
        return type;
    }
    else{
        wprintf(L"  ┌───────────────────────────────────────┐  \n");
        wprintf(L"  |           AES-128 Algorithm           |  \n");
        wprintf(L"  |    1- Decrypt file.txt                |  \n");
        wprintf(L"  |    0- Quitter                         |  \n");
        wprintf(L"  └───────────────────────────────────────┘  \n \n");
        scanf("%1d",&type);
        fflush(stdin);
        while(type<0 || type>1){
            system("cls");
            wprintf(L"  ┌───────────────────────────────────────┐  \n");
            wprintf(L"  |           AES-128 Algorithm           |  \n");
            wprintf(L"  |    1- Decrypt file.txt                |  \n");
            wprintf(L"  |    0- Quitter                         |  \n");
            wprintf(L"  └───────────────────────────────────────┘  \n \n");
            scanf("%1d",&type);
            fflush(stdin);
        }
        return type;
    }

}