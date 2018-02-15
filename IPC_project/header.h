#include<stdio.h>
#include<string.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<fcntl.h>
#include<sys/sem.h>
//int semget(key_t key, int nsems, int semflg);


struct data_info
        {
                int oprnd1,oprnd2;
                char oprtr;
                pid_t pid;
        };
//extern void remove_semaphore(int ,int);
//int semop(int semid, struct sembuf *sops, unsigned nsops);
//sembuf has following member
// unsigned short sem_num;  /* semaphore number */
// short          sem_op;   /* semaphore operation */
//                       short          sem_flg;  /* operation flags *
//int semctl(int semid, int semnum, int cmd, ...); initialize semaphore 
//int semget(key_t key, int nsems, int semflg);
  union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
           };
