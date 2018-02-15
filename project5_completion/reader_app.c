#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	
	printf("Entry in APP --->%s",__FILE__);
	int fd,nread,nread1,pos,pos1;
	char buf[1024],buf1[1024];
	fd=open(argv[1],O_RDONLY);
	
	if(fd<0)
		printf("File not opened");
	else
		printf("File opened Successfully \n");
	read(fd,buf,sizeof(buf));
	printf("App read  data :%s \n",buf);
/*	pos = lseek(fd,10,SEEK_SET);
	printf("return value of lseek =%d \n",pos);	
	nread=read(fd,buf,20);
	printf("App Read---->  %d bytes \n",nread);
	printf("App read  data :%s ",buf);
	printf("\n");
	pos1 = lseek(fd,2,SEEK_CUR);
	printf("return value of lseek =%d \n",pos1);	
	nread1=read(fd,buf1,sizeof(buf1));
	printf("App Read---->  %d bytes \n",nread1);
	printf("App read  New data :%s ",buf1);
*/	close(fd);
	printf("Exit from App --->%s",__FILE__);
	return 0;
}

