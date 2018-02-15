#include<glib.h>
#include<glib/gstdio.h>
GSList *list = NULL;
putdata(char *str)
{
	list = g_slist_append(list, g_strdup(str));
}
#if 0
deletedata(char *str)
{
	GSList *local = NULL;
	local = g_slist_find_custom(list, str,(GCompareFunc)compareData);	
	if (local)
		printf("%s",local->data);
	list = g_slist_delete_link(list, local);
	
}
#endif
void print(gpointer data, gpointer prefix)
{
	printf("\n %s %s ",data, prefix);
}

compareData(gpointer data, gconstpointer udata)
{
	return g_ascii_strcasecmp(data,udata);
}
int main()
{
	GSList *list1 = NULL;
	list = g_slist_prepend(list, g_strdup("Raman"));
	list = g_slist_prepend(list, g_strdup("aRman"));
	list = g_slist_prepend(list, g_strdup("Pankaj"));
//	list = g_slist_prepend(list, "Mohan");
//	g_slist_foreach(list, (GFunc)printf, NULL);
	list = g_slist_reverse(list);
	char *string = "NEHA";
	putdata(string);
	list = g_slist_prepend(list, g_strdup("Deepak"));
	g_slist_foreach(list, (GFunc)print, "-->");
	printf("\n---------After deleting-------\n");
	list1 = g_slist_find_custom(list ,"NEHA",(GCompareFunc)compareData);
	if (list1 != NULL)
		printf("\n finding %s :",list1->data);	
	g_free(list1->data);
	list = g_slist_delete_link(list, list1);
//	list = g_slist_append(list,"Sonika");
	g_slist_foreach(list, (GFunc)print, "-->");
	g_slist_foreach(list, (GFunc)g_free, NULL);
	g_slist_free(list);

	return 0;
}
