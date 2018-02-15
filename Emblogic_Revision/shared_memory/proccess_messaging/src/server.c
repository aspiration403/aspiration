/*To process communicate using shared memory for the synchronisation I am using semaphore*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include "common.h"

int initialize_semaphore(int semid)
{
  union semun sem;
  sem.val = 1;
  semctl(semid, 0, SETVAL, sem);
  return ERROR_NO;
}

/*waiting*/
int sem_p(int semid)
{
 // int semop(int semid, struct sembuf *sops, unsigned nsops)  
  struct sembuf sbuf;
  sbuf.sem_num = 0;
  sbuf.sem_op = -1;
  sbuf.sem_flg = SEM_UNDO;
  semop(semid, &sbuf, 1);
  return ERROR_NO;
}

/*Signaling*/
int sem_v(int semid)
{
 // int semop(int semid, struct sembuf *sops, unsigned nsops)  
  struct sembuf sbuf;
  sbuf.sem_num = 0;
  sbuf.sem_op = +1;
  sbuf.sem_flg = SEM_UNDO;
  semop(semid, &sbuf, 1);
  return ERROR_NO;
}

/*Deleting the semaphore*/
int delete_semaphore(int semid)
{
  semctl(semid, 0, IPC_RMID);
  return ERROR_NO;
}

int main()
{
  key_t shared_mem_key = 1234;
  key_t sem_key = 1234;
  int shared_id;
  int semid;   
  int retVal = 0;
  struct shared_memory *shared_loc;
  void *shared_addrs;
  char input[BUFSIZE];
  /*Getting the semaphore id */
//  int semget(key_t key, int nsems, int semflg);
  semid = semget(sem_key, 1, 0666 | IPC_CREAT);

  if (ERROR_FAIL == semid)
  {
    perror("Semaphore Creation failed");
    exit(EXIT_FAILURE);
  }
  
  initialize_semaphore(semid);

  //int shmget(key_t key,size_t size, int shmflg)
  shared_id = shmget(shared_mem_key, sizeof(struct shared_memory), 0666|IPC_CREAT);
  if (ERROR_FAIL == shared_id)
  {
    perror("Semaphore Creation failed");
    exit(EXIT_FAILURE);
  } 

 // void *shmat(int shmid, const void *shmaddr, int shmflg);
  shared_addrs = shmat(shared_id, NULL, 0);
  shared_loc = (struct shared_memory *)shared_addrs;
  do
  {
     printf("Enter Data :[For exit : END]\n");
     fgets(input, BUFSIZE, stdin);
     input[strlen(input)] = '\0';
     sem_p(semid);
     memcpy(shared_loc->buffer, input, BUFSIZE);
     sem_v(semid);
  }while(strncmp(input,"END",3));
  
  delete_semaphore(semid);  
  shmdt(shared_addrs);
  return 0;
}

