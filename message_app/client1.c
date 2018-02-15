#include"header.h"
/*
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
*/void *client_write(void *arg);
int sock_fd;
struct sockaddr_in client;
//int connect(int sock_fd,const struct sockaddr *addr,socklen_t addrlen);
static int RW_FLAG =1;
void *client_write(void *arg)
{
	struct payload buff;
	int ret;
	char buff1[BUFSIZ];//="Thread Progamming Difficult Task";
	fd_set fd_list;
	printf("Inside client writer\n");
	
	while(1)
	{
		//FD_ZERO(&fd_list);
		//FD_SET(&sock_fd,);
		//if(RW_FLAG)
	
	//	if(RW_FLAG)
	//	memset(buff1,'\0',SIZE);
		printf("Write some data for server and sockfd=%d\n",sock_fd);
		fflush(stdin);
		fgets(buff1,SIZE,stdin);
			
			ret = send(sock_fd,buff1,SIZE,0 );
			printf("Size of  Data sent :%d\n",ret);
		//	RW_FLAG = 0;
	
		if(!strncmp(buff1,"end",3))
			break;
//		sleep(5);
	//	sleep(1);
	
		
	}
	pthread_exit("Bye Bye Writer");
}	
int main()
{
	int connect_fd,res=-1,ret =-1,nread =0;
	
	struct payload buff;
	char buff2[BUFSIZ];	
	void *ret_val;
	pthread_t cw_thread;	
	pthread_attr_t t_attrbt;
	buff.write_flag =0;
	res = pthread_attr_init(&t_attrbt);
	if(res!=0)
	{
		perror("Thread attribute creation failed");
		goto OUT;
	}
	
	res = pthread_attr_setdetachstate(&t_attrbt, PTHREAD_CREATE_DETACHED);
	if(res!=0)
	{
		perror("Thread attribute init failed");
		goto OUT;
	}
	
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
	if(sock_fd==-1)
		perror("client socket not creatrd");
	client.sin_family=AF_INET;
	client.sin_port=htons(4007);
	client.sin_addr.s_addr=inet_addr("127.0.0.1");	

	//	strcpy(client.sa_data,"server_socket1");
	
	connect_fd=connect(sock_fd,(struct sockaddr *)&client,sizeof(client));
	if(connect_fd==-1)
		perror("client not connected");
	
	printf("communication channel created ....with fd =%d!!!\n",sock_fd);

	ret = pthread_create(&cw_thread, NULL , client_write,NULL );
	if(ret !=0)
		perror("Thread Not created ..!!");
	sleep(5);
	while(1)
	{
		memset(buff2,'\0',BUFSIZ);
	//	if(!RW_FLAG)
		
//		sleep(5);
//		printf("Reading data in client :..\n");
	//	do
	//	{
	//		if(!RW_FLAG)	
		
			//	RW_FLAG = 1;
				nread = recv(sock_fd,buff2,SIZE,0);
		//		if(nread)
				printf("data in client from server: at fd =%d\t%s\n",sock_fd,buff2);
		//		RW_FLAG = 1;	
		
	//	}while(!nread);
		
		//printf("data in client from server:%s",buff1);
	//	RW_FLAG = 1;		
		if(!strncmp(buff2,"end",3))
			break;	
		
//		sleep(5);
	//	RW_FLAG = 0;
			
	}
	pthread_join(cw_thread,&ret_val);
		return 0;
OUT:
	return -1;	
}
