#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

/*  Function is used to remove \0 (new line)  */
char** remove_new_line(char *input_lines[SIZE], int number_of_string)
{
	int index;
	int r_index = 0;
	for (index = 0;index < number_of_string; index++)
	{
		//printf("\n String <%d> : %s",i,input_lines[index]);
		/*  i > 0 is for discarding 0(zero) length string */ 
        	if (!strcmp(input_lines[index],"\n"))
	        {

			strcpy(input_lines[r_index],input_lines[index + 1]);
			printf("\n char <%d> : %s",index + 1,input_lines[index]); 
			index++;
		}
		else
		{
			strcpy(input_lines[r_index],input_lines[index]);
			r_index++;
	
		}
	}
	for (index = 0;index < r_index; r_index++)
	{
		printf("\ndisp:%s \n",input_lines[index]);
	}
	
        return input_lines;
}
/* End of Function -  remove_new_line(char input_lines[])  */


/* Function to display inputted strings.  */

void display_input_lines(char *input_lines[SIZE],int number_of_string)
{
	int index;
	for (index = 0;index < number_of_string; index++)
	{
		printf("\n String <%d> : %s",index + 1,input_lines[index]);
	}
}
/*  End of Function - display_input_lines(char *input_lines)  */

/* Function used for allocating memory, inputting string, and to remove new line for inputted string  */
void input_string(int number_of_string)
{
	char *input_lines[number_of_string];
	int index;
	for(index = 0;index < number_of_string;index++)
	{
		input_lines[index] = (char*)malloc(sizeof(char) * SIZE);
		printf("\n Enter string <%d> : ",index + 1);
		fgets(input_lines[index],SIZE,stdin);
	}
	remove_new_line(input_lines,number_of_string);
	display_input_lines(input_lines,number_of_string);
	for(index = number_of_string - 1;index >= 0;index--)
	{
		free(input_lines[index]);
	}
	

	


}
/* End of Function - input_lines(int number_of_string)  */


int main(int argc, char *argv[])
{
	if (2 == argc)
	{
		int number_of_string;
		if ((number_of_string = atoi(argv[1])) > 0)
		{
			input_string(number_of_string);
			//display_input_lines(input_lines,number_of_string);
		}
		else
		{
			printf(" \n Invalid number for number of strings found..!!! Please Enter a positive value for it.");
		}

	
	}
	else
	{
		printf("\n Invalid number of arguments found..!!! \n <Format : FIle_Name, number of Strings.>\n");
	}
	printf("\n");
	return 0;
}//End of main
