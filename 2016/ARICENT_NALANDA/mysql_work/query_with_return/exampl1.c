#include<stdio.h>
#include<stdlib.h>
#include<mysql.h>

MYSQL *my_conn;
void show_data(MYSQL_ROW myrow)
{
	int count = 0;
	int num_column = mysql_field_count(my_conn);
	while(count < num_column)
	{
		printf("\t %s ",myrow[count]);
		count++;
	}
	printf("\n");

}




int main()
{
	MYSQL_RES *result;
	MYSQL_ROW row;
	int ret = 0;
	unsigned long num_row = 0;
	char *query;
	my_conn = mysql_init(NULL);
	
	if (!my_conn)
	{
		fprintf(stderr, "mysql init error :%d \n %s \n",mysql_errno(my_conn), mysql_error(my_conn));
	}
	
	my_conn = mysql_real_connect(my_conn, "localhost", "raman", "abc123", "test", 0,0,0);
	if (!my_conn)
	{
		fprintf(stderr, "mysql connect error :%d \n %s \n",mysql_errno(my_conn), mysql_error(my_conn));
	}
	
//	query = "insert into student (name, age) values('minu',24)";
	query = "select * from student";
		
	ret = mysql_query(my_conn, query);
	if(ret)
		fprintf(stderr, "mysql query execution failed :%d \n %s \n",mysql_errno(my_conn), mysql_error(my_conn));
	
	result = mysql_store_result(my_conn);
	
	if (!result)
	{
		fprintf(stderr, "mysql getting result failed :%d \n %s \n",mysql_errno(my_conn), mysql_error(my_conn));
	}
	else
	{
		printf("\n query exexcuted successfully ");
		num_row = mysql_num_rows(result);
		printf("\n Fetched %lu rows \n",num_row);
		while(row = mysql_fetch_row(result))
			show_data(row);	


		mysql_free_result(result);
	}

	mysql_close(my_conn);

}













