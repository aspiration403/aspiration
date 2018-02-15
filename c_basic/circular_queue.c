//#include "header.h"
#include<stdlib.h>
#include<stdio.h>
static int rear=0;
static int front=0;
static int flag=0;
int enqueue(int arr[],int size)
{
	
	int i,val;
	if(rear ==0 && front == 0)
	{
		printf("Enter Value :\n");
		scanf("%d",&val);
		arr[rear] =val;
		rear++;
	}
	else if(rear < size && flag==0)
	{
		printf("Enter Value :\n");
		scanf("%d",&val);
		arr[rear] = val;
		rear++;
	}
	else if(rear==size && (rear - front )!=size)
	{
		
		printf("Enter Value :\n");
		scanf("%d",&val);
		rear =0;
		arr[rear] = val;
		
		flag =1;
	}
	else if(flag ==1 && rear < front)
	{
		
		printf("Enter Value :\n");
		scanf("%d",&val);
		arr[rear]=val;
		rear++;
	}
	else
		printf("queue is full\n");
////////////////////////////////////////////////////////////////////////////
	/*if(rear == front)
	{
		printf("Queue is empty\n");
		printf("Enter value :");	
		scanf("%d",&val);
		rear++;
		arr[rear]=val;
		
	}
	else if(rear < size-1 && rear > front)
	{		
		printf("Enter value :");	
		scanf("%d",&val);
		rear++;
		arr[rear]=val;
	}
	else if((rear == size -1)&& front !=-1)
	{
		 
		printf("Enter value :");	
		scanf("%d",&val);
		rear=0;
		arr[rear]=val;
	}
	else
		printf("Queue is full");
*/


}
int dequeue(int arr[],int size)
{
	int i,j;
	j=front;
	printf("queue is :rear=%d\t front =%d\n",rear,front);
	/*for(i=j;i<rear;j++)
	{
		printf("----QUEUE_---%d",arr[j]);
	}*/
	if(rear == front)
	{
		printf("Queue is empty \n");

	}
	if((front < rear) && front < size -1)
	{
		front++;
		printf("Data_1 is :%d\n",arr[front]);
	}
	else if((front == size -1 ) && rear !=0)
	{
		front =0;
		
		printf("Data_1 is :%d\n",arr[front]);
	}
	else
		printf("__Queue is empty__");
}
int main()
{
	int arr[5];
	int choice;
	while(1)
	{
		printf("for  enqueue press 1\nfor Dequeue press 2\n");
		scanf("%d",&choice);
		printf("you entered :%d\n",choice);
		if(choice == 1)
		{
			printf("__ENQUEUE__");
			enqueue(arr,5);
		}
		else if(choice == 2)
		{
			printf("__DEQUEUE__");
			dequeue(arr,5);
		}
/*		else if(choice == 3)
		{
			printf("__DEQUEUE__");
			printqueue(arr,5);
		}*/
		else
		{
			printf("enter right choice");
		}
	}	
}
