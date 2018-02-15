#include <stdio.h>
int add(int a, int b)
{
  if (b == 0)
			return a;
	else
		add(a^b, (a&b)<<1);
  
}

int main()
{
  int a, b;
  int result;
  while(1)
  {
    printf("Enter Two num:\n");
    
    scanf("%d %d",&a,&b);
  	result = add(a,b);
	  printf("Result :%d \n",result);
	}
}
