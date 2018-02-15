/* in bubble sort we compare the fist element to next element and so on at last(after pass1) we get heavy element in last.on the next pass we compare for n-1 item and so on.in bubble sort maximum number of swapping occur.so it is not used when heavy data is present because of data movement.*/
/* if the data is nearly sorted then only we use it*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void bubble_sort(int arr[],int max)
{
	int i,j,temp=0;
	int sorted_flag =0;
	for (i = 0 ;i < max; i++)
	{
		sorted_flag =0;
		for(j = 0; j < max -i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				sorted_flag =1;
			}
			
		}
		if(0==sorted_flag )
		{
		printf("\n further data is sorted:pass:%d\n", i+1);
		break;
		}
	}
}


int main()
{
	int max,i,j;
	int arr[MAX];
	printf("Enter the max length of array:");
	scanf("%d",&max);

	for(i=0; i < max; i++)
	{
		scanf("\n%d",&arr[i]);	
	}
	bubble_sort(arr,max);
	printf("\n data:");
	
	for(i=0; i < max; i++)
	{
		printf("\n%d ",arr[i]);	
	}

}


 
