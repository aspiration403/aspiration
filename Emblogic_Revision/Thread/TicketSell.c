/*There are four seller who are selling online bus ticket.
 * if the total ticket is 15000, then find out which seller sold how may tickets 
 * using the same software machine.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_SELLER 4
#define TOTAL_TICKETS 15000

sem_t sem;
int gTotalTickets = TOTAL_TICKETS;
//int sem_init(sem_t *sem, int pshared, unsigned int value);
//int pthread_create(pthread_t *tid, pthread_attr_t *attr, void *(*handler)(void *), void *arg);
void * ticket_counter(void *arg)
{
  //int mySell = (int *)arg;
  while (1)
  {
      sem_wait(&sem);
      if (gTotalTickets == 0)
      {
        sem_post(&sem);
        break;
      }
      gTotalTickets = gTotalTickets - 1;
      *((int *)arg) += 1;
      sem_post(&sem);
  } 
   pthread_exit(NULL);
}

int main()
{
  pthread_t thread[MAX_SELLER];
  int *mySell[4] = {0};
  int ret = 0;
  int i = 0;
  printf("Total tickets :%d \n",gTotalTickets);
  ret = sem_init(&sem, 0, 1);
  if (ret)
  {
    perror("Sem init Failed");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < MAX_SELLER; i++)
  {
    mySell[i] = malloc(sizeof(int));
    *mySell[i] = 0;
    ret = pthread_create(&thread[i], NULL, ticket_counter, (void *)(mySell[i]));
  }
 
   for (i = 0; i < MAX_SELLER; i++)
  {
    ret = pthread_join(thread[i], NULL);
    printf("Seller[%d] sold %d tickets :\n",i,*mySell[i]);

  }
 
 
  return 0;
}


