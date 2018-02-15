#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include "myshm.h"
#define TEXT_SIZE 2048
int main()
{
	struct myshm *source;
	void *shared_addr;
	char buff[TEXT_SIZE];
	int shm_id,run_flag =1,ret;
	
	shm_id = shmget((key_t)1234,BUFSIZ,0666 | IPC_CREAT);
	if(shm_id < 0)
	{
		perror("Shared memory not created ");
	}
	
	shared_addr = shmat(shm_id,(void *)0,0);
	if(!shared_addr)
	{
		perror("Shared memory not attched ");
	}
	printf("Shared memory attached at addrs:%x\n",shared_addr);
	source = (struct myshm*)shared_addr;
	
	while(run_flag)
	{
		if(source->data_written !=5)
		{
			printf("Write Data(write end to exit) :\n");
			fgets(buff,TEXT_SIZE,stdin);
			strncpy(source->data,buff,BUFSIZ);
			
			source->data_written = 10;
		}
		if(!strncmp(source->data,"end",3))
		{
			run_flag = 0;
		}
	}
	shmdt(shared_addr);
	if(ret < 0)
		perror("Shared memory not detached");
	ret = shmctl(shm_id,IPC_RMID,0);
	if(ret < 0)
		perror("Shared memory not removed");

	return 0;
}
