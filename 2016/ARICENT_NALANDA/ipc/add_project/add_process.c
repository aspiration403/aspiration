#include "header.h"

int main(int argc, char *argv[])
{
	int a = 5;
	int b = 3;
	int i = 0;
	//printf(" a + b = %d\n",a+b);
	
	for(i = 1; i < argc; i++)
	printf("\n argv[%d] = %s",i, argv[i]);

	int result = atoi(argv[1]) + atoi(argv[2]);
//	printf("result :%d",result);

	write(atoi(argv[3]), &result, 4);
	close(atoi(argv[3]));
	
	return 0;
}
