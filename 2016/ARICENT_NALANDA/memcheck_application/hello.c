#include<stdio.h>
#include<string.h>
int main()
{
	char name[5] = "ramankumar";
	int i=0;
	printf("size = %d len=%d",sizeof(name),strlen(name));
	for (i =0; i<strlen(name); i++)
	{
		printf("\n %c: %d=\n",name[i],name[i]);
	}
	return 0;
}
