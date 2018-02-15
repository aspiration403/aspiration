#include<header.h>
#define BUFSIZE 255
void sendFileToServer(int sock_id, char *fileName )
{

	assert(fileName != NULL);

	int fileName_len;
	char len[4];
	int bytes_sent = 0;
	int sent = 0;
	
	fileName_len = strlen(fileName);
	
	sprintf(len, "%d", fileName_len);

	/****Sending firstly length of file Name */
	send(sock_id, len, 4,0);

	/************Now sending actual file name*/
	while(1)
	{	
		sent =  send(sock_id, fileName +bytes_sent, fileName_len-bytes_sent,0 );
		bytes_sent+= sent;
		
		if (bytes_sent == fileName_len)
		{
			break;
		}
	}
	printf("\n File :%s sent successfully \n", fileName);	
}	

void recieveData(int conn_sd)
{

	char *output = "output_file";
	char buffer[BUFSIZE];
	int num_of_line = 0;
	int bytes_read = 0;
	char data_length[4] ;
	int data_len = 0 ;
	int n = 0;
	int fd = 0;
	int index = 0;
	/* firstly reading num of line wich came from server side*/
	recv(conn_sd, &num_of_line, 4, 0);
	num_of_line = ntohl(num_of_line);
	if (num_of_line <= 0)
	{
		printf("\n Nothing relevent data present \n");
		return;
	}
	
	fd = open(output, O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
	if (fd < 0)
	{
		perror(" File open error");
		return;
	}	

	for(index = 0; index < num_of_line; index++)
	{
		
		recv(conn_sd, data_length, 4, 0);
	//	printf("\n data len -: %d \n",data_len);
		data_len = atoi(data_length);
	
		printf("\n data len : %d \n",data_len);
			
		memset(buffer,'\0',BUFSIZE-1);	
		/*Now reading the actual content*/
		while(bytes_read < data_len)
		{	
			n = recv(conn_sd, buffer+bytes_read, data_len-bytes_read, 0);
			bytes_read = n + bytes_read;
		}	
		write(fd, buffer, bytes_read);	
	
		bytes_read = 0;
		data_len = 0;			

	}	
	
	close(fd);	

}
