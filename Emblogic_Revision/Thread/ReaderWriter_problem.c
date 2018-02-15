/* only one writer can perform write operation on critical section, and no reader will be enter inside critical section when write is present, but n reader can read simultaneously*/


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//int sem_init(sem_t *sem, int pshared, unsigned int value);
//int pthread_getattr_np(pthread_t thread, pthread_attr_t *attr);

#define handle_error(en, msg) \
do { errno = en; perror(msg); exit(EXIT_FAILURE); } while(0)


int is_finish = 1;

void *handler()
{
  int i = 0;
  pthread_attr_t attr;
  for (i = 0; i < 30; i++)
  {
    is_finish = ((is_finish + i)*5)/3;  
  }
    
}


int main()
{
  pthread_t readerThread,
           writerThread;
  int ret = 0;
  pthread_attr_t attr;
  ret = pthread_attr_init(&attr);
  if (ret)
    handle_error(ret,"Attribute initialization");  

  ret = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
  if (ret)
    handle_error(ret,"Attribute initialization");  

  ret = pthread_create(&readerThread, &attr, handler, NULL);
  if (ret)
    handle_error(ret,"Attribute initialization");  
  
  pthread_attr_destroy(&attr);
  
   
  return 0;
}
