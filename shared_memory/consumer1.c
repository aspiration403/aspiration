#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include "myshm.h"
int main()
{
	struct myshm *consumer;
	void *shared_addr;
	int shem_id,run_flag =1,ret;
	
	shem_id = shmget((key_t)1234,BUFSIZ,0666 | IPC_CREAT);
	if(shem_id < 0)
	{
		perror("Shared memory not created ");
	}
	
	shared_addr = shmat(shem_id,(void *)0,0);
	if(!shared_addr)
	{
		perror("Shared memory not attched ");
	}
	printf("Shared memory attached at addrs:%x\n",shared_addr);
	consumer = (struct myshm*)shared_addr;
	
	while(run_flag)
	{
		if(consumer->data_written !=10)
		{
			printf("Waiting for data from source :\n");
			sleep(2);
		}	
		else
		{
			printf(" Data is:%s\n",consumer->data);
			
			consumer->data_written = 0;
			fflush(0);
		}
		
		if(!strncmp(consumer->data,"end",3))
		{
			run_flag = 0;
		}
	}
	ret = shmdt(shared_addr);
	if(ret < 0)
		perror("Shared memory not detached");
	
	ret = shmctl(shem_id, IPC_RMID, 0);
	if(ret < 0)
		perror("Shared memory not removed");

	return 0;
}
