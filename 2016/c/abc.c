#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p = (int *)malloc(sizeof(int) * 3);
	p[3] = 20;
	free(p);
	return 0;
}
