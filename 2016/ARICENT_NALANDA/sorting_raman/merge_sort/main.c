/* in this we follow divide and conure rule.this is not inline sort.the number of average and worst case nlogn*/

#include<stdio.h>
#define MAX 50

int temp[MAX];
void merge(int arr[], int low1,int up1, int low2, int up2);
void merge_sort(int arr[], int low, int up)
{
	int mid,i;
	for(i = 0;i <= up;i++)
	{
		printf(" %d\t",arr[i]);
	
	}
	printf("\n");
	if (low < up )
	{
		mid = (low + up)/2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, up);
		merge(arr,low,mid,mid + 1,up);
		copy(arr,low,up);

	}
}

void merge(int arr[],  int low1,int up1, int low2, int up2)
{
	int i = low1;
	int j = low2;
	int k = low1;
	while ((i <= up1) && (j <= up2))
	{
		if(arr[i] > arr[j])
		{
			temp[k++] = arr[j++];
		}
		else
		{
			temp[k++] = arr[i++];
		}
	}
	while (i <= up1)
		temp[k++] = arr[i++];
	while (j <= up2)
		temp[k++] = arr[j++];
}



int copy(int arr[],  int low, int up)
{
	int i;
	for ( i= low; i <= up ;i++)
	{
		arr[i] = temp[i];
	}

}



int main()
{
	int list[MAX];
	int max;
	int i;
	printf(" Enter value for max :\n");
	scanf("%d",&max);
	printf("Enter data \n");
	for(i = 0;i < max;i++)
	{
		scanf("%d",&list[i]);
	}

	merge_sort(list, 0, max-1);
	printf("After performing Merge sort operation \n");
	for(i = 0;i < max;i++)
	{
		printf(" %d\n",list[i]);
	
	}
}

