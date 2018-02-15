#include <stdio.h>
int main()
{ 
  int arr[] = {10,12,43,13,54};
  printf("Length :%d \n", *(&arr +1)-arr);
  return 0;
}
