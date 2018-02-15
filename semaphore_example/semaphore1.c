#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
           };


char buf[30];
init_sem(int semid)
{
	int ret = -1;
	union semun sem_val;
	sem_val.val = 1;
	ret = semctl(semid, 0, SETVAL, sem_val);
	if(ret == -1)
	{	
		perror("Semaphore Initialization Error ");
	//	exit(0);
	 }
	return(ret);
}

get_entry(int semid)
{
	int ret = -1;
	struct sembuf entry;
	entry.sem_num = 0;
	entry.sem_op = -1;
	entry.sem_flg = SEM_UNDO;
	ret = semop(semid, &entry, 1);
	
	if(ret == -1)
	{	
		perror("Semaphore Entry Error ");
	}
	return ret;	
}
exit_sem(int semid)
{
	int ret = -1;
	struct sembuf entry;
	entry.sem_num = 0;
	entry.sem_op = 1;
	entry.sem_flg = SEM_UNDO;
	ret = semop(semid, &entry, 1);
	
	if(ret == -1)
	{	
		perror("Semaphore Exit Error ");
	}
	return ret;	
}
void delete_sem(int semid)
{

	semctl(semid,0,IPC_RMID);
}

int main()
{
	key_t key = 1234;
	pid_t pid;
	//int nsems=1,semflag = IPC_CREAT,ret;
	int ret,semid,i = 0;
/*	if(!acess("server", F_OK))
	{
		printf("server fifo is present\n");
	}
	else
	{	ret = mkfifo("server", O_RDONLY);
		if(ret)
			perror("SErver fifo not created ");
	}
*/
	semid = semget(key,1,IPC_CREAT);	
	if(semid == -1)
		perror("Semaohore not created");
	else
		printf("semid = %d\n",semid);
	ret = init_sem(semid);
	if(ret == -1)
	{
		perror("Semaphore not initialized");
	}
	pid = fork();
	switch(pid)
	{
		
	case -1:
		perror("Fork Error");
		break;
	case 0:
			
		{
			printf("In child\n");
			while(i<50)
			{
		    ret = get_entry(semid);
				strcpy(buf+i,"A");
				i++;
			  exit_sem(semid);	
				sleep(1);
			}
			puts(buf);
		}
		
		break;
	default:
		
		{
			printf("In Parent :%d\n",getpid());
			while(i < 50)
			{
		     get_entry(semid);
				strcpy(buf+i,"B");
				i++;
			  exit_sem(semid);	
				sleep(1);
			}
			puts(buf);
		}
  }
	delete_sem(semid);
}
