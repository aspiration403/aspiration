/* Handle the request from different client, and call the particular handler*/
#include "server.h"
#include "header.h"

int main(int argc, char *argv[])
{
  int read_fd;
  int write_fd;
  char buffer[255];
  int nread = 0;
  char token[] = ":";
  int num1, num2;
  char operator;
  char *temp = NULL;
  int result;
  char result_buf[4];
   
  if (argc < 2)
  {
  	perror("Server Argc Error");
    exit(EXIT_FAILURE);
  }
  
  read_fd = atoi(argv[1]);
  write_fd = atoi(argv[2]);
  nread = read(read_fd, buffer, sizeof(buffer));
  printf("In server : Data read :%d bytes  \n",nread);
  if (nread > 0)
  {
    temp = strtok(buffer,token);
    sscanf(temp,"%d",&num1);
    printf("Num1 :%d\n",num1);
      
    {
       temp = strtok(NULL,token);
   //    printf("token: %s\n",(temp? temp:"null"));
       if (temp)
       {
            sscanf(temp,"%d",&num2);
            printf("Num2 :%d\n",num2);
       }
       temp = strtok(NULL,token);
         
          if (temp )
          {
            sscanf(temp,"%c",&operator);
            printf("operator :%c\n",operator);
          }
          
       }  
    }
  
  
  switch(operator)
  {
    case '+':
          result = num1 + num2;  
      break;  
    case '-':
          if (num1 > num2)
            result = num1 - num2;
          else
             result = num2 - num1; 
      break;
    case '*':
          result = (num1 * num2);
      break;
    case '/':
         if(num2 == 0)
         {
            perror("Denominator can't be zero");
            exit(EXIT_FAILURE); 
         }
         result = num1/num2;
      break;
    case  '%':
				if(num2 == 0)
         {
            perror("Denominator can't be zero");
            exit(EXIT_FAILURE); 
         }
         result = num1 % num2;
          
      break;
  }
  memset(result_buf,0,sizeof(result_buf));
  sprintf(result_buf,"%d",result); 
  write(write_fd,result_buf,sizeof(result_buf)); 
  close(write_fd);
  return 0;
}
