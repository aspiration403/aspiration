/* Add two link list in sorted order*/
#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
	int data;
	struct list* next;
}list_t;

/* insert data in link list */
void insert(list_t **headref,int val)
{
  list_t *temp = *headref;
  if (*headref == NULL)
  {
    temp = (list_t*)malloc(sizeof(list_t));
    temp->data = val;
    temp->next = *headref;
    *headref = temp; 
  } 
  else
  {
    while(temp->next)
    {
      temp = temp->next;
    }
    temp->next = (list_t*)malloc(sizeof(list_t));
    (temp->next)->data = val;
    (temp->next)->next = NULL;
  }
}

printList(list_t *temp)
{
	while(temp)
	{
    printf("Num -> %d\n",temp->data);
    temp = temp->next;
  }
}

void insertInSortedOrder(list_t **final, int sum)
{
  list_t *temp = *final;
  list_t *local = (list_t*)malloc(sizeof(list_t));
  local->data = sum;  
  if ((temp == NULL) || (temp->data >= sum))
  {
    local->next = temp;
    *final = local;   
  }
  else
	{
		while(temp)
    {
       if((temp->data < sum) && (temp->next == NULL || temp->next->data > sum))
       {
          local->next = temp->next;
          temp->next = local;
       }
       temp = temp->next;
    }
  }
}
void AddList(list_t **first, list_t **second, list_t **final)
{
  list_t *l1 =  *first;
  list_t *l2 =  *second;
  int sum = 0;
  list_t *temp =  (list_t*)malloc(sizeof(list_t));
  while (l1 || l2)
  {
    if (l1 && l2)
    {
			sum = l1->data + l2->data;
      insertInSortedOrder(final, sum);
      l1 = l1->next; 
      l2 = l2->next; 
      continue;
    }
    else if (l1)
    {
      sum = l1->data;
      l1 = l1->next;
      insertInSortedOrder(final, sum);
      continue;
    }
    else if (l2)
    {
      sum = l2->data;
      l2 = l2->next;
      insertInSortedOrder(final, sum);
      continue;
    }
  }  
}

int main()
{
  int len = 0,num = 0;
  list_t *first = NULL;
  list_t *second = NULL; 
  list_t *final = NULL; 
  printf("How many element for first list :");
  scanf("%d",&len);
  while(len--)
  {
    printf("\n Enter number to insert :");
    scanf("%d", &num);
    insert(&first, num);
  }
  printList(first);
	printf("How many element for Second list :");
  scanf("%d",&len);
  while(len--)
  {
    printf("\n Enter number to insert :");
    scanf("%d", &num);
    insert(&second, num);
  }
  printList(second);
  AddList(&first, &second, &final);

	printf("\n Appended Final List : \n");
  printList(final);
return 0;
}

