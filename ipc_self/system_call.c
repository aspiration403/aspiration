#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("Showing the process table :\n");
	system("ps -ef &");
	printf("\n Done");
	return 0;
}
