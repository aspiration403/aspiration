/***********************************************************************************
 *
 * 	FILE NAME	:	main.c
 *
 * 	Description	:	create the thread for reader and writer
 *
 * 	DATE		NAME		REFERENCE	REASON
 *
 * 	CopyRight@2016,Aricent inc
 * **********************************************************************************/
#include<header.h>

int main()
{
	int num_reader;
	int num_writer;
	int index = 0;
	int retVal = 0;

	printf("\n Enter Number of Reader :");
	scanf("%d",&num_reader);
	
	printf("\n Enter Number of Writer :");
	scanf("%d",&num_writer);

	sem_init(&sem_reader, 0, 1);
	sem_init(&sem_resource, 0, 1);

	/*Creating thread for writer */
	pthread_t reader_thread[num_reader];
	pthread_t writer_thread[num_writer];

	for (index = 0; index < num_reader; index++ )
	{
		retVal = pthread_create(&reader_thread[index], NULL, reader, NULL);
		if (0!=retVal)
		{
			perror("Thread Creation Error");
		}
	}
	
	for (index = 0; index < num_writer; index++ )
	{
		retVal = pthread_create(&writer_thread[index], NULL, writer, NULL);
		if (0!=retVal)
		{
			perror("Thread Creation Error");
		}
	}

	for (index = 0; index < num_reader; index++ )
	{
		retVal = pthread_join(reader_thread[index], NULL);
		if (0!=retVal)
		{
			perror("Thread join Error:Reader");
		}
	}

	for (index = 0; index < num_writer; index++ )
	{
		retVal = pthread_join(writer_thread[index], NULL);
		if (0!=retVal)
		{
			perror("Thread join Error:Writer");
		}
	}

	sem_destroy(&sem_reader);
	sem_destroy(&sem_resource);
	return 0;
}




