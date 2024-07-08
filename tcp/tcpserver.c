#//TCP SERVER
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

void main()
{
struct sockaddr_in serveraddr,clientaddr;
char buffer[1024];
int serversocket=socket(AF_INET,SOCK_STREAM,0);
printf("Socket created...");
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(4444);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("bind to port number..");
listen(serversocket,6);
printf("listening...");

int addrsize=sizeof(clientaddr);
int newsocket=accept(serversocket,(struct sockaddr*)&clientaddr,&addrsize);

recv(newsocket,buffer,1024,0);
printf("DATA RECIEVED>..%s\n",buffer);

strcpy(buffer,"hello from server");
send(newsocket,buffer,strlen(buffer),0);
}
