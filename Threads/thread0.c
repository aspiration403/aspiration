#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
//int pthread_create(pthread_t *thread,pthread_attr_t *attr,void *(*start_routine)(void *),void *arg)
char name[20];
void thread_fun(void *arg)
{
	
}
int main()
{
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, &thread_fun,);
	return 0;
}


