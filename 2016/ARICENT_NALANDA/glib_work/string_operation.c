#include<glib.h>
#include<glib/gprintf.h>
#include<glib/gstdio.h>
int main(int argc, char *argv[])
{
	gint32 a = -1;
	/*gchar delimeter[]= ",: ";
	gchar *temp = NULL;
	gchar *str = " hello rahul abc how are you fine";
	gchar **str1 = g_strsplit_set(str, delimeter, a);
//	gchar *str1 = g_strstrip(str);
	
	a = g_strv_length(str1);		
	printf("\n strstrip string :%d",a);
	gchar *str2 = g_strjoinv("-", str1);
	printf("\n string = %s",str2);
	temp = g_strrstr(str2,"rahul");
	printf("\n string = %s",temp);

//	printf("\n %d :",CLAMP(a, 70,80));
*/
	gchar *name ="Rahul   kumar	";
	gchar *name1 = NULL;
	gchar *name2 = NULL;	
	gchar *name3 = NULL;	
	char **name_array;
	name2 = g_malloc(255);
//	name1 = g_strreverse(g_strdup(name));
	name1 = g_strstrip(g_strdup(name));	
//	name2 = g_strdup_printf("%s is %d years old",name1,25);
	g_snprintf(name2,255,"%s is %d years old",name1,25);
	printf("\n%s:",name2);	
	name3 = g_strjoin("-",name2,name1,name1,NULL);
	printf("\n%s:",name3);
	name_array = g_strsplit_set(name3," ", -1);
	printf("\n Length :%d",g_strv_length(name_array));
	name3 = g_strjoinv("/",name_array);	
	printf("\n%s:",name3);
	name2 = g_strrstr(name3,"raman");
	printf("\n %s",name2);
	return 0;
}

