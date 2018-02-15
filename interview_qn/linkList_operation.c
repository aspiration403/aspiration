#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
  int data;
  struct node *next;
}node_t;

node_t *head = NULL;

node_t *createNode()
{
  node_t *temp = NULL;
  temp = malloc(sizeof(node_t ));
  if (temp)
  temp->next = NULL;
  else  
  perror("CreateNode Malloc Error");
  return temp;
  
}
node_t *create_list()
{
  head = createNode();
  printf("Enter Value :\n");
  scanf("%d", &head->data);
  return head;
}
void insertNodeAtLast()
{
  int value = 0;
  node_t *temp = NULL;
  node_t *start = head;
  temp = createNode();
  printf("Enter Value :\n");
  scanf("%d", &temp->data);
  while(start->next)
  {
    start = start->next;
  }
  start->next = temp;
}

void printList()
{
  node_t *temp = head;
  int n = 1;
  while(temp)
  {
    printf(" Node :%d ->value = %d \n",n,temp->data);
    temp = temp->next;
    n++;
  }  
}

void reverseList()
{
  node_t *start = head;
  node_t *prev = NULL;
  node_t *next = NULL;
  
  while (start->next)
  {
    prev = start;
    next
  }
}

int main()
{
  int choice = 0;
  static bool list_present = false;
  while(1)
  { 
  printf(".....MENU......\n");
  
  printf("1.Insert Node At last....\n");
  printf("2.Delete Node....\n");
  printf("3.Print list....\n");
  printf("4.Reverse list....\n");
  printf("5.Exit....\n");
  scanf("%d",&choice);
  switch(choice)
  {
	  case 1:
		  if (!list_present )
		  {
			  head = create_list();
			  list_present = true;
		  }
                  else
		  insertNodeAtLast();
		  break;
	  case 2:
		  break;
	  case 3:
	          if (list_present == true)
		  printList();
                  else
                    printf("No node present"); 
		  break;
          case 4 :
	          if (list_present == true)
		  reverseList();
                  else
                    printf("No node present"); 
		  break;
          case 4 :
		  
	  case 5:
		  exit(0);
                  break;

  }
 }
 return 0;
}

