#include<stdio.h>
#include<stdlib.h>
#define BUFSIZE 255
#define TABLE_SIZE 11
enum table_status
{
	EMPTY,
	OCCUPIED,
	DELETED
};

typedef struct student
{
	char name[BUFSIZE];
	char college[BUFSIZE];
	int roll_no;
}student_t;


struct hash_table
{
	enum table_status status;
	student_t student_info;
	struct hash_table *next;
}table[TABLE_SIZE];


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

                                                                                                       190,0-1       88%

}

