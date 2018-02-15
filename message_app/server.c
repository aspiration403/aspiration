/*#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<assert.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
*/
#include "header.h"
int ret_accept;
void *writer();
static int RW_FLAG =1;
//int socket(int domain,int type,int protocol);
//int bind(int sockfd,const struct sockaddr *addr,socklen_t addrlen);
//int listen(int sockfd,int backlog);
//int accept(int sockfd,struct sockaddr *client_addrs,socklen_t addrlen);
void *writer()
{
	char buff[BUFSIZ];//="Hello Emblogic";
	printf("Value of ret_accept :%d\n",ret_accept);
	sleep(5);
	while(1)
	{
		memset(buff,'\0',BUFSIZ);
		printf("Write data for client:\n");
		fgets(buff,BUFSIZ,stdin);
	//	RW_FLAG = 0;
		send(ret_accept,buff,BUFSIZ,0);
		if(!(strncmp(buff,"end",3)))
			break;
	//	RW_FLAG = 1;
	//	sleep(5);
	}
	pthread_exit("Bye bye Client");
	

}
int main()
{
	int sockfd,ret_bind,fd,ret_listen;
	int len,ret;
	void *retval;
	pthread_t tid;
	char buff1[BUFSIZ];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	printf("socket-fd is %d\n",sockfd);
	if(fd==-1)
	{
		perror("Socket not created\n ");
	//	assert(-1==fd);
		goto OUT;
	}
	struct sockaddr_in server1,client_addrs;
	server1.sin_family=AF_INET;
	server1.sin_port=htons(5000);
	server1.sin_addr.s_addr=INADDR_ANY;
		
//	strcpy(server1.sa_data,"server_socket1");

	len=sizeof(server1);
	ret_bind=bind(sockfd,(struct sockaddr *)&server1,len);
	if(-1==ret_bind)
	{
		perror("Bind failed \n");
	//	assert(-1==ret_bind);
		goto OUT;
	}
	ret_listen=listen(sockfd,100);
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

	read(ret_accept,&ip_addr,sizeof(int));
	
	
	ret = pthread_create(&tid,0,writer,0);
	if(-1==ret)
	{
		perror("Thread creation failed \n"); 	
	//	assert(-1==ret_listen);
		goto OUT;	
	}
	printf("Now connection is established\n");
	
	while(1)
	{
	/*	memset(buff,'\0',BUFSIZ);
		printf("Write data for client:\n");
		fgets(buff,BUFSIZ,stdin);
		write(ret_accept,buff,BUFSIZ);
	*/	//if(RW_FLAG)
	//	{
	//	sleep(2);
			printf("Main Thread Running \n");
			memset(buff1,'\0',BUFSIZ);
			recv(ret_accept,buff1,BUFSIZ,0);	
			printf("Data from client:%s\n",buff1);
			if(!(strncmp(buff1,"end",3)))
			break;
	//	}
		//RW_FLAG = 0;
	//	sleep(5);
	}
	printf("Inside Main Thread");
	pthread_join(tid,&retval);
	printf("%s",(char *)retval);
	close(sockfd);	
	//unlink("server_socket1");
	return 0;
OUT:
	return -1;
}

