#include<stdio.h>
#include<stdlib.h> 
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int n,count,count1;

	printf("in %s function \n",__FILE__);
	printf("How many client you want to serve :");
	scanf("%d",&count);
	count1=count;
	int cfd[2],c1fd[2],c2fd[2],retc,i,retp,ret,ret1,p1_res,j=1,k;
	int fd_bkup[2*count];
//	struct data a;
	char cfdw[4],cfdr[4],pfdw[4],pfdr[4],c[7];
	for(i=1,k=0;i<=count;i++)
	{
		ret=pipe(cfd);
		
		fd_bkup[k]=cfd[0];
		fd_bkup[k+1]=cfd[1];
		k=k+2;
		sprintf(cfdw,"%d",cfd[1]);
		sprintf(cfdr,"%d",cfd[0]);	
		sprintf(c,"./client%d",i);
		ret=fork();
		if(!ret)
		{
			execl(c,c,cfdr,cfdw,NULL);
		}
	} 
	for(i=0;i<2*count;i++)
	{
		printf("--fd :%d\n",fd_bkup[i]);
	}
	

/*	retc=pipe(cfd);
	
	
	if(retc!=0)
	{
		perror("client pipe error :NOT CREATED");
		goto out;
	}
	retp=pipe(pfd);
	if(retc!=0)
	{
		perror("Process pipe error :NOT CREATED");
		goto out;
	}	
	sprintf(pfdw,"%d",pfd[1]);	
	sprintf(pfdr,"%d",pfd[0]);
	ret=fork();
	if(!ret)
	{
		
		execl(c,c,cfdr,cfdw,NULL);
	}
	else
	{
		read(cfd[0],&a,sizeof(a));
		printf("data in pipe is :%d \n %d \n %c \n",a.oprnd1,a.oprnd2,a.oprtr);
	//	printf(" in parent process with pid %d\n",getpid());
		ret1=fork();
		if(!ret1)
		{
			
			execl("./process1","process1",pfdr,pfdw,NULL);
		}
		else
		{
			write(pfd[1],&a,sizeof(a));
			wait();
			read(pfd[0],&p1_res,4);
			printf("read data at server from process %d\n",p1_res);
			write(cfd[1],&p1_res,4);
		}
	}*/	
	return 0;
	out:
		return -1;
}

