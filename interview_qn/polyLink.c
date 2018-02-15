#include <stdio.h>
#include <stdlib.h>
//7a(7) +  
typedef struct list
{
	int coeff;
	int pow;
	struct list *next;
}list_t;

list_t *head1 = NULL;
list_t *head2 = NULL;


void create_poly_first()
{
	list_t *temp = NULL;
		
	head1 = (list_t*)malloc(sizeof(list_t)); 
	head1->coeff = 7;
	head1->pow = 7;
	head1->next = NULL;
	
  temp = (list_t*)malloc(sizeof(list_t));
	temp->coeff = -4;
	temp->pow = 5;
  temp->next = NULL;
  head1->next = temp;
  
  temp = (list_t*)malloc(sizeof(list_t));
	temp->coeff = 4;
	temp->pow = 4;
  temp->next = NULL;
  (head1->next)->next = temp;
	
  temp = (list_t*)malloc(sizeof(list_t));
	temp->coeff = -4;
	temp->pow = 3;
  temp->next = NULL;
  ((head1->next)->next)->next = temp;
  
  temp = (list_t*)malloc(sizeof(list_t));
	temp->coeff = -4;
	temp->pow = 0;
  temp->next = NULL;
  (((head1->next)->next)->next)->next = temp;
    
  
}
void create_poly_second()
{
	list_t *temp = NULL;
		
	head2 = (list_t*)malloc(sizeof(list_t)); 
	head2->coeff = 7;
	head2->pow = 6;
	head2->next = NULL;
	
  temp = (list_t*)malloc(sizeof(list_t));
	temp->coeff = -4;
	temp->pow = 5;
  temp->next = NULL;
  head2->next = temp;
  
  temp = (list_t*)malloc(sizeof(list_t));
	temp->coeff = 4;
	temp->pow = 4;
  temp->next = NULL;
  (head2->next)->next = temp;
	
  temp = (list_t*)malloc(sizeof(list_t));
	temp->coeff = -4;
	temp->pow = 3;
  temp->next = NULL;
  ((head2->next)->next)->next = temp;
  
  temp = (list_t*)malloc(sizeof(list_t));
	temp->coeff = -4;
	temp->pow = 2;
  temp->next = NULL;
  (((head2->next)->next)->next)->next = temp;
    
  
}

void print_poly_list(list_t *head)
{
	list_t *start = head;
	int count = 0;
	while(start)
	{
			printf("\n List[%d] :coeff :%d pow:%d ",count, start->coeff,start->pow);
			start = start->next;
			count++;
	}
}

list_t *create_node()
{
	list_t *temp = NULL;
	temp = (list_t*)malloc(sizeof(list_t));
	temp->coeff = 0;
	temp->pow = 0;
	return temp;
}


list_t * add_polynomial()
{
	int temp_coeff = 0;
	int temp_pow = 0;
	int list_len = 0;
  list_t *headf = NULL;
	list_t *start1 = NULL;
	list_t *start2 = NULL;
	
	start1 = head1;
	start2 = head2;
	headf = (list_t*)malloc(sizeof(list_t));
	
  if (start1->pow > start2->pow)
	{
		headf->pow = start1->pow;
		headf->coeff = start1->coeff;
	}
	else if (start1->pow < start2->pow)
	{
		headf->pow = start2->pow;
		headf->coeff = start2->coeff;
	}
	else
	{
		headf->pow = start2->pow;
		headf->coeff = start1->coeff + start2->coeff;
	}
   
	start1 = start1->next;
	start2 = start2->next;
  list_t *start3 = headf;
int i = 0;
	list_t *temp = NULL;	
	for ( i = start3->pow-1 ; i >=0 ;i--)
	{
			temp =create_node();
			temp->pow = i;
			if (start1)
			{
		
				if (i == start1->pow)
				{
					temp->coeff +=start1->coeff;
        	start1 = start1->next;        
				}
			}
			if (start2)
			{
				if (i == start2->pow)
				{
					temp->coeff +=start2->coeff;
					start2 = start2->next;
				}
			}
			start3->next = temp;
			start3 = start3->next;
	}
	return headf;	
}

int main()
{
	list_t *add;
	create_poly_first();	
  printf("PolyNomial 1:\n");
  print_poly_list(head1);	
	create_poly_second();	
  printf("PolyNomial 2:\n");
  print_poly_list(head2);
//  printf("And PolyNomial 2:\n");
 // print_poly_list(head2);
 add = add_polynomial(head1, head2);	
 printf("Added PolyNomial :\n");
 print_poly_list(add);
  return 0;
}
