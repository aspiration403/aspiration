#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFO "tuktuk"

int main()
{
  int ret = 0;
  int fd= 0;
 
  if (-1 == access(FIFO,F_OK))
  {
     ret = mkfifo(FIFO, 777);
     if (-1 == ret)
     {
       fprintf(stderr,"FIFO Creation error");
        exit(EXIT_FAILURE);
     }   
  }

  fd = open(FIFO, O_WRONLY);
  if (-1 == fd)   
     {
       fprintf(stderr,"FIFO open error");
        exit(EXIT_FAILURE);
     }   
   
  printf("Waiting for write Some data"); 
  return 0;
}
