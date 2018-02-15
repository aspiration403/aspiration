#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
//#include<unistd.h>
int main()
{

	int fd1;

	fd1 = open("input_1.txt",O_CREAT);
	printf(" File Descriptor value : %d\n",fd1);

	close(fd1);
	printf("\n");
	return 0;
}
