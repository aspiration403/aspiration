/* Provide the interface to client to request for differnt operations*/
#include "client.h"
#include "header.h"
int main(int argc, char *argv[])
{
  printf("**********Client Server Communication*********\n");
  int operand_1,
      operand_2;
  char operator;
  int fd[2];
  pid_t pid;
	
  while(1)
  {
  pipe(fd);
	
  printf("Enter the data :format [operand operand operator]");
  
	scanf("%d %d %c",&operand_1,&operand_2,&operator); 
  
  pid = fork();
  switch(pid)
  {
		case -1:
          perror("FORK FAILED");
					exit(EXIT_FAILURE);
		case 0:
//          close(fd[0]);
  				send_data(fd,operand_1, operand_2,operator);
   				break;
		default:
          wait(NULL);
          read_data(fd); 
					break;
	}
 }        
  return 0;

}

int send_data(int fd[2], int num1, int num2, char operator)
{
  char read_fd[4];
  char write_fd[4];
  char buff[255];
  char first[4];
  char second[4];
  int nwrite = 0; 
  memset(buff,0,sizeof(buff));
  sprintf(write_fd,"%d",fd[1]);
  sprintf(read_fd,"%d",fd[0]);
  sprintf(first, "%d", num1);
  sprintf(second, "%d", num2);
  
  strcat(buff,first);
  strcat(buff,":");
  strcat(buff,second);
  strcat(buff,":");
  buff[strlen(buff)] = operator;
  printf("Data to send:%s\n",buff);
  nwrite = write(fd[1], buff, strlen(buff));
  printf("Written %d bytes data :%s\n",nwrite, buff);
	execl("../bin/server","server",read_fd,write_fd,0);
  return 0;
}

int read_data(int fd[2])
{
	char buffer[255];
  int nread = 0;
  memset(buffer,0,sizeof(buffer));
  nread = read(fd[0], buffer,sizeof(buffer));
  if (nread > 0)
  {
    printf("data from server :%s\n",buffer);
  }
  close(fd[0]);
  return 0;
}

