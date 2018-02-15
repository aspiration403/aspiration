#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<assert.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
//int socket(int domain,int type,int protocol);
//int bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
//int listen(int sockfd,int backlog);
//int accept(int sockfd,struct sockaddr *client_addrs,socklen_t addrlen);
int main()
{
	int sockfd,ret_bind,fd,ret_listen,ret_accept;
	int len;
	char buff[BUFSIZ],buff1[BUFSIZ];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	printf("socket-fd is %d\n",sockfd);
	if(fd==-1)
	{
		perror("Socket not created\n ");
		assert(-1==fd);
	}
	struct sockaddr_in server1,client_addrs;
	server1.sin_family=AF_INET;
	server1.sin_port=htons(5555);
	server1.sin_addr.s_addr=INADDR_ANY;
		
//	strcpy(server1.sa_data,"server_socket1");

	len=sizeof(server1);
	ret_bind=bind(sockfd,(struct sockaddr *)&server1,len);
	if(-1==ret_bind)
	{
		perror("Bind failed \n");
	//	assert(-1==ret_bind);
	}
	ret_listen=listen(sockfd,2);
	if(-1==ret_listen)
	{
		perror("listen failed \n"); 	
	//	assert(-1==ret_listen);
	}
	ret_accept=accept(sockfd,(struct sockaddr *) &client_addrs,&len);
	if(-1==ret_accept)
	{
		perror("accept failed");
	//	assert(-1==ret_accept);
	}
	while(1)
	{
		memset(buff,'\0',BUFSIZ);
		printf("Write data for client:\n");
		fgets(buff,BUFSIZ,stdin);
		write(ret_accept,buff,BUFSIZ);
		memset(buff1,'\0',BUFSIZ);
		read(ret_accept,buff1,BUFSIZ);	
		printf("Data from client:%s\n",buff1);
		if(!(strncmp(buff,"end",3)))
			break;
		if(!(strncmp(buff1,"end",3)))
			break;

	}
	close(sockfd);	
	unlink("server_socket1");
	return 0;
}

