#include<bits/stdc++.h>
#include <cstdio>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
using namespace std;


int initialPermutation[]={

    58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,18,10,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7

};


int permutedChoice1[]={

    57,49,41,33,25,17,9,
    1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,
    19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,
    7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,
    21,13,5,28,20,12,4

};


int permutedChoice2[] ={

    14, 17, 11, 24,  1,  5,
    3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32

};


int ExpansionBox[]={

    32,1,2,3,4,5,
    4,5,6,7,8,9,
    8,9,10,11,12,13,
    12,13,14,15,16,17,
    16,17,18,19,20,21,
    20,21,22,23,24,25,
    24,25,26,27,28,29,
    28,29,30,31,32,1

};


FILE *filePointer;

int key56Bit[56];
int Key48Bit[17][48];

int shiftingRounds[]={

    1,1,2,2,2,2,2,2,
    1,2,2,2,2,2,2,1

};

//code to convert 64 bit key to 56 bit key
void convertingKey64To56(int position,int text){

    int i;

    for(i=0;i<56;i++){

        if(permutedChoice1[i]==position+1){
            break;
        }
    } 

    key56Bit[i]=text;
}


//code to convert 64 bit key to 48 bit key
void convertingKey64To48(unsigned int key[]){

    int i,j,k,round;
    int temporary[17][2];
    int C[17][28],D[17][28];
    int C1D1[17][56];

    for(i=0;i<64;i++){
        convertingKey64To56(i,key[i]);
    }

    for(i=0;i<56;i++){
        if(i<28){
            C[0][i]=key56Bit[i];
        }

        else{
            D[0][i-28]=key56Bit[i];
        }
    }

    for(round=1;round<17;round++){

        int shift=shiftingRounds[round-1];

        for(i=0;i<shift;i++){
            temporary[round-1][i]=C[round-1][i];
        }

        for(i=0;i<(28-shift);i++){
            C[round][i]=C[round-1][i+shift];
        }

        int j=0;
        for(i=28-shift;i<28;i++){
            C[round][i]=temporary[round-1][j];
            j++;
        }

        for(i=0;i<shift;i++){
            temporary[round-1][i]=D[round-1][i];
        }

        for(i=0;i<(28-shift);i++){
            D[round][i]=D[round-1][i+shift];
        }

        j=0;
        for(i=28-shift;i<28;i++){
            D[round][i]=temporary[round-1][j];
            j++;
        }

    }

    for(round=0;round<17;round++){
        for(j=0;j<28;j++){
            C1D1[round][j]=C[round][j];
        }

        for(j=28;j<56;j++){
            C1D1[round][j]=D[round][j-28];
        }

    }

    for(round=1;round<17;round++){
        for(j=0;j<56;j++){
            for(k=0;k<48;k++){
                if(permutedChoice2[k]==j+1){
                    break;
                }
            }
            Key48Bit[round][k]=C1D1[round][j];
        }
    }
}



//Code to generate 16 48 bit keys for 16 fiestel rounds
void generating16Keys(){

    FILE *filePointer1=fopen("input.txt","r");//read the 64 bit key text
    unsigned int key[64];
    int i=0;
    int ch;

    while(!feof(filePointer1)){

        ch=getc(filePointer1);
        key[i]=ch-48;
        
        i++;

    }

    convertingKey64To48(key);
    fclose(filePointer1);

}



//code to find the size of plain text given as input
long int sizeOfFile(){

    long int size;
    FILE *filePointer2=fopen("inputPlainText.txt","r"); // read the plaintext file

    if(fseek(filePointer2,0L,SEEK_END)){
        printf("function failed.");
    }

    else{
        size=ftell(filePointer2);
    }

    fclose(filePointer2);
    return size;

}



void ConvertToBinary(int n){

    int k,m;

    for(int i=7;i>=0;i--){

        m=1<<i;
        k=n & m;

        if(k==0){
            fprintf(filePointer,"0");
        }

        else{
            fprintf(filePointer,"1");
        }

    }

}



//code to convert character of files into bit
void CharacterOfFileToBit(long int size){


    FILE *filePointer3=fopen("inputPlainText.txt","r"); //read the plain text file

    filePointer=fopen("bitText.txt","w"); //write the binary values on bitText file

    int i=size;

    char ch;

    while(--i){

        ch=fgetc(filePointer3);

        if(ch==-1){
            break;
        }

        //i--;
        ConvertToBinary(ch);

    }   

    fclose(filePointer3);
    fclose(filePointer);


}



int main(void){

    generating16Keys();

    long int size=sizeOfFile();
    printf("%ld",size);

    CharacterOfFileToBit(size);


    return 0;

}