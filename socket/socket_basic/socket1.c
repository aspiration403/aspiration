#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<assert.h>
#include<sys/un.h>
#include<string.h>
#include<unistd.h>
//int socket(int domain,int type,int protocol);
//int bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
//int listen(int sockfd,int backlog);
//int accept(int sockfd,struct sockaddr *client_addrs,socklen_t addrlen);
int main()
{
	int sockfd,ret_bind,fd,ret_listen,ret_accept;
	int len;
	sockfd=socket(AF_UNIX,SOCK_STREAM,0);
	printf("socket-fd is %d\n",sockfd);
	if(fd==-1)
	{
		perror("Socket not created\n ");
		assert(-1==fd);
	}
	struct sockaddr server1,client_addrs;
	server1.sa_family=AF_UNIX;
	
	strcpy(server1.sa_data,"server_socket1");
	len=sizeof(struct sockaddr);
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
	write(ret_accept,"Raman",6);	
	unlink("server_socket1");	
	return 0;
}

