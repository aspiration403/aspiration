#include"header.h"
void handle_message()
{
	printf("receive signal ");
}
int main(int argc,char *argv[])
{
	signal(SIGUSR1,handle_message);
	struct data a;
	int wfd,rfd,nwrite,client2_result;
	if(argc<3)
	{
		perror(" CLI argument error ");
		goto out;
	}
	printf(" No. of argument received %d:\n",argc);
	rfd=atoi(argv[1]);
	wfd=atoi(argv[2]);

	printf("write desc. received value :%d \n",wfd);
	a.oprnd1=20;
	a.oprnd2=30;
	a.oprtr='-';
	nwrite=write(wfd,&a,sizeof(a));
	printf("No. of bytes written :%d",nwrite);
	pause(); 
	read(rfd,&client2_result,4);
	printf("Result of client 1 :%d \n",client2_result);
	return 0;
	out:
		return -1;
}

