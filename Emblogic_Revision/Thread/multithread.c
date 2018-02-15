#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define MAX_THREAD 10

//int pthread_create(pthread_t *thread_id, pthread_attr_t *attribute, void *(*start_routine)(void *), void *arg);

void *thread_hanlder()
{
  printf("My thread-id %x \n",pthread_self());
  pthread_exit(NULL);  
}

int main()
{
  pthread_t tid[MAX_THREAD];
  int ret = 0;
	int i = 0;
  
  for (i = 0; i < MAX_THREAD; i++)
  {
    ret = pthread_create(&tid[i], NULL, thread_hanlder, NULL);
    if (ret)
    {
       perror("Thread Creation Fail");
       exit(EXIT_FAILURE);
    }
  }

  for (i = 0; i < MAX_THREAD; i++)
  pthread_join(tid[i], NULL);

  return 0; 
}
