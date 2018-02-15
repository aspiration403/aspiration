#include<stdio.h>
#include<mysql.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
	MYSQL *conn_ptr;
	int ret = 0;
	conn_ptr = mysql_init(NULL);
	if(!conn_ptr)
	{
		fprintf(stderr, "Mysql init failed :error :%d :%s ",mysql_errno(conn_ptr), mysql_error(conn_ptr));
		exit(EXIT_FAILURE);
	}
		
	conn_ptr = mysql_real_connect(conn_ptr,"localhost", "raman", "abc123", "test",0,NULL,0);
	
	if (!conn_ptr)
	{
		fprintf(stderr, "Mysql connect failed :error :%d :%s ",mysql_errno(conn_ptr), mysql_error(conn_ptr));
		exit(EXIT_FAILURE);
		
	}
	else
		printf("\n connection successful");

	
	ret = mysql_query(conn_ptr, "insert into student(name,age) values('sonali', 22)");
	if (ret)
	{
		
		fprintf(stderr, "Mysql insertion failed :error :%d :%s ",mysql_errno(conn_ptr), mysql_error(conn_ptr));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("\n inserted :%lu rows :", (unsigned long)mysql_affected_rows(conn_ptr));
	}


	ret = mysql_query(conn_ptr,"update student set name='mohini' where age=22");
	if (ret)
	{
		
		fprintf(stderr, "Mysql insertion failed :error :%d :%s ",mysql_errno(conn_ptr), mysql_error(conn_ptr));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("\n inserted :%lu rows :", (unsigned long)mysql_affected_rows(conn_ptr));
	}

	

	char *query = "create table education(id int auto_increment primary key,qualification varchar(30))";
	
	ret = mysql_query(conn_ptr,query);
	if (ret)
	{
		
		fprintf(stderr, "Mysql insertion failed :error :%d :%s ",mysql_errno(conn_ptr), mysql_error(conn_ptr));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("\n inserted :%lu rows :", (unsigned long)mysql_affected_rows(conn_ptr));
	}

	




	mysql_close(conn_ptr);
		


	return EXIT_SUCCESS;
}
