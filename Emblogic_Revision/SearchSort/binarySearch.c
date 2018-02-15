#include <stdio.h>
int main()
{
  int arr[] = {10,20,30,40,50,60,70 };  //7
  int numToSearch = 50;
  int end = sizeof(arr)/sizeof(int);//*(&arr +1)-arr
  int beg = 0;
  int mid ;
  int flag = 0;
  for (mid = (beg + end)/2; mid <= end; mid = (beg +end)/2)
  {
     if (numToSearch < arr[mid])
     {
        end = mid -1;  
     }
     else if(numToSearch == arr[mid])
     {
        flag = 1;
        break;
     }
     else
     {
        beg = mid + 1;
     }
  }
  if (flag)
    printf("Number Find at position :%d\n",mid );
  else
    printf("Number Not present");
  return 0;
}
