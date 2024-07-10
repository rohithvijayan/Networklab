//time server
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/udp.h>
int main()
{
struct sockaddr_in serveraddr,clientaddr;
char buffer[1024];
socklen_t addr_size;
int serversocket=socket(AF_INET, SOCK_DGRAM, 0);
printf("socket created..");
memset(&serveraddr, 0, sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(8080);
serveraddr.sin_addr.s_addr=INADDR_ANY;
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("binded...");
while(1)
	{
		addr_size=sizeof(clientaddr);
		int len=recvfrom(serversocket,(struct sockaddr*)&clientaddr,&addr_size);
		buffer[len]='\0';
		printf("CLIENT: %s",buffer);
		//ger current time
		time_t t;
		time(&t);
		snprintf(buffer,1024,"current time:%s",ctime(&t));
		sendto(serversocket,buffer,strlen(buffer),0,(struct sockaddr*)&clientaddr,addr_size);
	
	}
	return 0;
}

