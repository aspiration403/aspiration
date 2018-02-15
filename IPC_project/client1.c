#include"header.h"

int main()
{
	struct data_info
	{
        	int oprnd1,oprnd2;
        	char oprtr;
        	pid_t pid;
	};
	char name[20];
	int ret,fd,nwrite,res,nread;
	struct data_info data;
	
	data.oprnd1=10;
	data.oprnd2=10;
	data.oprtr='+';
	data.pid=getpid();	
	
	printf(" -----in Client1---\n");

	if(access("client_data",F_OK))
        {
                ret = mkfifo("client_data",0777);
                if(ret == 0)
                        printf("client_data fifo created successfully\n");
        }
        else
                printf("client_data fifo already exist in file system\n");	
//		sleep(1);	
	fd = open("client_data",O_WRONLY);
	if(fd > 0)
	{
		nwrite = write(fd,&data,sizeof(struct data_info));
		printf("No. of bytes written =%d\n",nwrite);
		printf("-----Data Written ------\n");
		printf("%d \t %d \t %c for client%d \n",data.oprnd1,data.oprnd2,data.oprtr,data.pid);
		close(fd);
	}
	else 
	{
		perror("client_data Fifo not opened\n");
		sleep(1);
	}	
	printf("Client Data Writting Completed\n");
//-------------------for Result------------
	sprintf(name,"client%d",getpid());	
	printf("Client Result Fifo Name =%s\n",name);	
	if(access(name,F_OK))
        {
                ret = mkfifo(name,0777);
                if(ret == 0)
                        printf("client_data Result fifo created successfully\n");
        }
        else
                printf("client_data fifo already exist in file system\n");	
//		sleep(1);	
	fd = open(name,O_RDONLY);
	if(fd > 0)
	{
		nread = read(fd,&res,4);
	//	printf("No. of bytes read =%d\n",nread);
		printf("Result in %s =%d\n",name,res);
		close(fd);
		unlink(name);
	}
	else 
	{
		perror("client_data Fifo not opened\n");
		sleep(1);
	}
		
	printf("---Exit from %s---\n",__FILE__);
	exit(EXIT_SUCCESS);
}
