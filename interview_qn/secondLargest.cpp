#include <stdio.h>
int main()
{
	int arr[] = {10, 20,40,3,50,70,55,65, 90,77, 87,10,12};
  //printf("size : %d\n",*(&arr + 1)-arr );
  int arrLen = *(&arr + 1)-arr;  
  int max = 0, jrMax = 0, temp = 0;
	if (arr[0] >arr[1] )
	{
		max = arr[0];
		jrMax = arr[1];
	}
	else
	{
		max = arr[1];
		jrMax = arr[0];
	}
  
  for ( int i = 2; i < arrLen; i++ )
  {	
      
    if ( arr[i] > jrMax )
		{
			if (arr[i] > max)
			{
				jrMax = max;
				max = arr[i];
			}
			else
				jrMax = arr[i];
		}
	}
	printf("\n Second Max :%d ",jrMax);
  return 0;
}
