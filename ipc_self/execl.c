#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	printf(" Printing Process Table with exec :\n");
	execl("/bin/ps","ps","-ef",0);
	printf("\n Done");

	return 0;

}	
