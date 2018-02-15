#include"header.h"
int num;
int fdc[2*num],fdp[2*num];
create_pipe(char *str)
{
	int i,ret,fd[2],j;
	for(i=1,j=0;i<=num;i++)
	{
		ret=pipe(fd);
		if(!ret)
		{
			perror("pipe not created ");
			exit-1 ;
		}
		if(!strcmp(str,client))
		{
			fdc[j]=fd[0];
			fdc[j+1]=fd[1];
			
		}
		if(!strcmp(str,process)
		{
			fdp[j]=fd[0];
			fdp[j+1]=fd[1];
		}
		j=j+2;	
	}
	return 0;
	
}



int main()
{
	
	printf("How many client you want to serve :\n");
	scanf("%d",&num);
	char *str="client";
	printf("Creating pipe for client  \n")
//	str="client";
	create_pipe(str);
	printf("Creating pipe for process handler \n");
	str="process";
	create_pipe(str);	 
	return 0;
}
	
