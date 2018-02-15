#include"header.h"
int main(int argc,char *argv[])
{
	int fdr;
	char ch[6];
	fdr=atoi(argv[1]);
	printf("in %s file ",__FILE__);
	printf(" first argument is :%d",atoi(argv[1]));
	read(fdr,ch,6);
	printf("data read from pipe is :%s",ch); 
	close(fdr);
	return 0;	
}
