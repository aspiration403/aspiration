#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
 int main()
{
	int i=0,exit_code;
	char *name;
	pid_t pid;
	printf("Hello...\n");	 	
	pid = fork();
	
	switch(pid)
	{
		case 0:
			printf("pid of child process =%d\n",getpid());
			i=10;
			name = "child";
			exit_code = 37;
			break;
		case -1:
			perror("Fork failed");
			exit(EXIT_FAILURE);
		default:
			printf("pid of  parent process =%d\n",getpid());
			i = 5;
			name = "Parent";
			exit_code = 0;
			
	}
	while(i)
	{
		printf("%s process is running pid=%d\n",name,getpid());
		sleep(1);
		i--;
	}
	
	if(pid)
	{
		int stat_val;
		pid_t c_pid;
		c_pid = wait(&stat_val);
		if(WIFEXITED(stat_val))
		{
			printf("Child %d exited with exit_code :%d",c_pid,WEXITSTATUS(stat_val));

		}
		
	}
	

	exit(exit_code);

}
