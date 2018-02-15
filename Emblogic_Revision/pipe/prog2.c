/*Dend the data from one process to another via fork and pipe*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 255
int main()
{
  int ret = 0;
  int fd[2];
  pid_t pid;
  int nread,
      nwrite;
  char buffer[BUFSIZE];
  pipe(fd);
  
  pid = fork();
  switch(pid)
  {
     case -1:
            perror("Fork Failed");
            exit(EXIT_FAILURE);
     case 0:
           printf("This is child ,Id : [%d], will write the data \n",getpid());
           nwrite = write(fd[1],"Raman",6);
           printf("\n Written %d bytes ",nwrite);
          break;
    default:  
           nread = read(fd[0], buffer,sizeof(buffer));
           printf("\n Read %d bytes ",nread);
           if (nread)
           printf("Data reading  parent[%d] : %s",getpid(),(buffer ? buffer : "null"));   
          break;
  }  
   
  return 0;
}
