#include <header.h>

#define MY_PORT 45585
#define NUM_CLIENT 5

int main()
{
	int	sd,
		new_sd,
		ret = SUCCESS,
		bind_ret = SUCCESS,
		lis_ret = SUCCESS;

	char	buffer[BUFFER_SIZE];
		
	struct sockaddr_in	server,
				client;

	socklen_t	client_len;

	memset(&server,0,sizeof(server));
	memset(&client,0,sizeof(client));
	memset(buffer,0,BUFFER_SIZE);
	
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (0 > sd)
	{
		perror(" Socket Error ");
		exit(FAILURE);
	}
		
	server.sin_family = AF_INET;
	server.sin_port = htons(MY_PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	bind_ret = bind(sd, (struct sockaddr*)&server, sizeof(server));	
	if (0 > bind_ret)
	{
		perror("  Bind Error ");
		exit(FAILURE);
	}	
	lis_ret = listen(sd, NUM_CLIENT);
	if (0 > lis_ret)
	{
		perror(" Listen Error ");
		exit(FAILURE);
	}

	while (1)
	{
			printf(" <Server> Waiting for client....\n");
			client_len = sizeof(client);
			new_sd = accept(sd, (struct sockaddr*)&client, &client_len);
			if (0 > new_sd)
			{
				perror(" Accept Error ");
				exit(FAILURE);
			}
			ret = read_data(new_sd, buffer);
			if (FAILURE == ret)
			{
				perror(" Read Error ");
				exit(FAILURE);
			}
		printf(" <Server>... Data received : %s\n",buffer);
		
		close(new_sd);	
	}	
	close(sd);
	printf(" <Server>... All Done..!!! \n");
	return SUCCESS;
}






