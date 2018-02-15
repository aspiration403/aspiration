#include<stdio.h>
#include<stdlib.h>
#include<glib.h>

void k_des(gpointer item)
{
	printf(" Key \"%s\" Destroyed.\n",item);
}

void v_des(gpointer item)
{
	printf("Value \"%s\" Destroyed.\n",item);
}

gboolean print_tree(gpointer item1,gpointer item2)
{
	printf(" %s \t %s \n",item1,item2);
	return FALSE;
}

gpointer my_strcasecmp(gpointer data1, gpointer data2)
{
	return (gpointer)(data1 - data2);
}
int main()
{
	//GTree* t = g_tree_new((GCompareFunc)g_ascii_strcasecmp);
	//GTree* t = g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp,NULL,(GDestroyNotify)k_des,(GDestroyNotify)v_des);
	//GTree* t = g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp,NULL,(GDestroyNotify)k_des,NULL);
	GTree* t = g_tree_new_full((GCompareDataFunc)my_strcasecmp,NULL,(GDestroyNotify)k_des,NULL);
	//char *str;
	//char str[30];
	gpointer str;
	gint i = 0;
	//gchar ch;
	gpointer ch;
/*	g_tree_insert(t,"10","Sumit");
	g_tree_insert(t,"11","Sreya");
	g_tree_insert(t,"12","Srivastava");
	g_tree_insert(t,"18","Srayas");
	g_tree_insert(t,"20","Sanjana");
	g_tree_insert(t,"14","Somi");
	g_tree_insert(t,"19","Sonika");
	g_tree_insert(t,"13","Sarathi");
	g_tree_insert(t,"18","Somita");
	g_tree_insert(t,"6","Sapna");
	g_tree_insert(t,"8","Sachi");
*/
	printf(" Enter 6 Value to be inserted : ");
	for (i=0;i<6;i++)
	{	
		scanf("%p",str);
		ch = GINT_TO_POINTER(i);
		g_tree_insert(t,GINT_TO_POINTER(ch),str);
	}	

	printf(" Height of tree : %d. \n",g_tree_height(t));
	printf(" Number of nodes in tree : %d. \n",g_tree_nnodes(t));
	g_tree_traverse(t,(GTraverseFunc)print_tree,G_IN_ORDER,NULL);
	printf(" ---------------------------------------------- \n");
	//g_tree_remove(t,"i");	
	//printf(" After remove......\n");
	//printf(" Height of tree after remove : %d. \n",g_tree_height(t));
	//printf(" Number of nodes in tree after remove : %d. \n",g_tree_nnodes(t));
	//g_tree_traverse(t,(GTraverseFunc)print_tree,G_IN_ORDER,NULL);
	//printf(" ---------------------------------------------- \n");
/*	g_tree_traverse(t,(GTraverseFunc)print_tree,G_PRE_ORDER,NULL);
	printf(" ---------------------------------------------- \n");
	g_tree_traverse(t,(GTraverseFunc)print_tree,G_POST_ORDER,NULL);
	printf(" ---------------------------------------------- \n");

	g_tree_steal(t,"18");
	printf(" Height of tree after steal : %d. \n",g_tree_height(t));
	printf(" Number of nodes in tree after steal : %d. \n",g_tree_nnodes(t));
	g_tree_traverse(t,(GTraverseFunc)print_tree,G_IN_ORDER,NULL);
	printf(" After steal.. \n");
	g_tree_traverse(t,(GTraverseFunc)print_tree,G_IN_ORDER,NULL);
	printf(" ---------------------------------------------- \n");
*/	
	g_tree_destroy(t);	
	printf("\n");
	return 0;
}
