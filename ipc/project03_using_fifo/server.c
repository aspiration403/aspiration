#include"header.h"
int main()
{
	int ret,client_rfd,sem_key;
	printf("in %s file.........\n",__FILE__);
	ret=access("client_request",F_OK);
	printf(" acess return =%d\n ",ret);
	if(ret==-1)
	{
		mkfifo("client_request",777);
	}
	else
		printf("Client_request fifo is already created !!\n");
	
	client_rfd=open("client_request",O_RDONLY |O_NONBLOCK);
	printf(" common client read fd =%d\n",client_rfd);
	sem_key=semget((key_t) 255,1,IPC_CREAT);
	if(-1==sem_key)
		perror("semaphore not created !!\n");
	else
		printf("semaphore is created and sem_id =%d\n",sem_key);
	
	unlink("client_request");
	return 0;
}
