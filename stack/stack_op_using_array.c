#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define STACK_SIZE 5

/*	push() : Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
	pop()  :Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition
	peek() : Returns top element of stack
	isEmpty() :
  These all operation is O(1)
*/

int stack[STACK_SIZE];
int top  = -1;

bool isFull()
{
  if(top == STACK_SIZE-1)
	{
		return true;
	}
	return false;
}

bool isEmpty()
{
	if(top < 0)
	{
		return true;
	}
	return false;
}

void push()
{

	int data = 0;
	if(!isFull())
	{
		printf("Enter Data : \n");
		scanf("%d", &data);
		stack[++top] = data;
	}
	else
	{
		printf(".....OVERFLOW........!!\n");
	}
}

int pop()
{
  int data = 0;
	if(!isEmpty())
	{
	  data = stack[top];
		printf("Data :%d \n", stack[top--]);
	}
	else
	{
		printf("..UnderFLOW.....!!\n");
	}
	return data ;
}

void peek()
{
		printf("Top :%d \n", stack[top]);
}

int main()
{
	int choice = 0;

	do
	{
		printf("......MENU..........\n");
		printf("1. Push \n");
		printf("2. Pop \n");
		printf("3. Top \n");
		printf("0. Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
				push();
				break;
		case 2:
				pop();
				break;
		case 3:
				peek();
				break;
		case 0:
					exit(0);
					break;
		default:
			break;
		}
	}while(choice);

}

