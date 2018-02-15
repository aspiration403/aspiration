#include"header.h" 

int main()
{
	int n,count,count1;
	printf("in %s function \n",__FILE__);
	//printf("How many client you want to serve :");
	//scanf("%d",&count);
	count1=count;
	int pfd[2],cfd[2],retc,i,retp,ret,ret1,p1_res;
	int fd[2*count];
	struct data a;
	char cfdw[4],cfdr[4],pfdw[4],pfdr[4],c[7];
/*	for(i=1;i<=count;i++,count1--)
	{
		ret=pipe(fd);
		fd[(2*count1)-1]=fd[1];
		fd[(2*count1)-2]=fd[0];
	} 
	for(i=0;i<2*count;i++)
	{
		printf("--fd :%d\n",fd[i]);
	}*/
	retc=pipe(cfd);
	
	if(retc!=0)
	{
		perror("client pipe error :NOT CREATED");
		goto out;
	}
	sprintf(cfdw,"%d",cfd[1]);
	sprintf(cfdr,"%d",cfd[0]);	
	sprintf(c,"./client%d",1);
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
	}	
	return 0;
	out:
		return -1;
}

