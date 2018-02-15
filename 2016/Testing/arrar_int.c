#include<stdio.h>
void function1(int *p);
void function(int (*p)[3])
{
	int (*q)[3];
	q = p;
	printf("\n%d \t %d",q[0][0],p[1][1]);
	//printf("%d \t %d \t %d \t %d",*p[0],*p[1],*p[2],*p[3]);
}
int main()
{
	int a[][3]={{1,2,3},{3,4,5}};
//	char (*p)[6];
	extern int x;
	function(a);

	printf("\n x = %d \n",x);
	function1(a);
/*	p = a;
	printf("\n%s \t %s",p[0],p[1]);
*/	return 0;
}
int x = 5;
void function1(int *p)
{
//	int (*q)[3];
//	q = p;
	printf("\n x = %d ",x);
//	printf("\n%d \t %d",q[0][0],p[1][1]);
	//printf("%d \t %d \t %d \t %d",*p[0],*p[1],*p[2],*p[3]);
}
