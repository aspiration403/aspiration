#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int fd,nwrite,i;
	char buff ;
	if(argc<2)
	{
		perror("Insufficient Argument Error");
		exit(1);
	}
	fd = open(argv[1],O_WRONLY);
	if(fd<3)
	{
		perror("File not opened successfully\n");
		exit(1);
	}
	for(i=0;i<10;i++)
	{
		printf("Enter character : \n");
		scanf(" %c",&buff);	

		nwrite = write(fd,&buff,1);	
		printf("No. of bytes written :%d\n",nwrite);
	}
	return 0;
}
