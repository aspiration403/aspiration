#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void ouch(int sig)
{
	printf("I cought signal %d\n ",sig);
	kill(getpid(),SIGALRM);
}

int main()
{
	
	struct sigaction act;
	int ret;
	act.sa_handler = ouch;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	ret =sigaddset(&act.sa_mask,SIGALRM);	
	printf("REturn =%d \n",ret);
	sigprocmask(SIG_BLOCK,&act.sa_mask,0);
	sigaction(SIGINT,&act,0);
	
	while(1)
	{
		printf("Hello I am inside main...\n");
		sleep(1);
	}
  	
return 0;
}
