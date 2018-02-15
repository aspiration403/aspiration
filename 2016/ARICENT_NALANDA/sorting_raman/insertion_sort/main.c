#include<stdio.h>
#define MAX 20

void insertion_sort(int arr[],int max)
{
	int current ;
	int i,j,n,k;
	
	for( i = 1; i < max;i++)
	{
		current = arr[i];
		for( j = i-1; j >= 0;j-- )
		{
			if( current <= arr[j])
			{
				arr[j+1] = arr[j];
			}
			else
				break;
		}
		arr[j+1] = current;
	}
	for(i =0; i < max; i++)
	{
		printf("%d \n",arr[i]);
	}
}


int main()
{
	int max,i;
	int arr[MAX];
	printf("\n Enter the maximum size :");
	scanf("%d",&max);

	printf("Enter elements:\n");
	for(i =0; i < max; i++)
	{
		scanf("%d",&arr[i]);
	}


	insertion_sort(arr,max);
	printf("\n data after insertion sort :\n");
	for(i =0; i < max; i++)
	{
		printf("%d \n",arr[i]);
	}

	
}	
