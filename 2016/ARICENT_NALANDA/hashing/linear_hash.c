#include<stdio.h>
#include<stdlib.h>
#define MAX 11
void insert();
int search();
void display();
int delete();
int hash();


enum infoType
{
	EMPTY,
	OCCUPIED,
	DELETED
};
typedef struct employee
{
	int empId;
	char name[20];
	char location[20];
}employee_t;

struct employeeTable
{
	employee_t empInfo;
	enum  infoType status;
}table[MAX];



int hash(int key)
{
	return((key) % (MAX));
}

void insert()
{
	int location = 0;
	int key;
	int i = 0;
	employee_t emp;
	printf("\n Enter employee id, Name ,Native Place \n");
	scanf("%d%s%s",&emp.empId,&emp.name,&emp.location);
		
	key = emp.empId;
	location = hash(key);
	
	for (i = 1; i < MAX-1; i++)
	{
		if ((table[location].status == EMPTY) || (table[location].status == DELETED))
		{
			table[location].empInfo = emp;
			table[location].status = OCCUPIED;
			return ;
		}

		if (table[location].empInfo.empId == emp.empId)
		{
			printf("\n duplicate data ");
			return ;
		}
		
		location = hash(i + key);
	}
	printf("\n!!!!!!  ::Attention:: table overflow \n");

}


void display()
{
	int i = 0;
	for(i = 0; i < MAX; i++)
	{
		if (table[i].status == OCCUPIED)
		{
			printf("\n**** Employee Id: %d \n Name : %s \n Native Place:%s\n",table[i].empInfo.empId, table[i].empInfo.name,table[i].empInfo.location);
		}
	}
}

int search()
{
	
	int id = 0;
	int loc = 0;
	int i = 0;
	printf("\n Enter employee Id to search :");
	scanf("%d",&id);
	loc = hash(id);
	
	for (i = 1; i <= MAX -1; i++)
	{

		if ((table[loc].status == OCCUPIED) && ( id == table[loc].empInfo.empId))
		{
			printf("\n -----Employee Detail Found------------");
			printf("\n**** Employee Id: %d \n Name : %s \n Native Place:%s\n",table[loc].empInfo.empId, table[loc].empInfo.name,table[loc].empInfo.location);
			return 1;
		}
		
		loc = hash(i + id);
	}
	
	return -1;

}

int delete()
{
	int idToDelete = 0;
	int loc = 0;
	int i = 0;
	printf("\n Enter employee Id whose record you want to delete :");
	scanf("%d",&idToDelete);
	loc = hash(idToDelete);
	for (i = 0; i <= MAX-1; i++)
	{
		if ((OCCUPIED == table[loc].status) && (idToDelete == table[loc].empInfo.empId))
		{
			table[loc].status = EMPTY;
			table[loc].empInfo.empId = 0;
			printf("\nRecord deleted for %d employee \n",idToDelete);
			return 0;
		}
		loc = hash(i + idToDelete);	
	}
	
	return -1;
}


int main()
{
	int index = 0;
	int choice = 0;
	int found = 0;
/* intialize the table status empty*/	
	for (index = 0; index < MAX-1; index++)
	{
		table[index].status = EMPTY;
	}
	
	while(1)
	{
		printf("\n ********************** MENU ****************");
		printf("\n\t1. Insert ");
		printf("\n\t2. Search ");
		printf("\n\t 3.Display ");
		printf("\n\t 4.Delete ");
		printf("\n\t 5.exit  ");
		printf("\n Enter choice:");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				insert();
				break;
			
			case 2:
				found = search();
				if ( -1 == found)
					printf("\n employee Not found \n");
			
				break;
		
			case 3:
				display();
				break;
			
			case 4:
				
				found  =delete();
				if (-1 == found)
					printf("\n employee Not found \n");
				break;
			
			case 5:
				exit(0);
				
			default:
				printf("\n Please Enter Right choice ");
				break;

		}

	}



	return 0;
}


















