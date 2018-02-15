#include<server.h>
#include<header.h>

MYSQL *create_mysql_conn(MYSQL *db_conn)
{
	db_conn = mysql_init(NULL);
	if (db_conn == NULL)
	{
		fprintf(stderr, "MYSQL init failed :%s",mysql_error(db_conn));
		exit(EXIT_FAILURE);	
	}

	db_conn = mysql_real_connect(db_conn, "localhost","raman","abc123","test",0,NULL,0);
	if (db_conn == NULL)
	{
		fprintf(stderr, "MYSQL connect failed :%s",mysql_error(db_conn));
		exit(EXIT_FAILURE);	
	}
	else
	{
		printf("\n Mysql connected successfully \n");
	}
	return db_conn;
}
