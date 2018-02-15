#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char *argv[])
{
	
	int fd,nwrite,len;
	printf(" In %s --------->\n",__FILE__);
	char *buf="Hello welcome to World of Driver .Hi friends now here I am at emblogic .It's a nice day today.I started my day,with the first Driver Class and today I learn how to use semaphore for synchonisation in driver when two writer is trying to write";
	fd=open(argv[1],O_WRONLY);

	if(fd<0)
		printf("File not opened");
	else
		printf("File opened Successfully \n");
	len=strlen(buf);
	nwrite=write(fd,buf,len);
	printf("App written  data %s \n",buf);
	printf("App written %d bytes \n",nwrite);
	close(fd);
	printf("Exit from application  --->%s",__FILE__);
	return 0;
}

