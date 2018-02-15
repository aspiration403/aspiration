/*Basic work of Pipe,first in first out */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
  int fd[2];
  int ret = 0;
  char buff[256];
  int nwrite = 0;
  int nread = 0;
  ret = pipe(fd);
  if (!ret)
  {
    printf("Enter data to write in pipe :\n");
    fgets(buff,sizeof(buff),stdin);

    nwrite = write(fd[1], buff, strlen(buff));
///    close(fd[0]);
    printf(" written %d bytes \n",nwrite);
    if (nwrite > 0)
    {
       memset(buff,0,sizeof(buff));
       nread = read(fd[0],buff,sizeof(buff));
       
      printf(" Read %d bytes \n",nread);
      if (nread>0)
       printf("Data [%d] bytes read from pipe :%s  \n",nread,buff);
    }
    
  } 
}
