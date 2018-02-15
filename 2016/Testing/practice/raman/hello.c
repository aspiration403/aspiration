#include<header.h>
#include<string.h>
#define BUFSIZE 255
void getLine(int num_line, char **line)
{
	static char input[BUFSIZE];
	int index = 0;      /* for indexing of loop */ 
	for (index = 0; index < num_line; index +=1 )
	{
		
		if (NULL == fgets(input,BUFSIZE,stdin))
		{
			printf("\n %d %s line input error :",__LINE__,__func__);
			exit(1);
		}
		else
		{
	
			line[index] = (char *)malloc(strlen(input)+1);
			strcpy(line[index],input);
		}
	}
}
int main(int argc, char *argv[])
{
	int num_line;
	int index = 0;
	static char **line;	
	if (argc < 2)
	{
		printf("Insufficient Argument :format:[output num_line]");
		exit(1);
	}
	line = (char **)malloc(sizeof(char *) * num_line);
	num_line = atoi(argv[1]);	 	
	getLine(num_line,line);
	for (index = 0; index < num_line; index++)
	{
		printf("\n line = %p line[%d] :%p :%s\n",line,index,line[index],line[index]);
		printf("\n line[%d]:%s",index+1,line[index]);
	}
	
	return 0;
}




