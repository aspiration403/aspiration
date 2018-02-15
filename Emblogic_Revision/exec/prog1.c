#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
  printf("Now going to handover this process\n");
  execlp("ps","ps","ax",(char*)0);
  return 0;
}
