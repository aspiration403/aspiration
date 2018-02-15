#include<stdio.h>
#include<stdlib.h>
//#include"sub.c"

extern int sub();

int main()
{
	int a,b;
	printf(" Enter two numbers :");
	scanf("%d %d",&a,&b);
	
	if(a > b)
	{
		printf(" In if block..\n");
	}
	else
	{
		printf(" In else block..\n");
		sub();
	}
	printf(" Sum  = %d\n",a+b);

	printf("\n");
	return 0;
}
