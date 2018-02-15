#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
	int fd,nread,i=0;
//	char data;
	char buff[100];
//	char buff[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//i = strlen(buff);
//	printf("String length =%d\n",i);
	if(argc<2)
	{
		perror("Insufficient Argument Error");
		exit(1);
	}
	fd = open(argv[1],O_RDONLY);
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
	nread = read(fd,buff,100);
	
	printf("No. of bytes read and char in app :%d \t %s\n",nread,buff);
	close(fd);
	return 0;
}
