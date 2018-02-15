/*Algo:in selection sort we select the smallest element in array and put it on appropriate place.then next smallest element in second array and so on.In this minimum number of swapping occur*/

/* time complexity n2
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 25

void selection_sort(int arr[], int max )
{
	int smallest = 0,i,j=0,temp=0;
	for (i = 0;i < max; i++)
	{
		smallest = i;
		for(j = i+1; j < max; j++)
		{
			if (arr[smallest] > arr[j])
				smallest = j;
		}
		if (smallest != i)
		{
			temp = arr[i] ;
			arr[i] = arr[smallest];
			arr[smallest] = temp;
		}
	}

}


int main()
{
	int arr[MAX],i,j,max;
	printf("\n enter the size of array:");
	scanf("%d",&max);
	for(i = 0; i < max; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	selection_sort(arr,max);
	printf("\n Data after sort:");
	for(i = 0; i < max; i++)
	{
		printf("\n%d",arr[i]);
	}
	
	return 0;
}


