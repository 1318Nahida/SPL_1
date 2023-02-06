#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>

void error(const char *message){
    perror(message);
    exit(1);
}


int main(int argc,char *argv[]){

    if(argc<2){
        fprintf(stderr,"You have not provided the port number.Programme is terminated.\n");
        exit(1);
    }

    int socketfd,newSocketfd,portNumber,n;
    char array[255];
    struct sockaddr_in server_addr,client_addr;
    socklen_t clientAddressLength;

    socketfd=socket(AF_INET,SOCK_STREAM,0);

    if(socketfd<0){
        error("There is an error to open a socket.");
    }

    bzero((char*)&server_addr,sizeof(server_addr));

    portNumber=atoi(argv[1]);

    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=INADDR_ANY;
    server_addr.sin_port=htons(portNumber);

    if(bind(socketfd,(struct sockaddr *)&server_addr,sizeof(server_addr))){
        error("There is an error on binding procedure.");
    }

    listen(socketfd,5);

    clientAddressLength=sizeof(client_addr);

    newSocketfd=accept(socketfd,(struct sockaddr *)& client_addr,&clientAddressLength);

    if(newSocketfd<0){
        error("There is an error on accepting process.");
    }

    FILE *filePointer2;
    int ch=0;
    filePointer2=fopen("TextfileReceived.txt","w");

    int words;

    read(newSocketfd,&words,sizeof(int));

    while(ch!=words){
        read(newSocketfd,array,255);
        fprintf(filePointer2,"%s ",array);
        ch++;
    }

    printf("File has been received successfully.");

    close(newSocketfd);
    close(socketfd);

    return 0;

}

