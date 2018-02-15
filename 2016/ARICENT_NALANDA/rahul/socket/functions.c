#include <header.h>
int read_data(int sd, char buffer[])
{
	int	len = 0,
		len2 = 0,
		ret = FAILURE,
		bytes_written = 0;
		
		ret = read(sd, &len2, sizeof(int));
		len = ntohs(len2);

		printf(" len : %d\n",len);	
		while(bytes_written < len)
		{
			ret = read(sd, (buffer + bytes_written), (len - bytes_written));
			if (0 > ret)
			{
				perror(" Write Error ");
				exit(FAILURE);
			}
			bytes_written = bytes_written + ret;
		}
	buffer[bytes_written + 1] = '\0';
	printf(" In read_data(),Data in Buffer : %s",buffer);
	return SUCCESS;
}
/* ----------------------------------------------------------------------- */
int write_data(int sd, char *buffer)
{
	int	len = 0,
		len2 = 0,
		ret = FAILURE,
		bytes_written = 0;
		
		len = strlen(buffer);
		printf(" Length of data in buffer : %d\n",len);
		len2 = htons(len);
		printf(" In write_data(), Data in buffer : %s\n",buffer);
		ret = write(sd, &len2, sizeof(int));
	
		while(bytes_written < len)
		{
			ret = write(sd, (buffer + bytes_written), (len - bytes_written));
			if (0 > ret)
			{
				perror(" Write Error ");
				exit(FAILURE);
			}
			bytes_written = bytes_written + ret;
		}
	
	return SUCCESS;
}
