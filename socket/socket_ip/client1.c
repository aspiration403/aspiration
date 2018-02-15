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
	int sock_fd,connect_fd,nread;
	char buff[BUFSIZ],buff1[BUFSIZ];
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
	if(sock_fd==-1)
		perror("client socket not creatrd");
	struct sockaddr_in client;
	client.sin_family=AF_INET;
	client.sin_port=htons(5555);
	client.sin_addr.s_addr=inet_addr("127.0.0.1");	
//	strcpy(client.sa_data,"server_socket1");
	
	connect_fd=connect(sock_fd,(struct sockaddr *)&client,sizeof(client));
	if(connect_fd==-1)
		perror("client not connected");
		memset(buff,'\0',BUFSIZ);
	while(1)
	{
		
	do{
			nread = read(sock_fd,buff,BUFSIZ);
			if(nread)
			printf("data From server :%s\n",buff);
		  }while(!nread);
///	printf("data From server :%s\n",buff);
		memset(buff1,'\0',BUFSIZ);
		printf("Write data for server(end for exit) :\n");
		fgets(buff1,BUFSIZ,stdin);
		fflush(stdin);
		write(sock_fd,buff1,BUFSIZ);
		if(!(strncmp(buff,"end",3) ))
					break;
		if(!(strncmp(buff1,"end",3) ))
					break;
		
	}	
		close(sock_fd);
	return 0;
}
