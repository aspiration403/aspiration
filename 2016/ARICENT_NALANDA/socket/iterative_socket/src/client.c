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
	int index = 0;
	int num_file = 0;
	printf("\n Hi i am client \n");
	
	/* verify for input file */

	if (argc < 2)
	{
		printf("\n Insufficient Argument :Format :[a.out input_file_list pattern_to_match ]\n");
		exit(EXIT_FAILURE);

	}
	
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
	
	/*Firstly sending  number of input files to server*/
	num_file = argc-1;
	num_file = htonl(num_file);
	send(sock_sd, &num_file, 4, 0);

	
	
		
	for(index = 1; index < argc; index++)
	{
	
		sendFileToServer(sock_sd, argv[index]);
	}

	recieveData(sock_sd);

	return SUCCESS;
}



