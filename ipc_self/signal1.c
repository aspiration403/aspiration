#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
 int Alarm = 1;
void ouch(int sig)
{
	Alarm = 0;
}
 int main()
{
	pid_t pid;
	signal(SIGALRM,ouch);
	printf("Now learning Signal programming...\n");
	pid = fork(); 
	switch(pid)
	{
		case -1 :
			perror("Fork Error");
			exit(EXIT_FAILURE);
			break;
		case 0:
			sleep(5);
			printf("Inside Child Process pid=%d\n",getpid());
			kill(getppid(),SIGALRM);
			break;
		default:
			printf("Inside Parent Process pid=%d\n",getpid());
			
			while(Alarm)
			{
				printf("Executing Parent pid =%d \n",getpid());
				sleep(1);
				
			}
			
			break;
	}	
return 0;
}
