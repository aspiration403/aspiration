#include <stdio.h>
#include <stdlib.h>
//After Each iteration we get the maximum value at end of array
int main()
{
  int arr[] = {87,13,9,95,23};
  int i = 0,j;
  int length = sizeof(arr)/sizeof(int);
  int swap = 0;
  for (i = 0; i < length; i++)
  {
    
    for (j = 0; j < length -i-1; j++)
    {
      if (arr[j] > arr[j+1])
      {
         swap = arr[j+1];
         arr[j+1] = arr[j];
         arr[j] = swap; 
      }
    }
  } 

   for (i = 0; i < length; i++)
  {
    printf("Arr[%d] = %d \n ",i,arr[i]);
  } 
  return 0;
}
