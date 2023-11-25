//
// Created by tomfr on 14/09/2023.
//
#include "CorpsFini.h"
void multFiniInv(int Result[]){
    FILE *file=NULL;
    file= fopen("1.txt","r");
    if(!file){ printf("Erreur lors de l'ouverture du fichier ");}
    else{
        for(int i=0;i<=7;i++){
            Result[i]= fgetc(file);
        }
        fgets(NULL,1,file);
        for(int i=8;i<=15;i++){
            Result[i]= fgetc(file);
        }
    }
}
unsigned char multFini(int binary1,int binary2){

    int coef[16],coefFinal[15], index[15];
    unsigned char result;
    convDecBin(binary1,binary2,coef);
    getInterPoly(coef,coefFinal,index);
    multFiniGetPoly(coef,coefFinal);
    divisEucli(coefFinal,index);
    result= convBinToDec(coefFinal,index);
      return result;
}
int convBinToDec(const int coefFinal[],int index[]){
    int value=0;
    for(int i=0;i<15;i++){
        if(coefFinal[i]==1){
            value+= (int) pow(2,index[i]);
        }
    }
    return value;
}
void convDecBin(int D1,int D2,int result[]){
    for(int i=0; i<=7; i++){
        if(D1>0) {
            result[i] = D1 % 2;
            D1 /= 2;
        }
        else{
            result[i]=0;
        }
    }
    for(int i=8; i<=15; i++){
        if(D2>0) {
            result[i] = D2 % 2;
            D2 /= 2;
        }
        else{
            result[i]=0;
        }
    }
}
void RecupBin(int Bin1[],int Bin2[]){
    FILE *file=NULL;
    file= fopen("1.txt","a");
    if(!file){ printf("Erreur lors de l'ouverture du fichier 1 : ");}
    else{
        for(int i=0;i<=7;i++){
            fprintf(file,"%d",Bin1[i]);
        }
        fprintf(file,"\n");
        for(int i=0;i<=7;i++){
            fprintf(file,"%d",Bin2[i]);
        }
    }
}
int searchHighPoly(const int coef[],const int index[]){
    int recup=0;
    for(int i =14;i>=0;i--){
        if(coef[i]==1){
            if(recup<index[i]){
                recup=index[i];
            }
        }
    }
    return recup;
}
void divisEucli(int coefFinal[],int index[]){
    int modulo[5]={8,4,3,1,0},resultModulo[5];
    int diff,highPoly;
    highPoly= searchHighPoly(coefFinal,index);
    while (modulo[0] <= highPoly) {
        diff = highPoly - modulo[0];
        for (int j = 0; j < 5; j++) {
            resultModulo[j] = diff + modulo[j];
            coefFinal[resultModulo[j]]--;
        }
        highPoly = searchHighPoly(coefFinal, index);
    }
    for (int x = 0; x <= 14; x++) {
        if (coefFinal[x] < 0) {
            coefFinal[x] = abs(coefFinal[x]);
        }
    }
}
void multFiniGetPoly(const int coef[],int coefFinal[]){
    int varRecup,coefFinalIndex[15]={0};
    for(int i=0;i <= 7 ;i++ ){
        for(int j=0;j <= 7;j++){
            if(coef[i]>=0 && coef[8+j]>=0) {
                varRecup = coef[i] + coef[8 + j];
                coefFinalIndex[varRecup]++;
            }
        }
    }
    for( int i=14; i >= 0;i-- ){
        if(coefFinalIndex[i]==2){
            coefFinalIndex[i]=0;
        }
    }
    for( int b=0;b<=14;b++){
        coefFinal[b]=coefFinalIndex[b];
    }
}
void getInterPoly(int coef[],int coefFinal[],int index[]){
    multFiniInit(index,coefFinal);
    for(int i=0;i<=7;i++){
        if(coef[i]==1){
            coef[i]=index[i];
        }
        else if(coef[i]==0){
            coef[i]--;
        }
        if(coef[i+8]==1){
            coef[i+8]=index[i];
        }
        else if(coef[i+8]==0){
            coef[i+8]--;
        }
    }
}
void multFiniInit(int index[],int coefFinal[]){
    for( int i=0;i<15;i++){
        index[i]=i;
        coefFinal[i]=0;
    }
}
