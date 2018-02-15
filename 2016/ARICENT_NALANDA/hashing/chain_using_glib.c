#include<stdio.h>
#include<stdlib.h>
#include<glib.h>
//#define MAX 11
GHashTable *hash;

void insert();
//int search();
void display();
//int delete();
//int hash();


void print_hash(gpointer key, gpointer value);

void iterator(gpointer table);

#if 0
enum infoType
{
	EMPTY,
	OCCUPIED,
	DELETED
};
#endif
typedef struct employee
{
	int empId;
	char name[20];
	char location[20];
}employee_t;
#if 0
struct employeeTable
{
	employee_t empInfo;
	enum  infoType status;
}table[MAX];

#endif
void destroy_key_r(gpointer key)
{
//	printf("\n Got a destroy key for :%d",GPOINTER_TO_INT(key));
}
void destroy_value_r(gpointer key)
{
//	printf("\n Got a destroy key for :%d",GPOINTER_TO_INT(key));
}


void insert()
{
	int location = 0;
	int key;
	int i = 0;
	employee_t emp;
	printf("\n Enter employee id, Name ,Native Place \n");
	scanf("%d%s%s",&emp.empId,&emp.name,&emp.location);
		
//	key = emp.empId;
	
	g_hash_table_insert(hash, g_strdup(emp.name), 
				g_slist_append(g_hash_table_lookup(hash, emp.name),(gpointer)&emp));

}


void display()
{
	g_hash_table_foreach(hash, (GHFunc)print_hash,NULL);
}
void print_hash(gpointer key, gpointer value)
{
//	printf("\n Here empId(key) :%d", GPOINTER_TO_INT(key));
	g_slist_foreach(value,(GFunc)iterator, NULL);
}
void iterator(gpointer table)
{

	printf("\n**** Employee Id: %d \n Name : %s \n Native Place:%s\n",((employee_t *)table)->empId, ((employee_t *)table)->name,((employee_t *)table)->location);
}

#if 0
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
#endif

int main()
{
	int index = 0;
	int choice = 0;
	int found = 0;
	hash = g_hash_table_new_full(g_str_hash, g_str_equal,(GDestroyNotify)destroy_key_r,(GDestroyNotify)destroy_value_r);
	
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
			//	found = search();
			//	if ( -1 == found)
			//		printf("\n employee Not found \n");
			
				break;
		
			case 3:
				
				display();
				break;
			
			case 4:
			//	
			//	found  =delete();
			//	if (-1 == found)
			//		printf("\n employee Not found \n");
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


















