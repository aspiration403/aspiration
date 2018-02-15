#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUFSIZE	255

void search_replace(char *original)
{
	
	char search[] = "Rahul";
	char replace[] = "Raman";
	char *dummy = strdup(original);
	char *temp;
	char *final;
	char *local;
	int len = strlen(replace);
	int line_length = strlen(original);
	int written_length = 0;
	printf("\n original = %s", original);
	while(1)
	{
		temp = strstr(dummy, search);
		if((temp != NULL) && (written_length < line_length))
		{
			prev_len = strlen(temp);
			final_len = 
			final = realloc(final, strlen(dummy) + (line_length - (written_length + prex_len)));
			strncpy(final, dummy, line_length -(written_length +prev_len));
			strncat(final, replace, len);
			dummy = temp + strlen(search);
			written_length += strlen(dummy);
		}
		else
		{
			strcpy(final, dummy);
			break;
		}
	}

}




int main()
{
	int i =0;
	char *name[2];
	char buffer[BUFSIZE];
	printf("\n Enter name:");
	fgets(buffer, BUFSIZE-1, stdin);
	name[0] = strdup(buffer);
	printf("Name :%s",name[0]+2);
	search_replace(name[0]);
	printf("\n Enter name:");
	fgets(buffer, BUFSIZE-1, stdin);
	name[1] = strdup(buffer);
	printf("Name :%s",name[1]);

	for(i = 0; i < 2;i++)
	{
		free(name[i]);
	}


	return 0;
}

