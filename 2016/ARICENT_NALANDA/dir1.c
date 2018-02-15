#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
int main()
{
	DIR *current = NULL;
	struct dirent *direct;
	current = opendir(".");
	if (NULL == current)
		perror(" ::Current directory error:");

	
	while(NULL !=(direct = readdir(current)))
	{
		printf("\n File name :%s ",direct->d_name);
	}
	closedir(current);
	return 0;
}
