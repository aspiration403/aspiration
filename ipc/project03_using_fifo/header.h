#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<assert.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/sem.h>
int semget(key_t key,int nsems,int semflag);
int semop(int semid,struct sembuf *semops,unsigned nsops);
