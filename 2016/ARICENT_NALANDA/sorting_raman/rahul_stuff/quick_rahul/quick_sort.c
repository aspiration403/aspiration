#include<stdio.h>
#define MAX 100

int partition(int arr[], int low, int up)
{
	int i = low +1;
	int j = up;
	int temp;
	while (i <= j)
	{
		while ((arr[low] > arr[i]) && (i < up))
			i++;
		while (arr[low] < arr[j])
			j--;
		if (i <= j)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
			j--;
		}
		else
			i++;
	}
	temp =  arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	return j;
}



void quick_sort(int arr[], int low, int up)
{
	int pivot = arr[low];
	int pivot_loc = 0;
	if (low <= up )
	{
		pivot_loc = partition(arr,low,up);
		quick_sort(arr, low, pivot_loc-1);
		quick_sort(arr, pivot_loc+1, up);
	}
}

int main()
{
	int max,i;
	int arr[MAX];
	printf(" How many elements do you want to enter : \n");
	scanf("%d",&max);
	printf(" Enter Elements \n");
	for (i = 0;i < max; i++)
		scanf("%d",&arr[i]);
	quick_sort(arr, 0, max);
	printf(" After performing quick sort :\n");
	for (i = 0;i < max;i++)
		printf("%d \n",arr[i]);
}
