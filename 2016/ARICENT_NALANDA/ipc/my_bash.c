#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<string.h>
#define MAX 256
void getInput(char *arg_list[], char *terminate);
void call_execv(char *arg_list[]);
void ouch()
{
	write(1,"\nMy Bash>",10);
	signal(SIGINT,ouch);
}
int main()
{

	pid_t pid;
	char *arg_list[MAX];
	char terminate[MAX];
///	signal(SIGINT,SIG_IGN);
//	signal(SIGINT,SIG_IGN);
	signal(SIGINT, ouch);
	//signal(SIGINT,SIG_IGN);
	pid = fork();
	if(0==pid)
		execl("/usr/bin/clear","clear",NULL);
	else{
		wait(NULL);
	do
	{
		write(1,"My Bash>",9);
		getInput( arg_list, terminate);
		if(arg_list[0] != NULL)
		call_execv(arg_list);

	}while(strncmp(terminate,"quit",4));	
	}
	return 0;

}

void call_execv(char *arg_list[])
{
	pid_t pid;
	
	pid = fork();
	switch(pid)
	{
		case 0:
			execvp(arg_list[0], arg_list);
			exit(0);
			break;
		case -1:	
			perror("Fork");
			break;
		default:
			wait(NULL);
		//	exit(0);
			break;
	}
}

	



void getInput( char *arg_list[], char *terminate)
{
	char buffer[MAX];
	char delimeter[] = " '\n'";
	char *token;
	int index = 0;
	memset(buffer,'\0',MAX-1);	
	read(0, buffer, MAX-1);
	
	token = strtok(buffer,delimeter);
	
	if (NULL!=token)
	strncpy(terminate, token,4);

	while(NULL != token)
	{
		arg_list[index] = strdup(token);
		token = strtok(NULL,delimeter);
		index++;
	}
	arg_list[index] = NULL;

}
