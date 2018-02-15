#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  int data;
  struct node *next;
};

typedef struct node list_t; 

void insertNode(list_t **node, int data)
{
  list_t *start = *node;
  list_t *temp = NULL;
  if (( NULL == start) || (start->data >= data))
  {
    temp = (list_t *)malloc(sizeof(list_t));
    if (NULL == temp)
    {
      perror("Malloc Error");
      exit(EXIT_FAILURE);
    }
  
    temp->data = data;
    temp->next = start;
    *node = temp;
  }
  else 
  {
    while(start )
    {
       if ((start->data < data) && (start->next))  
       start = start->next;
       else
				break;
    }
    temp = (list_t *)malloc(sizeof(list_t));
    if (NULL == temp)
    {
      perror("Malloc Error");
      exit(EXIT_FAILURE);
    }
  
    temp->data = data;
    temp->next = start->next;
    start->next = temp;
  }
}

void printList(list_t *head)
{
  while(head)
  {
    printf("Data:%d \n",head->data);
    head = head->next;
  } 
}

list_t *reverseList(list_t **head)
{
  list_t *start = *head;
  list_t *prev = NULL;
  list_t *temp = NULL;
  
  while(start)
  {
    
    temp = start;
    start = start->next;
    temp->next = prev; 
    prev = temp;
  }
  *head = prev;
  return prev;   
}

int main()
{
  
  list_t *first = NULL;
  int num = 0;
  do
  {
    printf("Enter number :[0] to exit\n");
    scanf("%d",&num);
    insertNode(&first, num);
  }while(num);  

  printList(first);  
  first = reverseList(&first);
  printf("\n List After reverse:\n");
  
  printList(first);  
  return 0;
}
