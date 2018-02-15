#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int fd,nwrite,i;
	//char buff[]= "ABCDEFGHIJKLMNOPQRTUVWXYABCDEFGHIJKLMNOPQRSTUVWXYABCDEFGHIJKLMNOPQRSTUVWXYZz";
	char buff[100] ;
	//printf("String length =%d\n",i);
	printf("enter a string\n");
	fgets(buff,100,stdin);
	i = strlen(buff);
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
/*	for(i=0;i<10;i++)
	{
		printf("Enter character : \n");
		scanf(" %c",&buff);	

		nwrite = write(fd,&buff,1);	
		printf("No. of bytes written :%d\n",nwrite);
	}*/
	nwrite = write(fd,buff,i);
	
	printf("No. of bytes written :%d\n",nwrite);
	close(fd);
	return 0;
}
