#include <stdio.h>
#include <stdlib.h>

//To sort the data in ascending order, 0th element is compared with all other if 0th element found greater the we do swap,so after each iteration we get smallest element at position 0 */

int main()
{
  int arr[] = { 23,87,9,17,39,72};
  int i = 0, j = 0,swap = 0;
  int smallest = 0;
  int len = sizeof(arr)/sizeof(int);
  int temp = 0;
  for (i = 0; i< len; i++)
  {
    for (j = i+ 1; j < len; j++)
    {
       if (arr[i] > arr[j])
       {
          temp = arr[j];
          arr[j] = arr[i];
          arr[i] = temp;
       }
    }
      
  }  
 for (i = 0; i< len; i++)
  {
    printf("Array:%d\n",arr[i]);
  } 
 
  return 0;
}

