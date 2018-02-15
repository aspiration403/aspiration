#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>

sem_t sem_reader;
sem_t sem_resource;	


extern void *reader();
extern void *writer();



