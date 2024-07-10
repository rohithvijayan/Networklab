//TIME CLIENT
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
int main()
{
struct sockaddr_in serveraddr,clientaddr;
char buffer[1024];
int clientsocket=socket(AF_INET,SOCK_DGRAM,0);
printf("CLIENT SOCKET CREATED..");
memset(&serveraddr,'\0',sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(8080);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
memset(&clientaddr,'\0',sizeof(clientaddr));
clientaddr.sin_family=AF_INET;
clientaddr.sin_port=htons(8081);
clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

bind(clientsocket,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
printf("binded..");
int num=1;
time_t start_time=time(NULL);
sendto(clientsocket,&num,sizeof(num),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
addrlen=strlen(clientaddr);
recvfrom(clientsocket,&current_time,sizeof(current_time),0,(struct sockaddr*)&clientaddr,&addrlen);
rtt=time(NULL)-start_time;
current_time+=rtt/2;
printf("Server TimeL%s\n",ctime(&current_time));
return 0;
}
