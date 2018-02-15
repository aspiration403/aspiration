#include<stdio.h>
int main(int argc, char *argv[])
{
	FILE **fp;
	FILE **temp = NULL;	
	FILE *fpc;
	char buffer[255];
	fpc = fopen(argv[1],"r");
	while(1)
	{
		fgets(buffer, 254,fpc);
		if(feof(fpc))
		break;
	printf("%s",buffer);
	}
//	printf("\n size = %d",sizeof(fp));
	return 0;

}
