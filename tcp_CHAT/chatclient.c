//chat client
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
int main()
{
struct sockaddr_in serveraddr;
char buffer[1024];
int clientsocket=socket(AF_INET,SOCK_STREAM,0);
printf("CLient socket created..");
memset(&serveraddr,'\0',sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(6666);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("connected to server..");
while(1)
{
	printf("CLIENT INPUT:");
	scanf("%s",&buffer);
	send(clientsocket,buffer,strlen(buffer),0);
	recv(clientsocket,buffer,1024,0);
	printf("SERVER: %s\n",buffer);
}
return 0;
}
