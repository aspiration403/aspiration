#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<sys/stat.h>

#define shared "/my_share"


int main()
{
	int s_fd ;
	s_fd = shm_open(shared, O_RDWR|O_CREAT,S_IRWXG|S_IRWXU);
	if (s_fd < 0)
	{	perror("!!Shared mem open error:");
	
	}

	ftruncate(s_fd,"");


	close(s_fd);
	return 0;
}



