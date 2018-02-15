#include<glib.h>
#include<glib/gstdio.h>

void keyDestroy(gpointer data)
{
	printf("\n Deleting key :%s", data);
}

void valDestroy(gpointer data)
{
	printf("\n Deleting value :%s", data);
}

void printing(gpointer data)
{
	printf("\n data :%s", data);
}


int main(int argc, char **argv)
{
	GHashTable *table = NULL;
	gpointer *str1 = NULL;
	gpointer *str2 = NULL;
	gpointer *str3 = NULL;
	gpointer *str4 = NULL;
	
	
	table = g_hash_table_new_full(g_str_hash, g_str_equal, (GDestroyNotify)keyDestroy, (GDestroyNotify)valDestroy);
	str1 = g_strdup("patna");
	str2 = g_strdup("patna");
	str3 = g_strdup("delhi");
	str4 = g_strdup("up");

	g_hash_table_insert(table, str1,"Raman");
	g_hash_table_insert(table,str3 ,"Paman");
	g_hash_table_insert(table, str4,"Naman");
	printf("\n printing before inseert ");
	//g_hash_table_foreach(table, (GFunc)printing, NULL);
	printf("\n printing After inseert ");

	g_hash_table_insert(table, str2,"Pankaj");
//	g_hash_table_foreach(table, (GFunc)printing, NULL);

	

	return 0;
}


