#include<stdio.h>
#include<string.h>
#include<malloc.h>
enum d_type
{
 CHAR_P,
 CONST_CHAR_P,
 INT_P
}type;

union list
{
  char *p;
  const char *q;
  int *r;
}data;

void func( union list  input,enum d_type type)
{

	if (INT_P == type)
	printf("%d\n", *(input.r) );
	else if (CHAR_P == type)
	printf("%s\n", (input.p )) ;
        else
	printf("%s\n",input.q);
}

#if 0
int func( int* p )
{
printf("%d\n", p ) ;
return 0;
}
#endif

int main()
{

char *p = NULL;
const char *q = "hello" ;
int *r ;
r = malloc(4);
*r = 10;
p = (char *)malloc(sizeof(char)*20);

printf("Enter THE STRIng\n");
fgets(p,10,stdin) ;
//data.p = p;
//data.q = q;
data.r = malloc(1);
data.r = r;
//data.p = malloc(1);
//data.q = malloc(1);
//strcpy(data.p , p);
//func(data,CHAR_P) ;
//func(data,CONST_CHAR_P);
func(data,INT_P);
return 0 ;
}


