#include<stdio.h>
int main()
{
	printf("Hello i am learning process replacement\n");
	printf("I will call by execl and my pid =%d and ppid=%d\n",getpid(),getppid());	
	return 0;
}
