#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#define PORT 3000
void *server_handler(void *arg);
int main()
{
  int server_sd = 0, sd;
  int retVal = 0;
  pthread_t server_thread;
  pthread_attr_t attr;
  char clientAddr[INET_ADDRSTRLEN];
  struct sockaddr_in server, client;
  server_sd = socket(AF_INET, SOCK_STREAM, 0);
  
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  
  retVal = bind(server_sd, (struct sockaddr *)&server, sizeof(server));
  
  listen(server_sd, 5);
  while(1)
  {
    int len = sizeof(client);
    sd = accept(server_sd, (struct sockaddr *)&client, &len);
    printf("Received request from client :%s \n",inet_ntop(AF_INET, &client.sin_addr.s_addr, clientAddr,INET_ADDRSTRLEN));
    retVal = pthread_attr_init(&attr);
    if (-1 == retVal)
    {
      perror("Attribute set error");
    }
    retVal = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    if (-1 == retVal)
    {
      perror("Attribute set error");
    }
    int *serv_sd = (int *)malloc(sizeof(int));
    *serv_sd = sd;
    retVal = pthread_create(&server_thread, &attr, server_handler,(void *)serv_sd);
     if (-1 == retVal)
    {
      perror("Attribute set error");
    }
 
  }    
  return 0;
}


void *server_handler(void *arg)
{
  int sd = *(int *)arg;
  int datalen = 0;
  int nread = 0,remaining_byte = 0;
  char len[4];
  char buffer[255];
  
  read(sd, len, 4);
  datalen = atoi(len);
  printf("Recieving %d byte from client:%d\n",datalen);
  remaining_byte = datalen;
  while (remaining_byte > 0)
  {
      nread = read(sd, buffer+(datalen-remaining_byte) , sizeof(buffer));
      remaining_byte = remaining_byte - nread;
  }
  printf("Data Received :%s\n", buffer);
  
}
