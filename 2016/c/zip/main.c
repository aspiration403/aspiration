#include "header.h"

int main()
{
	FILE *fpr,*fpw;
	char ch;
	fpr = fopen(argv[1], "r");
	if(fpr)
	{
		fpw = fopen("master_text", "a+");
		if (!fpw)
		{
			perror(" master_text not created ");
		}
	}
	while ((ch = fgetc(fpr)) != EOF)	
	{
		if( EOF != fputc(ch ,fpw);:q
	
	}
	
	return 0;
}

