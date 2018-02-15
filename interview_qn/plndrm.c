#include<stdio.h>
int main()        //1234 4321
{
  int num;
  printf("Enter a number :");
  scanf("%d",&num);
  int org_num = num;
  int rev = 0,remain = 0;
  do
  {
    remain = num % 10;
    num = num/10;
    rev = 10 * rev + remain;
    
  }while(num);

  if (org_num == rev)
     printf("It is palindrome");
  
}
