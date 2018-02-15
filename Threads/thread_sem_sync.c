#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<string.h>
#define BUFSIZE 1024

char buffer[BUFSIZE];
void *thread_func(void *);
//int sem_init(sem_t *sem,int pshared,unsigned int value) //pshared control semaphore between process

sem_t sem;
int main()
{
	int ret;
	pthread_t word_count;	
	void *thread_result;
	 sem_init(&sem,0,0);
	ret = pthread_create(&word_count,NULL,thread_func,NULL);
	if(ret!=0)
	{
		perror("Thread Creation failed \n");
		exit(EXIT_FAILURE);
	}
	
	printf("Input Some text and Enter end for exit from software... \n");
	while(strncmp("end",buffer,3))
	{
	/*	fgets(buffer,BUFSIZE,stdin);
		sem_post(&sem);*/
		if(strncmp("raman",buffer,3)==0)
		{
			strcpy(buffer,"Welcome");
		}
		else
		{
			fgets(buffer,BUFSIZE,stdin);
		}
		sem_post(&sem);
	
		
	}	
	printf("Waiting for thread for finish \n"); 
	ret = pthread_join(word_count,&thread_result);
	if(ret!=0)

	{
		perror("Thread joined failed \n");
		exit(EXIT_FAILURE);
	}
	
	
	printf("Data you Entered :\n %s",buffer);
	printf("Exit :%s",(char*)thread_result);
	sem_destroy(&sem);
	exit(EXIT_SUCCESS);

}

void *thread_func(void *arg)
{
	sem_wait(&sem);
	while(strncmp("end",buffer,3))
	{
		printf("No. of bytes written :%d\n ",strlen(buffer)-1);
		sem_wait(&sem);
	}
	pthread_exit("End of Thread");	
}









