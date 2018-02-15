#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node_t;

node_t *head = NULL;

create_list(int len)
{
  int i = 0;
  node_t *temp;
  node_t *start = NULL;

  for (i = 0; i< len; i++)
  {
		if (head == NULL)
		{
			head = (node_t *)malloc(sizeof(struct node));
      printf("Enter Data :");
      scanf("%d",&head->data);
      head->next = NULL;
      start = head;
      continue;
    }
		
    temp = (node_t *)malloc(sizeof(struct node));
		printf("Enter Data :");
		scanf("%d",&temp->data);
		temp->next = NULL;
   
		start = head;
    while ((start->next))
    {
      start = start->next;
    } 
    start->next = temp;
  }
}

void  print_list()
{
  node_t *start = head;
  int i =1;
	while (start)
	{
    printf("\n Data[%d] :%d",i,start->data);  
		start = start->next;
    i++;
	} 
	
}

void detectDuplicate()
{
  node_t *start = head;
	node_t *temp = NULL;
	while(start->next)
	{
					temp = start->next;
					while(temp)
					{
									if (temp->data == start->data)
									{
													printf("Duplicate Entry :%d\n",temp->data);
									}	
									temp = temp->next;
									
					}
					start = start->next;
	}
}
int main()
{
  int length = 0;
  printf("Enter the length of linklist");
  scanf("%d",&length);

	create_list(length);
	print_list();
	detectDuplicate();
	return 0;
}
