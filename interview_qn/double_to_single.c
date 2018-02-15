#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
	struct node 
	{
		int value;
		struct list* prev;
	};	
	struct node *data;
	struct list* next;
}list_t;

list_t *head = NULL;

struct list *addNode(int val)
{
	list_t *temp = NULL;
	list_t *start = head;
	temp = (list_t *)malloc(sizeof (list_t));	
	temp->data = (struct node *)malloc(sizeof(struct node));	
	
	while (start->next)
	{
		start = start->next;
	}
	
	temp->data->value = val;
	temp->data->prev = start;
	temp->next = NULL;
	start->next = temp; 
}

void printList()
{
	list_t *start = head;
	int count = 1;
	while(start)
	{
		printf("Forward Node :[%d]-->%d\n",count,start->data->value);
		count++;
		start = start->next;
	}
}

void ReversePrintAfterNthNode(int nthNode) //print node 5,4,3,2,1
{
	list_t *start = head;
	int count = 1;
	while(start && count< nthNode )
	{
	//	printf("Node :[%d]-->%d",count,start->data->value);
		count++;
		start = start->next;
	}
	while (start)
	{
		printf("Reverse Order Node :[%d]-->%d\n",count,start->data->value);
		count--;
		start = start->data->prev;	
	}

}


int main()
{
	list_t *start = NULL;

	head = start = (list_t *)malloc(sizeof (list_t));	
	start->data = (struct node *)malloc(sizeof(struct node));	
	
	start->data->value = 10;
	start->data->prev = NULL;

	start->next = NULL;

	addNode(20);
	addNode(30);
	addNode(40);
	addNode(50);
	addNode(60);
	addNode(70);
	addNode(80);

  printList();
	ReversePrintAfterNthNode(5); //print node 5,4,3,2,1

	return 0;
}
