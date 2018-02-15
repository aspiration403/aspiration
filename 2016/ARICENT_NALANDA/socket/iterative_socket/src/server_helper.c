#include<header.h>
#include<server.h>
#include<glib.h>
GSList *list = NULL;



/***************************************************************
 *
 *	FUNCTION	:	read_file
 *	
 *	DESCRIPTION	:	read_the file name from client
 *	
 *	RETURN		:	Nothing
 *
 ***************************************************************/
 
void read_file(int conn_sd)
{

	int num_file = 0;
	int index= 0;
	int data_size;
	int bytes_read = 0;
	int n = 0;		//temporary variable
	char data_len[4];
	char file[MAX_NAMELEN];

	
	
	/**************firstly receving number of file */
	recv(conn_sd, &num_file, 4, 0);
	
	num_file = ntohl(num_file);

	printf("\n Number of File :%d \n", num_file);
	
	for(index = 0; index < num_file; index++)
	{
		memset(file, '\0', MAX_NAMELEN-1);	
		/****Receiving length of file name */
		
		recv(conn_sd, &data_len, 4, 0);
		data_size = atoi(data_len);
		
		printf("\n File name length :%d ", data_size);
		/* Now reading file name*/
		while(bytes_read < data_size)
		{
			n = recv(conn_sd, file+bytes_read, data_size-bytes_read, 0);
			bytes_read = n + bytes_read;
		}	
			
		file[bytes_read] = '\0';
		bytes_read = 0;
		printf("\n Input file name : %s\n", file);
		process_file(conn_sd, file);
	}
//	show_filtered_output();
	
	send_data_to_client(conn_sd);
}


void send_data_to_client(int conn_sd)
{
	int length = 0;
	int index = 0;
	int n = 0; //temporary variable 
	int bytes_written = 0;
	char *data_to_send;
	int data_length = 0;
	char data_len[4];
	GSList *temp = list;


	length = g_slist_length(list);
	if (length == 0)
	{
		printf("\n Nothing to send \n");
		return;
	}
	
	/*fIRSTLY sending number of processed line */
	length = htonl(length);
	send(conn_sd, &length, 4, 0);	
	length = ntohl(length);	
	
	printf("\n sending data output :num_line :%d:",length);
	/*show the data present in ds*/
	
	
	for (index = 0; index < length; index++, temp = temp->next  )
	{
		if (NULL != temp)
		{
			if (NULL != temp->data)
			{
				data_length = strlen(temp->data);
			//	if (data_length <=0)
			//		continue;
				sprintf(data_len,"%d", data_length);	
				/*sending data_length first*/
				send(conn_sd, data_len, 4, 0);
				
				printf("\n data length :%d data :%s\n",data_length,(char*)temp->data);
				/*Now sending actual content*/
			//	data_to_send = strdup(temp->data);
				while (bytes_written < data_length)
				{
				
					n = send(conn_sd,((char*) temp->data)+bytes_written, data_length -bytes_written,0);
					bytes_written= n+ bytes_written;
				}
				bytes_written = 0;
			
			}
		
		}
//		temp = temp->next;
	}


}



void show_filtered_output()
{
	int length = 0;
	int index = 0;
	GSList *temp = list;
	length = g_slist_length(list);
	if (length == 0)
	{
		printf("\n Nothing to show \n");
		return;
	}
	
	printf("\n Desired output :");
	/*show the data present in ds*/
	
	
	for (index = 0; index < length; index++  )
	{
		if (NULL != temp)
		printf("\n %s ", temp->data ? (char *)temp->data : "null");
		
		temp = temp->next;
	}


}

/*****************************************************************************
 *
 * 	FUNCTION	:	Process_file
 *
 * 	DESCRIPTION	:	REad the file for particular pattern and if foun				d then store that line in a ds
 *
 * 	RETURN		:	Nothing
 * ****************************************************************************/

void process_file(int client_sd, char *file)
{

	assert(file != NULL);
	bool status = FALSE;
	/*firstly checking the validity of file*/
	status = check_file_validity(file);
	
	if (status == FALSE)
		return;
	
	put_matched_pattern_in_ds(file);

}

void put_matched_pattern_in_ds(char *file)
{
	assert(file != NULL);
	FILE *fp;
	char line[BUFSIZE];
	char *matched = NULL;
	
	/******opening the file */
	fp = fopen(file, "r");
	
	if (NULL == fp)
	{
		perror("File open error");
		return;
	}

	while (1)
	{
		memset(line, '\0', BUFSIZE-1);
		fgets(line, BUFSIZE-1, fp);
		if(feof(fp))
			break;
		/*********Now matching the pattern*/

		matched = strstr(line,"raman");
		if (NULL != matched)
		{
			list = g_slist_append(list, g_strdup(line));
		}

		
	}
	
	fclose(fp);
}

bool check_file_validity(char *file)
{
	assert(file != NULL) ;
	int retVal = -1;
	struct stat file_status;
	bool status = TRUE;

	/*Checking file for regular or not*/
	retVal = stat(file, &file_status);
	if (FAILURE == retVal)
	{
		perror("Fstat error");
		status = FALSE;
		return status;	
	}

	if (FALSE == S_ISREG(file_status.st_mode))
	{
		printf("\n Not a Regular file so not proccessing\n");
		status = FALSE;
		return status;	
	}

	if (file_status.st_size <= 0)
	{
		printf("\n No data is present in file");
		status = FALSE;
		return status;	
	
	}

	return status;
}







