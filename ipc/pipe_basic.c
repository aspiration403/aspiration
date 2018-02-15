#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd[2],nwrite,fork_ret;
	char Read_fd[4];
	static int a=2;	


	printf("In main program with pid %d and value of a=%d\n",getpid(),a);

	if(0!=pipe(fd))
	{
		perror("Pipe not Created ");
		exit(1);
	}

	nwrite=write(fd[1]," Hello",6);
	sprintf(Read_fd,"%d",fd[0]);
	if(nwrite==0)
	{
		perror("Data not written ");
		exit(1);
	}
	fork_ret=fork();

	
	if(0==fork_ret)
	{
		sleep(1);
		printf("we are inside a child process with pid =%d and a=%d and addr %u\n",getpid(),a,&a);
		execl("./execl_example","execl_example",Read_fd,NULL);
	}
	else if(fork_ret>0)
	{
	//	sleep(1);
		a=5;	
		printf("in parent process pid %d and value of a=%d and addr %u \n",getpid(),a,&a);
	}
	else
	{
		perror("Fork error");
		exit(1);
	}
	

	//printf("value of a=%d\n",a);
	 
		
	 		
	return 0;
}
