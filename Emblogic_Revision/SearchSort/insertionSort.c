#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[] = {56,17,23,12,38,5};
  int len = sizeof(arr)/sizeof(int);
  printf("len =%d",len);
  int i, j= 0 ;
 int value = 0; 
  for (i = 1; i < len; i++)
  {
    value = arr[i];
     j = i-1;
     while (j >= 0 && (value > arr[j]))
    {
        arr[j+1] = arr[j];
        j = j-1;
    }
    arr[j+1] = value;
  }

  for (i = 0; i < len; i++)
  printf("Data[%d] : %d \n",i,arr[i]); 
  return 0; 
}
