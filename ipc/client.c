#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()

{
int socket_fd,connect_fd;
struct sockaddr_in client_addr;
int n ,nread=1;
char rec_data[100]={""};
socket_fd=socket(AF_INET,SOCK_STREAM,0);
if(!socket_fd)
	{
	printf("error: cant create socket..\n");
	goto OUT;
	}
client_addr.sin_family=AF_INET;
client_addr.sin_port=htons(7000);
client_addr.sin_addr.s_addr = inet_addr("192.168.1.34");
printf("socket_fd in client is ..%d\n",socket_fd);

connect_fd=connect(socket_fd,(struct sockaddr *)&client_addr,sizeof(client_addr));

if(connect_fd)	
	{
	perror("couldnot connect to server ...\n");
	goto OUT;
	}
while(nread)
{
nread=read(socket_fd,rec_data,sizeof(int));
printf("%s",rec_data);
};
//printf("data is %s\n",rec_data);
OUT:
	return(EXIT_FAILURE);


return 0;
}




