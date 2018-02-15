#include<stdio.h>
int function(char (*p)[6])
{
//	char (*p)[6];
	printf("\n%s \t %s",p[0],p[1]);
	//printf("%d \t %d \t %d \t %d",*p[0],*p[1],*p[2],*p[3]);
}
int main()
{
	char a[][6]={"Raman","Rahul"};
//	char (*p)[6];
	function(a);
/*	p = a;
	printf("\n%s \t %s",p[0],p[1]);
*/	return 0;
}
