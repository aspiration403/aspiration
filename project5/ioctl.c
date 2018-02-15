#include<sys/ioctl.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include"ioctl_header.h"

ioctl_func(int fd, int cmd)
{
	int arg,ret;
	switch(cmd)
	{
		case 1:
			ioctl(fd,SCULL_RESET,0);
			break;
		case 2:
			ioctl(fd,SCULL_QUANTUM_OUT,&arg);
			printf("quantum size =%d\n",arg);
			break;
		case 3:
			ioctl(fd,SCULL_QSET_SIZE,&arg);
			printf("Qset size =%d\n",arg);
			break;
		case 4:
			printf("Enter the size of Quantum :");
			scanf("%d",&arg);
			ret = ioctl(fd,SCULL_QUANTUM_SET,&arg);
			if(!ret)
			printf("Quantum size changed sucessfully \n");
			break;
		case 5:
			printf("Enter the size of Qset :");
			scanf("%d",&arg);
			ret = ioctl(fd,SCULL_QSETSIZE_SET,&arg);
			if(!ret)
			printf("Qset size changed sucessfully \n");
			break;
		default:
			printf("Enter Right Choice ");
		
		
	}
}


int main(int argc,char *argv[])
{
	int fd,choice;
	char req;
	printf("Inside %s \n",__FILE__);
	do{
	fd = open(argv[1],O_RDONLY);
	if(fd < 3)
	{
		perror("File not opened sucessfully");
		exit(EXIT_FAILURE);
	}
	printf("_____IOCTL MENU _____\n");
	printf("Press 1 for Reset Scull\n");
	printf("Press 2 for Read number of Quantum Size\n");
	printf("Press 3 for Read Qset Size\n");
	printf("Press 4 for Set Quantum Size\n");
	printf("Press 5 for Set Qset Size\n");
	printf("Press 0 for exit \n");
	scanf(" %d",&choice);
	ioctl_func(fd,choice);
	close(fd);
	printf("For continue operation Press y\n");
	scanf(" %c",&req);
	}while(req == 'y');
	return 0;
}
