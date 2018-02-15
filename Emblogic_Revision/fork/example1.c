#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int gMyValue = 10;   //If we update this calue in parent then it doesnot get reflected in child
int main()
{
  int ret = 0;
  pid_t pid;

  pid = fork();
  switch(pid)
  {
    case -1:
					perror("FORK CREATION FAILED");
          exit(EXIT_FAILURE);
    case 0:
          gMyValue = 50;
          printf("Child process :pid :%d\t gMyValue = %d\n",getpid(),gMyValue);
          break; 
    default:
			    wait(0);		      
          printf("parent :pid :%d\t gMyValue = %d\n",getpid(),gMyValue);
          gMyValue = 100;
          break; 
  }


  return 0;
}
