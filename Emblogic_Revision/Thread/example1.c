#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int gMyValue = 10;
//int pthread_create(pthread_t *thread_id, pthread_attr_t *attr, void *(*start_routine)(void *),void *arg);

void *handler()
{
  int i = 0;
  for(i = 0; i < 10; i++)
  {
    gMyValue += 10;
    sleep(1);
  }
  pthread_exit("Bye..Bye..!!");
}

int main()
{
  pthread_t tid;
  int ret = 0;
  void *ret_status;

  ret = pthread_create(&tid, NULL, handler,NULL);
  if (ret)
	{
     perror("Thread Create ERROR");
  } 

  pthread_join(tid,&ret_status);
  printf(" Thread has exited with status:%s :gMyValue :%d \n",(char *)ret_status,gMyValue);
	return 0;
}


