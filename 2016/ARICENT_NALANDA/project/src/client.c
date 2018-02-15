/***********************************************************************
 *
 * 	FILE		:	client.c
 *
 * 	DESCRIPTION	:	get input file name from user. send this file name to server.server will
 * 				read  that file and read line by line and put only line which has "Raman" 
 * 				in a line. and return that to client.
 *
 * ***************************************************************************************************/
 
#include<header.h>
#include<client.h>

int main(int argc, char *argv[])
{
	
	int sock_sd;
	int retVal = 0;                          //capture the retval
	struct sockaddr_in client;
	printf("\n Hi i am client \n");
	

	
	/*Now creating socket for communication*/

	sock_sd = socket(AF_INET, SOCK_STREAM, 0);
	if(FAILURE == sock_sd)
	{
		perror("client socket not created ");
		exit(EXIT_FAILURE);
	}
		
	/* now making address structure*/
	
	client.sin_family = AF_INET;
	client.sin_port = htons(PORT);
	client.sin_addr.s_addr = inet_addr(SERVER_IP);
		
	/*****Now try to connect*/
	
	retVal = connect(sock_sd, (struct sockaddr *)&client, sizeof(client));
	if(FAILURE == retVal)
	{
		perror("client socket connection Fail ");
		exit(EXIT_FAILURE);
	}
	

	
	
		

	return SUCCESS;
}



