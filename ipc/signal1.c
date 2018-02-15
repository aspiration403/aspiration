#include<stdio.h>
#include<signal.h>
//#include<sys/types.h>
void alarm(int sig)
{
	printf("signal Received :%d\n",sig);
/*	int n;
	scanf("%d",&n);
	printf("\n");*/
	//kill(getpid(),SIGINT);
	signal(SIGINT , SIG_IGN);
	//while(1);
}

int main()
{
	signal(SIGINT,alarm);
	printf("Hello UNcle Namste !!\n");
	
	kill(getpid(),SIGINT);

	while(1){
	printf("\n hello");
	sleep(1);}
	return 0;
}
			
