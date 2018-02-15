#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
 int data;
 struct node *next;
}list_t;

void insert(list_t** headref, int val)
{
		list_t *temp = *headref;
    list_t *local = (list_t *)malloc(sizeof(list_t));
    local->data = val;

  if (temp == NULL || temp->data >= val)
  {
    local->next = temp;
    *headref = local;   
  }
  else
  {
    while(temp)
    {
      if ((temp->data < val ) && (  temp->next == NULL || temp->next->data > val))
      {
         local->next = temp->next;
         temp->next = local;
      }
      temp = temp->next;
    }
 }
}


void reverseList(list_t **headref)
{
  list_t *start = *headref;
  list_t *temp = *headref;
  list_t *prev = NULL;
  
  while (start)
  {
    temp = start;
    start = start->next;
    temp->next = prev;
    prev = temp;
  }
  *headref = prev;
}

void printList(list_t *temp)
{
	while(temp)
  {
    printf("Data :%d\n",temp->data);
    temp =temp->next;
  }
}

int main()
{
  list_t *first = NULL;
  int val,count = 0;
  printf(" How many num do you want to insert :\n");
 	scanf("%d", &count);
  while (count--)
  {
   printf("Enter number :");
   scanf("%d",&val);
   insert(&first,val);
  }
  printList(first);
  reverseList(&first); 
  
	printf("After reversing the list :\n");
  printList(first);
  return 0;
}
