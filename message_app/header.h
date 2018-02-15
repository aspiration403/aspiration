#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<pthread.h>
#include<arpa/inet.h>
#include<netinet/in.h> //for sockaddr_in
#define SIZE BUFSIZ
struct  payload
{
	char data[SIZE];
	char *addrs;	
	int write_flag;
};
