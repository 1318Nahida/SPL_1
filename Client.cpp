#include<bits/stdc++.h>
#include <cstddef>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<ctype.h>

void error(const char *message){
    perror(message);
    exit(1);
}

int main(int argc,char *argv[]){

    int socketfd,portNumber,n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    char array[255];

    if(argc<3){
        fprintf(stderr,"usage %s hostname port\n",argv[0]);
        exit(1);
    }

    portNumber=atoi(argv[2]);

    socketfd=socket(AF_INET,SOCK_STREAM,0);

    if(socketfd<0){
        error("There is an error on opening a socket.");
    }

    server=gethostbyname(argv[1]);

    if(server==NULL){
        fprintf(stderr,"There is no such host.");
    }

    bzero((char*)&server_addr,sizeof(server_addr));

    server_addr.sin_family=AF_INET;

    bcopy((char *)server->h_addr,(char *)&server_addr.sin_addr.s_addr,server->h_length);

    server_addr.sin_port=htons(portNumber);

    if(connect(socketfd,(struct sockaddr *)&server_addr,sizeof(server_addr))<0){
        error("There is failure on creating connection.");
    }

    bzero(array,255);

    FILE *filePointer1;
    int words=0;

    char c;

    filePointer1=fopen("Textfile.txt","r");

    while((c=getc(filePointer1))!=EOF){
        fscanf(filePointer1,"%s",array);
        if(isspace(c)||c=='\t'){
            words++;
        }

    }

    write(socketfd,&words,sizeof(int));

    rewind(filePointer1);
    char ch;

    while(ch!=EOF){
        fscanf(filePointer1,"%s ",array);
        write(socketfd,array,255);
        ch=fgetc(filePointer1);
    }

    printf("The file has been successfully sent.Thank you.");


    close(socketfd);
    return 0;

}


