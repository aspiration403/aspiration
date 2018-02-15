#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include "common.h"
error_t init_sem(int semid)
{
  union semun sem;
  sem.val = 1;
  semctl(semid, 0, SETVAL, sem);
  return ERROR_NO;
}

error_t sem_p(int semid)
{
  struct sembuf sbuf;
  sbuf.sem_num = 1;
  sbuf.sem_op = -1;
  sbuf.sem_flg = SEM_UNDO;
  semop(semid, &sbuf, 0);
  return ERROR_NO;
}  

error_t sem_v(int semid)
{
  struct sembuf sbuf;
  sbuf.sem_num = 1;
  sbuf.sem_op = +1;
  sbuf.sem_flg = SEM_UNDO;
  semop(semid, &sbuf, 0);
  return ERROR_NO;
}  

error_t delete_sem(int semid)
{
  semctl(semid, 0 ,IPC_RMID);
}


int main()
{
  int sem_id;
  int shmid; //shared memory id
  void *sharedAddr;
  struct shared_memory *shared_mem;
 
  sem_id = semget((key_t)1234, 1, 0666 | IPC_CREAT);
  if (ERROR_FAIL == sem_id)
  {
    perror("Semget Failed");
  }
  
  shmid = shmget((key_t)1234, sizeof(struct shared_memory), 0666|IPC_CREAT);
  if (ERROR_FAIL == shmid)
  {
    perror("Shared memory Id failed");
    exit(EXIT_FAILURE);
  }
  
  sharedAddr = shmat(shmid, (void *)0, 0);
  shared_mem = (struct shared_memory *)sharedAddr;
  init_sem(sem_id);
  
  do
  {
    sem_p(sem_id);
    printf("Incoming Data :%s\n", shared_mem->buffer);     
    sem_v(sem_id);

  }while(strncmp(shared_mem->buffer, "END", 3));

  sem_p(sem_id);
  return 0;
}
