// udp client
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/udp.h>
int main()
{
struct sockaddr_in serveraddr;
char * hello="HELLO FROM CLIENT";
int clientsocket=socket(AF_INET,SOCK_DGRAM,0);
printf("SOCKET CREATED...");
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(5555);
serveraddr.sin_addr.s_addr=INADDR_ANY;
sendto(clientsocket,(char *)hello,strlen(hello),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("SEND DATA...");
close(clientsocket);
return 0;
}

