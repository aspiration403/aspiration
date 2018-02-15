#include<stdio.h>
#include <stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main()
{
	int sd =socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in s_addr;
	//s_addr.sin_family = AF_INET;
	//s_addr.sin_port = htons(10234);
	//s_addr.sin_addr.s_addr = inet_addr("10.203.161.8");
	printf(" Sizeof s_addr : %d\n",sizeof(s_addr));
	printf("\n");
	return 0;
}
