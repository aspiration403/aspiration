#include <header.h>
static int top = -1;

void push(char ch)
{
	if ((MAX - 1) == top)
	{
		printf(" Stack overflow..!!!\n");	
		return;
	}
	top = top + 1;
	stack_arr[top] = ch;
}
/* ---------------------------------------------------------------------------------  */
char pop()
{
	char ch;
	if (-1 == top)
	{
		printf(" Stack underflow..!!!\n");
	}
	else
	{
		ch = stack_arr[top];
		top = top - 1;
	}
	return ch;
}
/* ---------------------------------------------------------------------------------  */
int Fopen(FILE **fp,char *f_name, char *mode)
{
	if (NULL == fp)
	{
		printf(" Data not received in file_pointer..!!!\n");
		exit(FAILURE);
	}
	*fp = fopen(f_name,mode);
	if (NULL == fp)
	{
		printf(" Error in opening %s file..!!!\n",f_name);
		perror(" File couldn't be opened..!!!");
		return FAILURE;
	}
	return SUCCESS;
}
/* ---------------------------------------------------------------------------------  */
int Fclose(FILE *fp)
{
	int ret_val = SUCCESS;
/*	if (NULL == fp)
	{
		printf(" Data not received in file_pointer..!!!\n");
		exit(FAILURE);
	}
*/
	ret_val = fclose(fp);
	if (SUCCESS != ret_val)
	{
		printf(" Error in closing file..!!!\n");
		perror(" File couldn't be closed..!!!");
		return FAILURE;
	}
	return SUCCESS;
}
/* ---------------------------------------------------------------------------------  */
int read_file_and_check_palindrome(FILE* in_fp,FILE* out_fp)
{
	char word[MAX];
	int ret_val = SUCCESS;
	int len_of_word = 0;
	int half_len_of_word = 0;
	int flag = 0;   // if word is palindrome 
	while (EOF != (fscanf(in_fp,"%s",word)))
	//while (fgets(word,MAX-1,in_fp))
	{
		//if (feof(in_fp))
		//	break;
		len_of_word = strlen(word);
		len_of_word--;
		half_len_of_word = len_of_word/2;
		if (0 == (len_of_word % 2))
		{
			ret_val = insert_into_stack(word,len_of_word);
			if (SUCCESS != ret_val)
			{
				printf(" Error in return value of function \"insert_into_stack\"\n");
				exit(FAILURE);
			}
			half_len_of_word--;
			flag = compare_from_stack(word,half_len_of_word);
			if (0 == flag)
			{
				//fopen(out_fp,argv[2],"a");
				fputs(word,out_fp);
				fputs("\n",out_fp);
				//fclose(out_fp);
			}
		}/* close of if (0 == (len_of_word % 2)) */
		else
		{
			ret_val = insert_into_stack(word,len_of_word);
			if (SUCCESS != ret_val)
			{
				printf(" Error in return value of function \"insert_into_stack\"\n");
				exit(FAILURE);
			}
			flag = compare_from_stack(word,half_len_of_word);
			if (0 == flag)
			{
				//fopen(out_fp,argv[2],"a");
				fputs(word,out_fp);
				fputs("\n",out_fp);
				//fclose(out_fp);
			}
		}/* Close of else */
	}/* close of while  */
	return SUCCESS;
}
/* ---------------------------------------------------------------------------------  */
int print_output_file(FILE *out_fp)
{
	char word[MAX];
	while (fscanf(out_fp,"%s",word))
		fputs(word,stdout);
	return SUCCESS;
}
/* ---------------------------------------------------------------------------------  */
int insert_into_stack(char word[],int len_of_word)
{
	int mid_len = len_of_word/2;
	while (len_of_word > mid_len)
	{
		push(word[len_of_word]);
		len_of_word--;
	}
	return SUCCESS;
}
/* ---------------------------------------------------------------------------------  */
int compare_from_stack(char word[],int half_len_of_word)
{
	int flag = 0;
	while (half_len_of_word >= 0)
	{
		if (word[half_len_of_word] == pop())
			half_len_of_word--;
		else
		{
			printf(" Word %s is not palindrome.. \n",word);
			flag = 1;
			break;
		}
	}
	return flag;
}
/* ---------------------------------------------------------------------------------  */

