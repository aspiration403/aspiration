#include"header.h"
int main(int argc,char *argv[])
{
	int rfd,wfd,result,nwrite;
	struct data a;
	if(argc<3)
	{
		perror(" pipe error in process1");
		goto out;
	}
	rfd=atoi(argv[1]);
	wfd=atoi(argv[2]);
	read(rfd,&a,sizeof(a));
	printf(" in %s function",__FILE__);
	printf(" Data read :\n %d \n %d \n %c",a.oprnd1,a.oprnd2,a.oprtr);
	result=a.oprnd1 + a.oprnd2;
	nwrite=write(wfd,&result,4); 	
	printf("no. of bytes written :%d and data %d \n",nwrite,result); 
	return 0;
	out:
		return -1;
}
