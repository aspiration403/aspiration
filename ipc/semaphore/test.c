#include<stdlib.h>
#include<stdio.h>
int main()
{
	char buf[BUFSIZ];
	printf("bufsize =%d\n",BUFSIZ);
	fgets(buf,BUFSIZ,stdin);
	printf("\n data :%s",buf);	
	return 0;
}
