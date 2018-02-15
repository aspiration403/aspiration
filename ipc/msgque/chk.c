#include <stdio.h>
#include<string.h>
int main()
{
	char buf[BUFSIZ];
	char abc[]="exit";
	char abd[6];
	//do{
		fgets(buf,BUFSIZ,stdin);
		strcpy(abd,abc);
		printf("%s\n",buf);
	  // }while(strcmp(buf,"exit"));
	printf("val =%d \n",strcmp(abd,"exit"));
	return 0;
}
