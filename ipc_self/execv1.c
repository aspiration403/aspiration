#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	char *const argv[]={"./hello",0};
	printf(" running hello program and pid=%d:\nparent pid=%d\n",getpid(),getppid());
	execv("hello",argv);	
	printf("Done..\n");
	return 0;
}
