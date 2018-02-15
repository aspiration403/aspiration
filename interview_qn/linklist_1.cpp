#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
using namespace std;
struct list
{
	int val;
	struct list *next;
}*head;

bool listCreated = false;
typedef  list list_t;

void insertAtEnd()
{
	list_t *start = head;
	list_t *temp = NULL;
	while(start->next)
	{
	  start = start->next;	
	}	
	temp = (list_t *)malloc(sizeof(list_t));
	printf("\n Enter Value :");
	scanf("%d", &temp->val);
	temp->next = NULL;		
  start->next = temp;
}

void insertAtPosition()
{
	int position = 0;
	int count = 0;
  bool invalidPosition = true;
  list_t *start = head;
	list_t *temp = NULL;
  list_t *next = NULL;
	printf("\nAt what position you want to insert : ");
	scanf("%d", &position);
	temp = (list_t *)malloc(sizeof(list_t));
	printf("\n Enter Value :");
	scanf("%d", &temp->val);
	temp->next = NULL;

  while (start)
  {
    count++;
		if (count == position)
		{
			temp->next = start->next;
			start->next = temp;
      invalidPosition = false;
      break;		
		}
    start = start->next;
	}
	if (invalidPosition == true)
	{
		printf("Given position is out of range (0 to %d)",count);
		free(temp);
	}
}

void insertAtHead()
{
	list_t *temp = NULL;
	temp = (list_t*)malloc(sizeof(list_t));
	printf("Enter Value :");
	scanf("%d", &temp->val);
	temp->next = head;
	head = temp;		
}

list_t *reverseList(list_t *start)
{
	list_t *node = start;
	list_t *next,*prev = NULL;
	list_t *temp = NULL;
	list_t *endNode = NULL;
	while (node)
	{
		temp = node->next;
    if (temp == NULL)
		{
			endNode = node;  
		}
		node->next = prev;
		prev = node;
		node = temp;
	}	
  return endNode;
}

void displayList(list_t *start)
{
  int count = 0;
	while(start)
	{
		printf("\nNode[%d]==> %d\n",count,start->val);
		start = start->next;
    count++;
	}
}

list_t *getMidNode()
{
	list_t *start = head;
	list_t *midFind = head;
	while (start)
	{
		start = start->next;
		if (start)
    {
			start = start->next;
		}
		if (start)
			midFind = midFind->next;
	}
  return midFind;
}
	
int checkForPalindrome()
{
	list_t *midNode = NULL;
  list_t *tail = NULL; 
  list_t *start = head;
	int retVal = 0;
	midNode = getMidNode();
//  printf("\n Displaying list from midNode"); 
//	displayList(midNode);
  tail = reverseList(midNode);
//  printf("\n Displaying list After midNode :twoMiddle = %d\n",twoMiddle); 
//	displayList(tail);
  midNode = tail; 
		while (start)
		{
			if (tail->val != start->val)
			{
				retVal = -1;
				break;
			}
			start = start->next;
			tail = tail->next;
		}
  reverseList(midNode); //Now make list in original form
	return retVal;
}
void deleteAtEnd()
{
}
void deleteAtHead()
{
}
void deleteAtPosition()
{

}
void deleteList()
{
	list_t *start = head;
  list_t *temp =NULL; 
	while(start)
	{
		temp = start;
    
		start = start->next;
    free(temp);
    temp = NULL; 
	}
  listCreated = false;
  head = NULL;	
}
int main()
{

	int choice ;
  do
	{
		fflush(stdin);
		int option = 0;
		printf("\n Enter Choice :\n");
		printf("1. Insertion at end :\n");
		printf("2. Insertion at head :\n");
		printf("3. Insertion at position:\n");
		printf("4. Show list :\n");
    printf("5. Deletion at end :\n");
		printf("6. Deletion at head :\n");
		printf("7. Deletion at position:\n");
		printf("8. Revese list :\n");
		printf("9. Check for palindrome :\n");
		printf("0. Delete list :\n");
		scanf("%d", &option);
    if ((listCreated == false) && (option > 3))
		{
			printf("List is not created, Firstly insert element");
			continue;
		}
		else if((listCreated == false) && (option < 3)) 
		{
			head = (list_t*)malloc(sizeof(list_t));
			printf("Enter Value :\n");
			scanf("%d", &head->val);
      head->next = NULL;
      listCreated = true;
			continue;	
		}
		switch(option)
		{
			case 1:
            insertAtEnd();
						break;
			case 2:
						insertAtHead();
						break;
			case 3:
						insertAtPosition();
						break;
			case 4:
						displayList(head);
						break;
			case 5:
  					deleteAtEnd();
						break;
			case 6:
						deleteAtHead();
						break;
			case 7:
						deleteAtPosition();
						break;
			case 8:
						head = reverseList(head);
						break;
			case 9:
						if(checkForPalindrome())
							printf("\n Not Plaindrome \n");
						else
							printf("\n Plaindrome\n");
						break;
			case 0:
						deleteList();
						break;
			default:
						printf("Unknown Choice \n");
						break;
		}
	printf("\n Do you want to continue :(Y/N) \n");
   choice = getchar();	
   fflush(stdout);
 }while(choice != 'n');
	
  return 0;
}

