#include<header.h>
#include<string.h>
static getLine(int num_line, char **line)
{
//	const char *getString[num_line];	
	static char string[BUFSIZE];
	int index = 0;      /* for indexing of loop */ 
	for (index = 0; index < num_line; index +=1 )
	{
		
		//if(index == 0)
			if (NULL == fgets(string,BUFSIZE,stdin))
			{
				printf("\n %d %s line input error :",__LINE__,__func__);
				exit(1);
			}
			else
			{
			
			line[index] = (char *)malloc(strlen(string)+1);
			
			if ( NULL == line[index])
			{
				printf("%s \t %d : Memory not allocated ",__func__,__LINE__);
				exit(1);
			}
			strcpy(line[index],string);
			printf("\n line = %p line[%d] :%p :%s\n",line,index,line[index],line[index]);
			}

//		line[index] = getString[index];
	}/*
		else
		{
//				line = p;
				line[index] = malloc(BUFSIZE);
				if ( NULL == line[index])
				{
					printf("%s \t %d : Memory not allocated ",__func__,__LINE__);
					exit(1);
				}

				if (NULL == fgets(line[index],BUFSIZE,stdin))
				{
					printf("\n %d %s line input error :",__LINE__,__func__);
					exit(1);
				}
				
		}
	}*/	
	/*for (index = 0; index < num_line; index++)
		printf("\n line[%d]:%s",index+1,line[index]);
*/
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
/*	for (index = 0; index < num_line; index++)
	{
		free(line[index]);
	}*/
//	free(line);
	
	return 0;
}




