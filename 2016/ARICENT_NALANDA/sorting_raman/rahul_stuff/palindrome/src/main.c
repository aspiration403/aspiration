
#include <header.h>

int main(int argc, char*argv[])
{
	FILE *in_fp;
	FILE *out_fp;
	int ret_val = SUCCESS;

	if (3 > argc)
	{
		printf(" Too few number of arguments found..!!!\n Format : <Exe>, <input_file_name>, <output_file_name>\n");
		exit(FAILURE);
	}
	if (3 < argc)
	{
		printf(" Number of arguments are more than what is required..!!!\n Proceeding with the required, ignoring the rest...!!!\n");
	}
	/*  0pening input file  */
	ret_val = Fopen(&in_fp, argv[1],"r");
	if (SUCCESS != ret_val)
	{
		printf(" Error in return value of function \"Fopen\"..!!!\n");
		exit(FAILURE);
	}
	/* Opening output file  */
	ret_val = Fopen(&out_fp, argv[2],"a");
	if (SUCCESS != ret_val)
	{
		printf(" Error in return value of function \"Fopen\"..!!!\n");
		exit(FAILURE);
	}

	ret_val = read_file_and_check_palindrome(in_fp,out_fp);
	if (SUCCESS != ret_val)
	{
		printf(" Error in return value of function \"read_file_and_check_palindrome\"\n");
		exit(FAILURE);
	}
	/* Printing the content of output file  */
	ret_val = print_output_file(out_fp);
	if (SUCCESS != ret_val)
	{
		printf(" Error in return value of function \"print_output_file\"\n");
		exit(FAILURE);
	}
	/* Close output file  */		
	ret_val = Fclose(out_fp);
	if (SUCCESS != ret_val)
	{
		printf(" Error in return value of function \"Fclose\"..!!!\n");
		exit(FAILURE);
	}
	/* Close input file  */
	ret_val = Fclose(in_fp);
	if (SUCCESS != ret_val)
	{
		printf(" Error in return value of function \"Fclose\"..!!!\n");
		exit(FAILURE);
	}
	
	
	printf("\n");
	return SUCCESS;
}
