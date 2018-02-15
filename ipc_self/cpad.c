#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
	int fd,nwrite,i;
//	printf("Give the file name:\n");
	char buf[]={"#include<stdio.h>\n#include<stdlib.h>\n#include<unistd.h>\n int main()\n{\n \t\nreturn 0;\n}"}; 
	if(argc<2)
	{
		perror("Provide the file name");
		printf("syntax :cim filename \n");
	}
	fd = open(argv[1],O_WRONLY |O_CREAT);
	printf("fd =%d\n",fd);
		nwrite = write(fd,buf ,sizeof(buf));
	/*	i++;
	}while(nwrite);**/
	return 0;
}	
