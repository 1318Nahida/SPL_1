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


int PermutationBox[]={
    26,7,20,21,
    29,12,28,17,
    1,15,23,26,
    5,18,31,10,
    2,8,24,14,
    32,27,3,9,
    19,13,30,6,
    22,11,4,25
};


int S1[4][16]={

    14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
    0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
    4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
    15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
};


int S2[4][16] =
{
    15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
    3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
    0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
    13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9
};


int S3[4][16] =
{
    10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
    13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
    13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
    1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12
};


int S4[4][16] =
{
    7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
    13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
    10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
    3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14
};


int S5[4][16] =
{
    2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
    14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
    4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
    11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3
};


int S6[4][16] =
{
    12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
    10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
    9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
    4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13
};


int S7[4][16]=
{
    4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
    13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
    1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
    6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12
};


int S8[4][16]=
{
    13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
    1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
    7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
    2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
};


int FinalPermutation[]={
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25
};


FILE *filePointer;

int key56Bit[56];
int Key48Bit[17][48];
int InitialPermutatedText[64];
int Left32bit[17][32];
int Right32bit[17][32];
int ExpansionText[48];
int XORText[48];
int X[8][6];
int X2[32];
int R[32];
int CipherText[64];
int EncryptedText[64];

int shiftingRounds[]={

    1,1,2,2,2,2,2,2,
    1,2,2,2,2,2,2,1

};



void expansion_function(int position,int text){
    for(int i=0;i<48;i++){
        if(ExpansionBox[i]==position+1){
            ExpansionText[i]=text;
        }
    }

}



int XOR(int x,int y){
    return (x^y);
}


//code to convert 64 bit key to 56 bit key
void convertingKey64To56(int position,int text){

    int i;

    for(i=0;i<56;i++){

        if(permutedChoice1[i]==position+1){
            break;
        }
    }
    if(i<56){
        key56Bit[i]=text;
        printf("%d %d\n",i,key56Bit[i]);
    }
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

    printf("\n\n");

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
            if(k<48){
                Key48Bit[round][k]=C1D1[round][j];
                printf("%d %d %d\n",round,k,Key48Bit[round][k]);
            }
        }
    }
}



//Code to generate 16 48 bit keys for 16 fiestel rounds
void generating16Keys(){
    FILE *filePointer1=fopen("input1.txt","rb");//read the 64 bit key text
    FILE *fp1=fopen("input6.txt","wb");
    unsigned int key[64];
    int i=0;
    int ch;

    while(!feof(filePointer1)){
        ch=fgetc(filePointer1);
        key[i]=ch-48;
        printf("%u \n",key[i]);
        fputc(ch,fp1);
        i++;
        if(i==64) break;
    }
    fclose(fp1);
    convertingKey64To48(key);
    fclose(filePointer1);
}



//code to find the size of plain text given as input
long int sizeOfFile(){

    long int length;
    FILE *filePointer2=fopen("inputtext.txt","rb"); // read the plaintext file

    if(filePointer2==NULL){
        printf("File not found!!");
        exit(1);
    }

    fseek(filePointer2,0,SEEK_END);

    length=ftell(filePointer2)-1;

    fclose(filePointer2);

    printf("\nLength of text file is %ld\n",length);
    return length;

}



void ConvertToBinary(int n){

    int k,m;

    for(int i=7;i>=0;i--){

        m=1<<i;
        k=n & m;

        if(k==0){
            fprintf(filePointer,"0");
            printf("0");
        }

        else{
            fprintf(filePointer,"1");
            printf("1");
        }

    }

}



//code to convert character of files into bit
void CharacterOfFileToBit(long int length){


    FILE *filePointer3=fopen("inputtext.txt","rb"); //read the plain text file

    if(filePointer3==NULL){
        printf("Can't open file.");
        exit(1);
    }


    filePointer=fopen("bitText.txt","wb+"); //write the binary values on bitText file

    if(filePointer==NULL){
        printf("Can't open file.");
        exit(1);
    }

    int i=length;

    char ch;

    while(i){

        ch=fgetc(filePointer3);
        printf("%c ",ch);

        if(ch==-1){
            break;
        }

        i--;
        ConvertToBinary(ch);
        printf("\n");
    }

    fclose(filePointer3);
    fclose(filePointer);


}


void InitialPermutation(int position,int text){

    int i;
    for(int i=0;i<64;i++){
        if(initialPermutation[i]==position+1){
            break;
        }
    }
    if(i<64){
        InitialPermutatedText[i]=text;
    }

}



int F1(int i){

    int r,c,b[6];

    for(int j=0;j<6;j++){
        b[j]=X[i][j];
    }

    r = b[0]*2+b[5];
    c = 8*b[1]+4*b[2]+2*b[3]+b[4];


    if(i==0){
        return S1[r][c];
    }

    else if(i==1){
        return S2[r][c];
    }

    else if(i==2){
        return S3[r][c];
    }

    else if(i==3){
        return S4[r][c];
    }

    else if(i==4){
        return S5[r][c];
    }

    else if(i==5){
        return S6[r][c];
    }

    else if(i==6){
        return S7[r][c];
    }

    else {
        return S8[r][c];
    }


}

void ToBits(int value){
    int k,j,m;
    static int i;

    if(i%32==0){
        i=0;
    }


    for(j=3;j>=0;j--){

        m=1<<j;
        k=value&m;

        if(k==0){
            X2[3-j+i]='0'- 48; // X2 stores returned value's binary formated value
        }

        else {
            X2[3-j+i]='1'- 48;
        }
    }

    i=i+4;
}

void SBox(int XORText []){
    int k=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<6;j++){
            X[i][j]=XORText[k++];
        }
    }

    int value;
    for(int i=0;i<8;i++){
        value=F1(i);
        ToBits(value);
    }


}


void PBox(int position,int text){
    int i;
    for(i=0;i<32;i++){
        if(PermutationBox[i]==position+1){
            break;
        }
    }

    if(i<32){
        R[i]=text;
    }

}




void cipher(int Round,int mode){
    for(int i=0;i<32;i++){
        expansion_function(i,Right32bit[Round-1][i]);
    }


    for(int i=0;i<48;i++){

        if(mode==0){
            XORText[i]=XOR(ExpansionText[i],Key48Bit[Round][i]);
        }

        else{
            XORText[i]=XOR(ExpansionText[i],Key48Bit[17-Round][i]);
        }
    }


    SBox(XORText);


    for (int i=0;i<32;i++){
        PBox(i,X2[i]);
    }


    for (int i=0;i<32;i++){
        Right32bit[Round][i]=XOR(Left32bit[Round-1][i],R[i]);
    }

}


void finalPermutation(int position,int text){
    int i;

    for(i=0;i<64;i++){
        if(FinalPermutation[i]==position+1){
            break;
        }
    }
    //printf("Call %d...",i);
    if(i<64){
        EncryptedText[i]=text;
    }
    printf(" %d",EncryptedText[i]);


}



void Encryption(long int plain[]){
    filePointer =fopen("cipherText1.txt","ab+");

    for(int i=0;i<64;i++){
        InitialPermutation(i,plain[i]);
    }

    for(int i=0;i<32;i++){
        Left32bit[0][i]=InitialPermutatedText[i];
    }

    for(int i=32;i<64;i++){
        Right32bit[0][i-32]=InitialPermutatedText[i];
    }

    for(int k=1;k<17;k++){
        cipher(k,0);
        for(int i=0;i<32;i++){
            Left32bit[k][i]=Right32bit[k-1][i];
        }
    }

    for(int i=0;i<64;i++){

        if(i<32){
            CipherText[i]=Right32bit[16][i];
        }

        else{
            CipherText[i]=Left32bit[16][i-32];
        }

        finalPermutation(i,CipherText[i]);
    }

    //printf("Hello process of encryption...\n");

    for(int i=0;i<64;i++){
        fprintf(filePointer,"%d",EncryptedText[i]);
        //printf("Hello to printing text...");
    }

    fclose(filePointer);

}







void encrypt(long int length){
    FILE * fp=fopen("bitText.txt","rb");

    printf("%ld \n",length);
    long int plain[length*64];
    int i=-1;
    char ch;

    while(!feof(fp)){
        ch=getc(fp);
        plain[++i]=ch-48;
        printf(" %c %d %ld \n",ch,i,plain[i]);
        if(i==length*64-1) break;
    }

    /*cout<<endl<<endl;
    for(int i=0;i<80;i++){
        cout<<i<<" "<<plain[i]<<endl;
    }*/

    printf("Hello encryption...\n");

    for(int i=0;i<length;i++){
        printf("Hello %d....",i);
        Encryption(plain+64*i);
    }


    fclose(fp);


}



void Decryption(long int plain[]){
    filePointer=fopen("decrypted.txt","wb");

    for(int i=0;i<64;i++){
        InitialPermutation(i,plain[i]);
    }

    for(int i=0;i<32;i++){
        Left32bit[0][i]=InitialPermutatedText[i];
    }

    for(int i=32;i<64;i++){
        Right32bit[0][i-32]=InitialPermutatedText[i];
    }

    for(int k=1;k<17;k++){
        cipher(k,1);
        for(int i=0;i<32;i++){
            Left32bit[k][i]=Right32bit[k-1][i];
        }
    }

    for(int i=0;i<64;i++){
        if(i<32){
            CipherText[i]=Right32bit[16][i];
        }
        else{
            CipherText[i]=Left32bit[16][i-32];
        }
        finalPermutation(i,CipherText[i]);
    }

    for(int i=0;i<64;i++){
        fprintf(filePointer,"%d",EncryptedText[i]);
    }

    fclose(filePointer);

}



void convertToBits(int ch[]){
    int value = 0;
    for (int i= 7;i>=0;i--) {
        value+=(int)pow(2,i)*ch[7-i];
    }
    fprintf(filePointer, "%c", value);
    printf("%c \n",value);
}



void Bit_To_Char(){
    filePointer = fopen("result.txt", "ab+");
    for (int i = 0; i < 64; i = i + 8) {
        convertToBits(&EncryptedText[i]);
    }
    fclose(filePointer);
}



void decrypt(long int n){
    FILE* filePointer1=fopen("cipherText1.txt","rb");

    cout<<endl<<n<<"  "<<endl;
    long int plain[n*64];
    char ch;
    int i=-1;


    while(!feof(filePointer1)){
        ch=getc(filePointer1);
        plain[++i]=ch-48;
        cout<<i<<" "<<plain[i]<<endl;
        if(i==(n*64-1)) break;
    }

    for(int i=0;i<n;i++){
        Decryption(plain+i*64);
        Bit_To_Char();
    }

    fclose(filePointer1);

}


int main(void){

   // printf("Hello 1");

    filePointer=fopen("result.txt","wb+");
    fclose(filePointer);

    filePointer=fopen("decrypted.txt","wb+");
    fclose(filePointer);

    filePointer=fopen("cipherText1.txt","wb+");
    fclose(filePointer);

    generating16Keys();

    long int length=sizeOfFile();
    printf("The file size is %ld\n",length/8);

    CharacterOfFileToBit(length);


    encrypt(length/8);
    decrypt(length/8);


    return 0;

}




