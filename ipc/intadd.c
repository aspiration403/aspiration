#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *str="hello";
	int a=1;
	char ch[6];
	sprintf(ch,"clientr%d",1);

	//strcat(str,ch);
	printf("%s",ch);
	return 0;
}
