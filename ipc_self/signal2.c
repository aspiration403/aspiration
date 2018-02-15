#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void ouch(int sig)
{
	printf("Ouch cought a signal no.: %d \n	",sig);
}
 int main()
{
 	signal(SIGINT,ouch);
	while(1)
	{
		printf("Hello inside main \n");
		sleep(1);
	}

return 0;
}
