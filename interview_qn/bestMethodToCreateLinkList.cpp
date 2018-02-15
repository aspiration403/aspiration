#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}list_t;

void addInList(list_t **headref)
{
	list_t *temp = (list_t*)malloc(sizeof(list_t));
  if (NULL == temp)
	{		perror("MALLOC ERROR");
      exit(1);
  }
  
  printf("Enter Data :\n");
  scanf("%d",&temp->data);
  
  temp->next = *headref;
  *headref = temp; 
}

void printList(list_t *temp)
{
	while(temp)
	{
		printf("Data :%d\n",temp->data);
    temp = temp->next;
	}
}
int main()
{
  int len = 0;
  int i = 0;
	list_t *head = NULL;
  printf("Enter Length of LinkList :\n");
  scanf("%d",&len);
  for (i = 0; i <len; i++)
  {
   	addInList(&head);
  }
  printList(head);
  return 0;
}
