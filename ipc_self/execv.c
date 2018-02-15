#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	char *const argv[]={"ps","ax",0};
	printf("Printing ps using execv :\n");
	execv("/bin/ps",argv);	
	printf("Done..\n");
	return 0;
}
