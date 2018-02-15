#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
//signal(SIGUSR1,handle_signal);
/*void handle_signal()
{
	printf("got a signal");
}*/
struct data
{
	int oprnd1,oprnd2;
	char oprtr;
};




