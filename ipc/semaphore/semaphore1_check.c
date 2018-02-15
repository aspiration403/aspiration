#include <sys/types.h>
#include <sys/ipc.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/sem.h>
#include<stdio.h>
//int semget(key_t key, int nsems, int semflg);
 union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
           };
/*int init_semaphore1(int semid)
{
	int ret=-1;
	union semun sem_val;
	sem_val.val=1;
	ret=semctl(semid,0,SETVAL,sem_val);	
	return ret;
}*/
/*int init_semaphore2(int semid)
{
	int ret=-1;
	union semun sem_val;
	sem_val.val=1;
	ret=semctl(semid,1,SETVAL,sem_val);	
	return ret;
}*/
int check_entry1(int semid)
{
	int ret=-1;
//	unsigned short sem_num;  /* semaphore number */
  //      short          sem_op;   /* semaphore operation */
    //    short          sem_flg;
	struct sembuf entry;
	entry.sem_num=0;
	entry.sem_op=-1;
	entry.sem_flg=SEM_UNDO;
	ret=semop(semid,&entry,1);
	return ret;
}
/*int check_entry2(int semid)
{
	int ret=-1;
//	unsigned short sem_num;  // semaphore number 
  //      short          sem_op;  //  semaphore operation 
    //    short          sem_flg;
	struct sembuf entry1;
	entry.sem_num=1;
	entry.sem_op=-1;
	entry.sem_flg=SEM_UNDO;
	ret=semop(semid,&entry1,1);
	return ret;
}*/
int check_exit1(int semid)
{
	int ret=-1;
	struct sembuf exit;
	exit.sem_num=0;
	exit.sem_op=1;
	exit.sem_flg=SEM_UNDO;
	ret=semop(semid,&exit,1);
	return ret;
}
/*int check_exit2(int semid)
{
	int ret=-1;
	struct sembuf exit1;
	exit.sem_num=1;
	exit.sem_op=1;
	exit.sem_flg=SEM_UNDO;
	ret=semop(semid,&exit1,1);
	return ret;
}*/
int delete_semaphore1(int semid)
{
	int ret=-1;
	
	ret=semctl(semid,0,IPC_RMID);
	return ret;	
}
/*int delete_semaphore2(int semid)
{
	int ret=-1;
	
	ret=semctl(semid,1,IPC_RMID);
	return ret;	
}*/
int main()
{
	char buf1[BUFSIZ],buf2[BUFSIZ];
	int nsems,ret=-1,i,ret_fifo,nread,fdr,fdw;
	if(-1==access("sender",F_OK))
	{
		ret_fifo=mkfifo("sender",666);
		if(ret_fifo<0)
			perror("fifo not created");
	}

	if(-1==access("receiver",F_OK))
	{
		ret_fifo=mkfifo("receiver",666);
		if(ret_fifo<0)
			perror("receiver fifo not created");
	}
	key_t user_key,semid;
	user_key=15;
	semid=semget(user_key,1,IPC_CREAT);
	if(semid<0)
		perror("semaphore not created !!\n");
	printf("semaphore successfuly created ID=%d",semid);
	
/*	ret=init_semaphore1(semid);
	if(-1==ret)
		perror("semaphore initialization !!");
*/
//	fdr=open("receiver",O_RDONLY|O_NONBLOCK);
	//fdw=open("sender",O_WRONLY|O_NONBLOCK);	
	/*ret=check_entry1( semid);
	if(0==ret)
		printf("Enter into critical section :\n");
	do
	{
		nread=read(fdr,&buf1,BUFSIZ);
		printf("%s \n"buf1);
	}while(nread);
	
*/	printf("write your message:\n for exit write no\n");
	do
	{
		fdr=open("receiver",O_RDONLY |O_NONBLOCK);
		nread=read(fdr,&buf1,BUFSIZ);
		if(nread)
		printf("%s \n",buf1);
		close(fdr);
		ret=check_entry1( semid);
		fdw=open("receiver",O_WRONLY |O_NONBLOCK);
		
		if(0==ret)
			printf("Data written by    :%d\n",getpid());
		printf("Enter message :\n");
		fgets(buf2,BUFSIZ,stdin);
		write(fdw,&buf2,BUFSIZ);
		
		ret=check_exit1(semid);	
		if(0==ret)
			printf("%d writer is on waiting \n",getpid());
		
	}while(strcmp(buf2,"no"));
	
/*	for(i=0;i<5;i++)
	{
		printf("executing critical section pid =%d\n",getpid());
		sleep(2);
	}
*/	
//	ret=check_exit(semid);	
	delete_semaphore1(semid);
	return 0;
}	

