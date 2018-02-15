#include <stdio.h>
/*After each iteration the largest element goes to last*/
void bubbleSort(int *arr, int len)
{
  int i = 0,j;
  int temp = 0; 
  for (i = 0; i < len-1; i++)
  {
    for (j = 0; j < len-i-1; j++)
    {
      /*Do swap*/
      if (arr[j] > arr[j+1])
      {
         temp = arr[j];
         arr[j] = arr[j+1];
         arr[j+1] = temp; 
      } 
    }
   }
  
  printf("\nArray After Sorting :\n");
  for (i = 0; i < len; i++)
  {
    printf("%d\n",*(arr+i));
  }
    
  }  

/***0th element is compared with another element, after each iteration we get the minimum value on 0th*/

void selectionSort(int *arr, int len)
{
  int i = 0, j = 0,min,index;
  for (i = 0; i < len-1; i++)
  {
     min = arr[i];
     for (j = i+1; j < len; j++)
     {
       if(arr[j] < min)  
       {
          min = arr[j];
          index = j;
       }
     }

     if (min != arr[i])
     {
       arr[index] = arr[i];
       arr[i] = min;
     }
     
  }
}

int main()
{
	int arr[7] = {10,43,8,56,9,67,86};
	int i = 0;
  int len = 7;
  printf("Array before Sorting :\n");
  for (i = 0; i < 7; i++)
  {
    printf("%d\n",*(arr+i));
  }
 // bubbleSort(arr,7);
  selectionSort(arr,len);
   printf("\nArray After Sorting :\n");
  for (i = 0; i < len; i++)
  {
    printf("%d\n",*(arr+i));
  }
    
   
  return 0;
}
