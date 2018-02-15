#include<unistd.h>
#include<sys/wait.h>
int main()
{

	char *arg_list[5];
	pid_t pid;
	int c_pid,status;

	arg_list[0] = "ls";
	arg_list[1] = "-lrt";
	arg_list[2] = 0;

	pid = fork();

	if(pid == 0)
		execvp(*arg_list,arg_list);
	else
	{
		c_pid = wait(&status);
		printf("\n c_pid :%d ppid :%d",c_pid,getpid());

	}
}
