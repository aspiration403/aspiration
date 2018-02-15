#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
int connect(int sock_fd,const struct sockaddr *addr,socklen_t addrlen);
int main()
{
	int sock_fd,connect_fd;
	char buff[6];
	sock_fd=socket(AF_UNIX,SOCK_STREAM,0);
	if(sock_fd==-1)
		perror("client socket not creatrd");
	struct sockaddr client;
	client.sa_family=AF_UNIX;
	strcpy(client.sa_data,"server_socket1");
	
	loop :
	{	connect_fd=connect(sock_fd,&client,sizeof(client));

		if(connect_fd==-1)
		{perror("client not connected");
			sleep(1);
			goto loop;
		}
	}
	read(sock_fd,&buff,6);
	printf("data in client :%s",buff);
	close(sock_fd);
	return 0;
}
