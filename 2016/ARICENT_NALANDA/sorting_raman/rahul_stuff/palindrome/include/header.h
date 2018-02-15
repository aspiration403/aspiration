/* Header files  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Macros  */
#define MAX 30
#define SUCCESS 0
#define FAILURE -1

/* Global data  */
char stack_arr[MAX];
//extern int top;// = -1;

/* Function prototype  */
int Fopen(FILE**, char*, char*);
int Fclose(FILE*);
int read_file_and_check_palindrome(FILE*,FILE*);
int print_output_file(FILE*);
int insert_into_stack(char*, int);
int compare_from_stack(char*, int);
void push(char);
char pop();
