//tcp client
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
void main()
{
struct sockaddr_in serveraddr;
char buffer[1024];
int clientsocket=socket(AF_INET, SOCK_STREAM, 0);
printf("socket created..");
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(4444);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("connected sucesfuly..");
strcpy(buffer,"HELlo from client");
send(clientsocket,buffer,strlen(buffer),0);
recv(clientsocket,buffer,1024,0);
printf("data recieved is:%s",buffer);
}
