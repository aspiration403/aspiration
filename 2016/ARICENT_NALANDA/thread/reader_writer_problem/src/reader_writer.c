/********************************************************************************888
 * 	FILE NAME	:	reader_writer.c
 * 	DESCRIPTION	:	Contains the function for reader and writer thread handler
 * ********************************************************************************************/

#include<header.h>

static int reader_count = 0;

void *reader()
{
	printf("\nI am %s for thread:%lu \n",__func__,pthread_self());
		
	if (reader_count == 0)
	{
		sem_wait(&sem_resource);
	}	
	
	sem_wait(&sem_reader);
	
	reader_count = reader_count +1;

	sem_post(&sem_reader);        //Allowing some other reader to read db
	
//	read_db();

	sem_wait(&sem_reader);
	reader_count = reader_count-1;
	
	if (reader_count == 0)
	{
		sem_post(&sem_resource);
	}	
	sem_post(&sem_reader);
	
	pthread_exit(NULL);
}



/******************************************************************************
 *
 * FUNCTION	:	Writer
 * DESCRIPTION	:	Responsible for write,[NOTE: Only one writer can have access of shared resource /database at a time]
 * ***************************************************************************/

void *writer()
{
	printf("\nI am %s for thread:%lu \n",__func__,pthread_self());
	
	sem_wait(&sem_resource);
//	write_resource();		
	sem_post(&sem_resource);

	pthread_exit(NULL);
}

/**************************************************************************
 *
 *
















