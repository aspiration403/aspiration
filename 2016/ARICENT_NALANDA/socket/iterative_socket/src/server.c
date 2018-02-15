/***********************************************************************
 *
 * 	FILE		:	server.c
 *
 * 	DESCRIPTION	:	get input file name from client. 
 * 	 			read  that file and read line by line and put only line which has "Raman" 
 * 				in a line. and return that to client.
 *
 * ***************************************************************************************************/
 
#include<header.h>
#include<server.h>

int main(int argc, char *argv[])
{
	
	int sock_sd,
		conn_sd;                         //for exclusive client
	int retVal = 0;                          //capture the retval
	socklen_t length = 0;
	struct sockaddr_in server,client;
	char client_addr[INET_ADDRSTRLEN];
	
	/*Now creating socket for communication*/

	sock_sd = socket(AF_INET, SOCK_STREAM, 0);
	if(FAILURE == sock_sd)
	{
		perror("server socket not created ");
		exit(EXIT_FAILURE);
	}
		
	/* now making address structure*/
	
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	retVal = bind(sock_sd, (struct sockaddr *)&server, sizeof(server));
	if(FAILURE == retVal)
	{
		perror("server socket bind Fail ");
		exit(EXIT_FAILURE);
	}
	
	/*Now started listening*/
	listen(sock_sd, BACKLOG);
	
	
	/*****Now try to accept*/
	while (1)
	{
		printf("\n Server Waiting For Request ....\n");
		length = sizeof(client);
		conn_sd  = accept(sock_sd, (struct sockaddr *)&client, &length);
		if(FAILURE == conn_sd)
		{
			perror("server socket Accept Failed ");
			continue;
		}

		printf("\n client [%s] connected :\n",
			inet_ntop(AF_INET, &client.sin_addr.s_addr, client_addr, INET_ADDRSTRLEN));
		
	
		read_file(conn_sd);

		close(conn_sd);
	
	}
	

		

	return SUCCESS;
}



