#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void *myfun(void *arg);
char name[]="Raman Kumar Pandey";
int comm_val =1;
int main()
{
	int res,i=0,j,k=2;
	int *p;
	p = malloc(sizeof(int));
	p =&k; 
	pthread_t mythread;
	void *thread_result;
	printf(" welcome Mr. %s :\n",(char *)name);
	res = pthread_create(&mythread,NULL,myfun,(void *)p);
	if(!res)
	{
		printf("Thread Created Sucessfully\n");
	}

	else
	{
		perror("Thread Creation failed");
		exit(EXIT_FAILURE);
	}
	
	while(i++<20)
	{
		if(comm_val ==1)
		{
			printf("Main..");
			comm_val = 2;
		}
		else
			sleep(1);
	}

	printf("Waiting for Thread to finish \n");

	res = pthread_join(mythread,&thread_result);
	if(!res)
	{
		printf("Thread joined Sucessfully\n");
	}
	else
	{
		perror("Thread joined failed");
	
		exit(EXIT_FAILURE);
	}	

	


	printf("Until now Waiting for finish of thread \n");
	
	printf("Now I am going to exit %s",(char *)(thread_result));
	printf("Now welcome Mr. %s :\n",(char *)name);
	
	exit(EXIT_SUCCESS);
}	
void *myfun(void *arg)
{
	int i=0;
	printf("Data Passed by main Thread =%d \n",*(int*)(arg));
	while(i++<20)
	{
		if(comm_val == 2)
		{
			printf("Thread ..");
			comm_val = 1;
		}
		else
			sleep(1);
	}
//	strcpy(name,"Pankaj");
	
	printf("Now Exit from Thread \n");
	pthread_exit("Thanks for CPU time \n"); 
}


