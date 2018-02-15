#include<stdio.h>
#include<stdlib.h>
#include<glib.h>

void k_des(gpointer item)
{
	printf(" Key %s Destroyed.\n",(char*)item);
}

void v_des(gpointer item)
{
	printf("Value \"%s\" Destroyed.\n",(char*)item);
}

gboolean print_tree(gpointer item1,gpointer item2)
{
	printf(" %d \t %s \n",GPOINTER_TO_INT(item1),(char *)item2);
	return FALSE;
}

gint my_strcasecmp(gpointer data1, gpointer data2)
{
	int a = GPOINTER_TO_INT(data1);
	//int b = 
	int b = GPOINTER_TO_INT(data2);
//	return (gpointer)(GPOINTER_TO_INT(data1) - GPOINTER_TO_INT( data2));
	return(a - b);
}
int main()
{
	GTree* t = g_tree_new((GCompareFunc)my_strcasecmp);
	//GTree* t = g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp,NULL,(GDestroyNotify)k_des,(GDestroyNotify)v_des);
	//GTree* t = g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp,NULL,(GDestroyNotify)k_des,NULL);
//	GTree* t = g_tree_new_full((GCompareDataFunc)my_strcasecmp,NULL,(GDestroyNotify)k_des,NULL);
//	char *str1;
	char str[30];
//	gpointer str;
	gint i = 0;
	//gchar ch;
//	gpointer ch;
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
//		str1 = g_malloc(30);
		fscanf(stdin,"%s",str);
		
//		ch = GINT_TO_POINTER(i);
		g_tree_insert(t,GINT_TO_POINTER(i),str);
	//	str1 = NULL;
	}	

	printf(" Height of tree : %d. \n",g_tree_height(t));
	printf(" Number of nodes in tree : %d. \n",g_tree_nnodes(t));
//	g_tree_traverse(t,(GTraverseFunc)print_tree,G_IN_ORDER,NULL);
	g_tree_foreach(t,(GTraverseFunc)print_tree,NULL);
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
