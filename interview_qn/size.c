#include <stdio.h>
struct abc
{
    char c;
  };
char p;


void printData()
{
  static int a;
  a = 20;
}






int main()
{
  struct abc A;

  printData();
  
 printf(" Size of :%d :P=%c A:%d",sizeof(A),p,a);
  return 0;
}
