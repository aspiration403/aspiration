#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int i=1;
	char *name;
	pid_t pid;
	printf("Hello I am learning process duplication :FORK\n My pid =%d and ppid=%d",getpid(),getppid());
	printf("\n Now using fork \n");
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("FORK FAILURE");
			break;	
		case 0:
			
			printf("Now Child process running pid=%d\n",getpid());
			i=50;
			name = "child is running";
			break;
		default:
		
			printf("Parent Process Running pid =%d\n",getpid());
			i=3;
			name ="parent is running";
			
			break;
	}
	while(i>0)
	{	
		puts(name);
		sleep(1);
		i--;		
	 } 	
return 0;
}
