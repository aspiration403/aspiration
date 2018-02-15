#include<stdio.h>
#include<mysql.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
	MYSQL *conn_ptr;

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

	mysql_close(conn_ptr);
		


	return EXIT_SUCCESS;
}
