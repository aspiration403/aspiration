#include <header.h>

#define PORT 45585
#define IP "127.0.0.1"

int main()
{
	int	sd,
		ret = SUCCESS,
		conn_ret;

	char	message[BUFFER_SIZE],
		buffer[BUFFER_SIZE];

	struct sockaddr_in	server;

	memset(message, 0, BUFFER_SIZE);
	memset(buffer, 0, BUFFER_SIZE);
	memset(&server, 0, sizeof(server));

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (0 > sd)
	{
		perror(" Socket Error ");
		exit(FAILURE);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr(IP);

	conn_ret = connect(sd, (struct sockaddr*)&server, sizeof(server));
	if (0 > conn_ret)
	{
		perror(" Connect Error ");
		exit(FAILURE);
	}

	printf(" Enter message \n");
	fgets(message, BUFFER_SIZE, stdin);
	printf(" <Client>... Entered message : %s\n",message);

	ret = write_data(sd, message);
	if (-1 == ret )
	{
		perror(" Write Error ");
		exit(FAILURE);
	}

	printf(" <Client>... All Done..!!! \n");
	return SUCCESS;
}
