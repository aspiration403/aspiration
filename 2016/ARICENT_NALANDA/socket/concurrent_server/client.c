#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define SERVER "127.0.0.1"
#define PORT 3000

int main()
{
  int sd = 0;
  struct sockaddr_in server;
  sd = socket(AF_INET, SOCK_STREAM, 0);
  
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr = inet_addr(SERVER);
  
  bind(sd, (struct sockaddr *)&server, sizeof(server));
  
  connect(sd, (struct sockaddr *)&server, sizeof(server));
  int datalen = 25;
  char length[4];
  sprintf(length,"%d",datalen);  
  write(sd,length, 4); 
  write(sd, "Hi I am Raman..client",25);

  close(sd); 
}
