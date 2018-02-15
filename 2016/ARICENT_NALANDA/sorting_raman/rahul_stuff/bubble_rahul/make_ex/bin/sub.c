#include<stdio.h>
#include<stdlib.h>

int sub()
{
	int a,b;
	printf(" Enter two values to subtract :");
	scanf("%d %d",&a,&b);
	if (a > b)
	{
		printf(" In IF block, After subtraction : %d\n",a-b);
	}
	else
	{
		printf(" In ELSE block, After subtraction : %d\n",a-b);
	}
	printf(" \n");
	return 0;
}
