
#include<stdio.h>
#include<string.h>
//#include<sys/socket.h>
#include<sys/types.h>
#include<assert.h>
//#include<sys/un.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
//int connect(int sock_fd,const struct sockaddr *addr,socklen_t addrlen);
int main()
{
	int sock_fd,connect_fd;
	char buff[6];
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
	if(sock_fd==-1)
		perror("client socket not creatrd");
	struct sockaddr_in client;
	client.sin_family=AF_INET;
	client.sin_port=htons(4555);
	client.sin_addr.s_addr=inet_addr("127.0.0.1");	
//	strcpy(client.sa_data,"server_socket1");
	
	connect_fd=connect(sock_fd,(struct sockaddr_in *)&client,sizeof(client));
	if(connect_fd==-1)
		perror("client not connected");
	read(sock_fd,&buff,6);
	printf("data in client :%s",buff);
	close(sock_fd);
	return 0;
}
