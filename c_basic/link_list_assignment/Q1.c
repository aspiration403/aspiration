//implement single link list with following function
//1. insert node at beginning of the list
//2.insert a node at end of list
//3.insert node at specific position
//4.delete a node from specified postion
//5.delete all lists

#include<stdio.h>
#include<stdlib.h>
struct linklist
{
	int val;
	struct linklist *next; 	
};
int flag = 0;
/*void create_ll(struct linklist *start)
{
	struct linklist *beg;
	beg = (struct linklist *)malloc(sizeof(linklist));
	if(!beg)
	{	perror("Malloc Failed :linklist not created");
		exit(EXIT_FAILURE);		
	}
	
	printf("Enter data :");
	scanf("%d",&val);		
	beg ->next = NULL;
}
*/
struct linklist* create_node ()
{
	struct linklist *temp = NULL;
	temp = (struct linklist *)malloc((sizeof(struct linklist)));
	if(!temp)
	{
		perror("Malloc Failed :node not created");
		exit(EXIT_FAILURE);		
	}
	else
	{
		printf("Enter data :");
		scanf("%d",&val);
		temp->val = val;
		temp ->next = NULL;
	}
	}
	return temp;
}

struct linklist* Node_at_begin(struct linklist *temp)
{
	printf("Inside %s \n",__func__);
	struct linklist *temp1 = NULL;
	temp1 = create_node();
	temp1->next = temp;
	return temp1;
	
}

Node_at_end(struct linklist *start)
{
	struct linklist *beg=NULL;
	beg = start;
	printf("Inside %s \n",__func__);
	while(beg->next)
	{
		beg = beg->next;
	}
	beg->next = create_node();
	return 0;
}
Node_at_pos(struct linklist *temp)
{
	struct linklist *temp1=NULL,temp2=NULL;
	temp1 = temp;
	int pos,count=1;
	printf("Inside %s \n",__func__);
	printf(" enter the position for inser data :\n");
	scanf("%d",&pos); 
	while(temp1 && count < pos)
	{
		temp2 = temp1;
		if(count == pos-1)
		{
			temp2 = temp1->next;
			temp3 = create_node();
			temp1->next = temp3;
			temp3->next = temp2;
				
		}
		temp1 = temp1->next;
		count++;
		
	}	
	return 0;
}

Del_node_pos()
{
	printf("Inside %s \n",__func__);
	return 0;
}

Del_list()
{
	printf("Inside %s \n",__func__);
	return 0;
}


int main()
{
	int choice;
	char request;
	struct linklist *start,*temp;
	do{
	printf("________FUNCTION MENU__________\n");
	printf("Press 1 for  create link_list	     :\n");
	printf("Press 2 for Insert Node at Beginning 	     :\n");
	printf("Press 3 for Insert Node at End               :\n");
	printf("Press 4 for Insert Node at specific position :\n");
	printf("Press 5 for Delete Node from specific pos    :\n");
	printf("Press 6 for Delete all link list	     :\n");
	printf("Press 7 for Display  link list	     :\n");
	printf("Enter Choice :");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:
			temp = start = (struct linklist *)malloc(sizeof(struct linklist));
			start ->next = NULL;
			printf("Enter Data :\n");
			scanf("%d",&temp->val);	
			
			break;
		case 2:
			temp = start = Node_at_begin(temp);
			break;
		case 3:
			Node_at_end(temp);
			break;
		case 4:
			Node_at_pos();
			break;
		case 5:
			Del_node_pos();
			break;
		case 6:
			Del_list();
			break;
		case 7:
			Display();
		default:
			printf("Enter Right Choice \n");
	
	} 
	printf("Press y/n for continue/exit\n");
	scanf(" %c",&request);
	}while(request == 'y' );
	

	return 0;	
}

