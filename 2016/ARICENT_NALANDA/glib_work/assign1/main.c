#include<glib.h>
#include<glib/gprintf.h>
#include<glib/gstdio.h>
#define BUFSIZE 255
gchar *finalArray;
void putInFinalArray(gchar **temp ,gint len)
{
	gint i = 0;
	gint length = 0;
	gchar *tempString = NULL;	
	do
	{
		printf("\n Token =%s",temp[i]);
		if (NULL != temp[i])
		{
			
			tempString = g_strjoin(tempString, temp[i],"-");
					
		}
		i++;
	}while(i < len);

	printf("\n Each Line :%s \n",tempString);
}


int main(int argc, char *argv[])
{
	FILE *fp_input;
	char buffer[BUFSIZE];
	gint numToken = 0;
	gint tokenLen = 0;
	gchar **temp = NULL;
	gchar delimeter[] = " ,:'\n'";
	finalArray = g_malloc(1);
	if (3 != argc)
	{
		printf("Insufficient argument:Format [exe file_name pattern] ");
	}
	
	fp_input = fopen(argv[1],"r");
	if (NULL == fp_input)
	{
		printf(" File not opened ");
	}
	
	while (1)
	{
		fgets(buffer, BUFSIZE, fp_input);
		if (feof(fp_input))
		{
			break;
		}
		temp = g_strsplit_set(buffer, delimeter, -1);
		tokenLen = g_strv_length(temp);
		putInFinalArray(temp,tokenLen);
		
	}

	printf("\n Hello ");
	return 0;
	
}
