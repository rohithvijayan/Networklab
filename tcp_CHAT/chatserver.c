//CHAT SERVER
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include<arpa/inet.h>
int main()
{
struct sockaddr_in serveraddr,newaddr;
char buffer[1024];
pid_t childpid;
socklen_t addr_size;
//create socket
int serversocket=socket(AF_INET,SOCK_STREAM,0);
printf("server socket created>..");
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(6666);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
//binding
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("binding done...");
listen(serversocket,6);
printf("listening....");
while(1)
	{
	 addr_size=sizeof(newaddr);
	 int newsocket=accept(serversocket,(struct sockaddr*)&newaddr,&addr_size);
	 if(childpid==fork()==0)
	 {
	 	close(serversocket);
	 	while(1)
	 	{
	 	 int len=recv(newsocket,buffer,sizeof(buffer),0);
                 buffer[len] = '\0';  // Null-terminate the received data
	 	 printf("client: %s\n",buffer);
	 	 send(newsocket,buffer,len,0);
	 	}
	 	close(newsocket);
	 	exit(0);
	 }
	 close(newsocket);
	}
	return 0;
}

