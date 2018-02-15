#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
void ouch(int sig,siginfo_t *siginfo,void *context)
{

	printf("We got the signal=%d \n UID= %ld\n",sig,(long)siginfo->si_uid);
	int n;
	//while(n<20000)
	scanf("%d",&n);
		
}
/*
action_ouch(int sig)
{

printf("We got the signal_action=%d",sig);
}
*/
void old_action(int sig,siginfo_t *siginfo,void *context)
{
	printf("i mean old\n");
}
int main()
{
	struct sigaction act,old_act;
	//act.sa_handler=NULL;
	int ret;
	old_act.sa_handler=&old_action;
	old_act.sa_flags=0;
	sigemptyset(&old_act.sa_mask);
//	act.sa_sigaction=action_ouch;
//	act.sa_sigaction=&ouch;
//	act.sa_flags=0;//SA_SIGINFO;
	//sigaddset(&act.sa_mask,SIGQUIT);
	ret=sigaction(SIGINT,NULL,&old_act);
	
	printf("IN main using sigaction  %d\n",ret);
	while(1);
	printf("\n Hello");
}
