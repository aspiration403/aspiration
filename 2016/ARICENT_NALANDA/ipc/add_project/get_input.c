#include"header.h"

int main()
{
	int fd[2];
	int result;
	pid_t pid;
	char a[4],b[4];
	char fd_w[4];
	printf(" Enter two numbers :");
	scanf("%s%s",a,b);


	pipe(fd);
	sprintf(fd_w ,"%d",fd[1]);
	pid = fork();
	switch(pid)
	{
		case 0:
			close(fd[0]);
			execlp("./add_process","add_process",a,b,fd_w ,NULL);
			break;
		case -1:
			break;
		default:
			wait(NULL);
			close(fd[1]);
			read(fd[0],&result,4);
			printf("output:%d\n",result);
			close(fd[0]);
			break;

	}	
}


