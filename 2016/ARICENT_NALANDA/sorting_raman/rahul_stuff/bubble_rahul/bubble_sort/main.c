/* in bubble sort we compare the fist element to next element and so on at last(after pass1) we get heavy element in last.on the next pass we compare for n-1 item and so on.in bubble sort maximum number of swapping occur.so it is not used when heavy data is present because of data movement.*/
/* if the data is nearly sorted then only we use it*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
#define BUFFER_SIZE 60

int swap(char *x, char *y)
{
	char temp[50];
	strcpy(temp,x);
	strcpy(x,y);
	strcpy(y,temp);
	return 0;
}


void bubble_sort(char *arr[],int max)
{
	int i,j;
	//int sorted_flag =0;
	for (i = 0 ;i < max; i++)
	{
		//sorted_flag =0;
		for(j = 0; (j < (max -i-1)); j++)
		{
			if ((strcmp(arr[j],arr[j+1]) > 0))
			{
				swap(arr[j],arr[j+1]);
			
			}
		}
	/*	if(0==sorted_flag )
		{
		printf("\n further data is sorted:pass:%d\n", i+1);
		break;
		}
*/	}
}


int main()
{
	int max,i;
	char *arr[MAX];
	int len = 0;
	char str[BUFFER_SIZE];
	printf("Enter the number of strings in array:");
	scanf("%d",&max);

	for(i=0; i < max; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * BUFFER_SIZE);
		//scanf("\n%s",arr[i]);	
		fgets(str,BUFFER_SIZE,stdin);
		
		len = strlen(str);
		printf(" Character :  %c\n",arr[i][len]);    // = '\0';
		while (getc(stdin) != '\n');
		printf(" Inputted data : %s\n",arr[i]);
	}
	
	printf("\n Data in array :");
	
	for(i=0; i < max; i++)
	{
		printf("\n%s ",arr[i]);	
	}
	bubble_sort(arr,max);
	printf("\n Data After sort :");
	
	for(i=0; i < max; i++)
	{
		printf("\n%s ",arr[i]);	
	}
	printf("\n");
	return 0;
}


 
