#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	
	printf("Entry in App --->%s",__FILE__);
	int fd,nread;
	char buf[1024];
	fd=open(argv[1],O_RDONLY);
	
	if(fd<0)
		printf("File not opened");
	else
		printf("File opened Successfully \n");
	
	nread=read(fd,buf,sizeof(buf));
	printf("App Read---->  %d bytes \n",nread);
	printf("App raed  data %s \n",buf);
	close(fd);
	printf("Exit from App --->%s",__FILE__);
	return 0;
}

