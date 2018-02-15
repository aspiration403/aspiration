#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#define BUFSIZE 255
int gReady = 0;
void ouch()
{
	
	printf("\nMyBash>");
  signal(SIGINT,ouch);       
}

void executeOnShell(char buffer[BUFSIZE])
{
  char delim[] = " '\n'";
  char *token = NULL;
  char *data[BUFSIZE] = { NULL };
  int i = 0; 
  token = (char *)malloc(BUFSIZE);
  token = strtok(buffer,delim);
//  printf("token : %s\n",(token ? token : "null"));
  if (token)
  {
    data[i] = (char *)malloc(strlen(token)+1);
    memcpy(data[i],token,strlen(token));
//    printf("token) : %s\n", (data[i] ? data[i] : "null"));
    i++;
  } 
  
  while (token)
  {
    token = strtok(NULL, delim);
    if (token)
    {
    data[i] = (char *)malloc(strlen(token)+1);
    memcpy(data[i],token,strlen(token));
    i++;
    }
  }
  data[i] = 0;
  
  execvp(data[0], data);  
}



int main()
{
  pid_t pid;
  char buffer[BUFSIZE];

  signal(SIGINT,ouch);
while(1)
{

	pid = fork();
  switch(pid)
  {
    case -1:
				perror("ERROR: FORK");
        exit(EXIT_FAILURE);
     case 0:
          pause();
					executeOnShell(buffer);
				break;
      default:
      kill(getpid()+1,SIGINT); 
	printf("\nMyBash>");
  memset(buffer,0,sizeof(buffer));
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) -1] = '\0';
  if (!strncmp(buffer,"quit",4))
    exit(EXIT_SUCCESS);

			  break;		
  }
}
}


