#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char *argv[])
{
	
	int fd,nwrite,len,fd1;
	//char *buf1="My Name is Raman";
	char *buf="Hello welcome to World of Driver .Hi friends now here I am at emblogic .It's a nice day today.I started my day,with the first Driver Class and today I ate chicken pizza in morning";
	fd = open(argv[1],O_WRONLY);
	
	if(fd<0)
		printf("File not opened");
	else
		printf("File opened Successfully :fd =%d\n",fd);
	len=strlen(buf);
	nwrite=write(fd,buf,len);
	//printf("App written  data %s \n",buf);
	printf("App written %d bytes \n",nwrite);


//	printf(" Second time writting start \n");
/*	fd1 = open("tarzan",O_WRONLY);

	if(fd1<0)
		printf("File not opened");
	else

	len=strlen(buf1);
	nwrite=write(fd1,buf1,len);
	printf("App written  data %s \n",buf1);
	printf("App written %d bytes \n",nwrite);
	*/	
	close(fd);
	//close(fd1);
	printf("Exit from App --->%s",__FILE__);
	return 0;
}

