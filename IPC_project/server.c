#include"header.h"
/*void * Addition(void *);
void * Subtraction(void *);
void * Division(void *);
void * Multiplication(void *);
*/
struct Result_Info
{
        int Result;
        pid_t Pid;
}Result_Data;
key_t key;
pthread_mutex_t Get_Result;
void init_sem(int semid,int nsem)
{
	int i,ret =-1;
	union semun init_sem;
	 init_sem.val = 1;
	for(i=0; i<nsem; i++)
	{
		ret=semctl(semid,i,SETVAL,init_sem);
		if(ret < 0)
		{
			printf("Semaphore-%d not Initialized\n",i);
			exit(EXIT_FAILURE);
		}
		else
			printf("semaphore -%d initialized sucessfully\n");
	}
}
int entry_check( semid, nth_sem)
{
	int ret=-1;
	struct sembuf sem_down;
	sem_down.sem_num = nth_sem;
	sem_down.sem_op = -1;
	sem_down.sem_flg = SEM_UNDO;
	ret = semop(semid,&sem_down,1);
	return ret;
}
int exit_check( semid, nth_sem)
{
	int ret=-1;
	struct sembuf sem_up;
	sem_up.sem_num = nth_sem;
	sem_up.sem_op = 1;
	sem_up.sem_flg = SEM_UNDO;
	ret = semop(semid,&sem_up,1);
	return ret;
}
void remove_semaphore(int semid,int nsem)
{
	
	int i ,ret=-1;
	for(i=0; i<nsem; i++)
	{
		ret = semctl(semid,i,IPC_RMID);
		if(ret < 0)
		{
			printf("Semaphore-%d not removed\n",i);
	//		exit(EXIT_FAILURE);
		}
		else
			printf("semaphore -%d removed sucessfully\n");
	}
	
}

send_result_to_client()
{
	
	char name[30];
	int fd,res,ret,nwrite;
	sprintf(name,"client%d",Result_Data.Pid);
	printf("client result fifo name :%s\n",name);
	if(access(name,F_OK))
        {
                ret = mkfifo(name,0777);
                if(ret == 0)
                        printf("client_result fifo created successfully\n");
        }
        else
                printf("client_result  fifo already exist in file system\n");
	fd = open(name,O_WRONLY);
        if(fd > 0)
        {
		res = Result_Data.Result;
                nwrite = write(fd,&res,4);
                printf("No. of bytes written =%d\n",nwrite);
                close(fd);
        }
        else
        {
                perror("client_data Fifo not opened\n");
                sleep(1);
        }



}

void * addition(void * arg)
{
	void *retval;
	int ret,flag=1;	
	struct data_info *data = NULL;
//	struct Result_Info output;
	data = (struct data_info *)(arg);	
	printf("Data is :%d \n %d \n %c \n",data->oprnd1,data->oprnd2,data->oprtr);		
	
	
		ret = pthread_mutex_lock(&Get_Result);
		if(ret == 0)
		{
		
			Result_Data.Result = (data->oprnd1 + data->oprnd2);
			Result_Data.Pid = data->pid;
			flag =0;
			send_result_to_client();
			pthread_mutex_unlock(&Get_Result);
		}
		else
			sleep(1);
	
	
//	printf("Result =%d \n",thread_result);
	
	pthread_exit("Addition Process End ");
	
      
}

void * subtraction(void * arg)
{
	void *retval;
	int ret;	
	struct data_info *data = NULL;
	struct Result_Info output;
	data = (struct data_info *)(arg);	
	printf("Data is :%d \n %d \n %c \n",data->oprnd1,data->oprnd2,data->oprtr);		
	
	
		ret = pthread_mutex_lock(&Get_Result);
		if(ret == 0)
		{
		
			Result_Data.Result = (data->oprnd1 - data->oprnd2);
			Result_Data.Pid = data->pid;
			
			send_result_to_client();
			pthread_mutex_unlock(&Get_Result);
		}
		else
			sleep(1);
	
	
//	printf("Result =%d \n",thread_result);
	
	pthread_exit("subtraction Process End ");
	
      
}

void * multiplication(void * arg)
{
	void *retval;
	int ret;	
	struct data_info *data = NULL;
	struct Result_Info output;
	data = (struct data_info *)(arg);	
	printf("Data is :%d \n %d \n %c \n",data->oprnd1,data->oprnd2,data->oprtr);		
	
	
		ret = pthread_mutex_lock(&Get_Result);
		if(ret == 0)
		{
		
			Result_Data.Result = (data->oprnd1 * data->oprnd2);
			Result_Data.Pid = data->pid;
			
			send_result_to_client();
			pthread_mutex_unlock(&Get_Result);
		}
		else
			sleep(1);
	
	
//	printf("Result =%d \n",thread_result);
	
	pthread_exit("Muliplication Process End ");
	
      
}

void * division(void * arg)
{
	void *retval;
	int ret;	
	struct data_info *data = NULL;
	struct Result_Info output;
	data = (struct data_info *)(arg);	
	printf("Data is :%d \n %d \n %c \n",data->oprnd1,data->oprnd2,data->oprtr);		
	
	
		ret = pthread_mutex_lock(&Get_Result);
		if(ret == 0)
		{
		
			Result_Data.Result = (data->oprnd1 / data->oprnd2);
			Result_Data.Pid = data->pid;
			
			send_result_to_client();
			pthread_mutex_unlock(&Get_Result);
		}
		else
			sleep(1);
	
	
//	printf("Result =%d \n",thread_result);
	
	pthread_exit("Division Process End ");
	
      
}

call_processor(struct data_info data)
{
	int ret,fd,flag =1;
	int result;
	char ch;
	void *p;
	struct data_info *data1;
	struct Result_Info res;
	
	pthread_t thread_add,thread_sub,thread_mul,thread_div;
	void *retval;
	//data1 = data;
	switch(data.oprtr)
	{
		case '+':
			
			printf("Processing for Addition\n");
			printf("Data is :%d \n %d \n %c \n",data.oprnd1,data.oprnd2,data.oprtr);
			p = &data;    
			ret = pthread_create(&thread_add,NULL,addition,p);
			if(ret)
			{
				perror("Proccessor for Addition not creadted \n");
				
			}
		/*	ret = pthread_join(thread_add,&retval);
			if(ret)
			{
				perror("Proccessor for Addition not creadted \n");
			}*/
	//		printf("\nThread joined %s\n",(char *)retval);
		/*	printf(" Thread Result :%d \n",Result_Data.Result);
			if(Result_Data.pid == data.pid)
			{
				ret = check_entry(sem_key,1);  //checking entry semap for resukt file
				if(ret)
					sleep(1);
				fd = open("Result_File",O_WRONLY);
				nwrite(fd,&Result_Data,sizeof(Result_Info));					
*/
			break;	
		case '-':
			printf("Processing for subtraction\n");
	
			printf("Data is :%d \n %d \n %c \n",data.oprnd1,data.oprnd2,data.oprtr);
			p = &data;    
			ret = pthread_create(&thread_sub,NULL,subtraction,p);
			if(ret)
			{
				perror("Proccessor for subtraction not creadted \n");
				
			}
	/*		ret = pthread_join(thread_sub,&retval);
			if(ret)
			{
				perror("Proccessor for subtrction not created \n");
			}
			printf("\nThread joined %s\n",(char *)retval);

//				printf("Data is :%d \n %d \n %c \n",data.oprnd1,data.oprnd2,data.oprtr);		
	*/			break;
		case '*':	
			printf("Processing for multiplication\n");
			printf("Data is :%d \n %d \n %c \n",data.oprnd1,data.oprnd2,data.oprtr);
			p = &data;    
			ret = pthread_create(&thread_mul,NULL,multiplication,p);
			if(ret)
			{
				perror("Proccessor for multiplication not creadted \n");
				
			}
			
	/*		ret = pthread_join(thread_mul,&retval);
			if(ret)
			{
				perror("Proccessor for multiplication not created \n");
			}
			printf("\nThread joined %s\n",(char *)retval);
	*/		break;	
		case '/':
			
			printf("Processing for Division\n");
			printf("Data is :%d \n %d \n %c \n",data.oprnd1,data.oprnd2,data.oprtr);
			p = &data;    
			ret = pthread_create(&thread_div,NULL,division,p);
			if(ret)
			{
				perror("Proccessor for Division not creadted \n");
				
			}
		/*	ret = pthread_join(thread_div,&retval);
			if(ret)
			{
				perror("Proccessor for Division not created \n");
			}
			printf("\nThread joined %s\n",(char *)retval);
		*/	break;	
		default:
				printf("Can't handle No processor found for this operation\n"); 
				printf("Data is :%d \n %d \n %c \n",data.oprnd1,data.oprnd2,data.oprtr);		
	}
	return 0;
	 
}



int main()
{	
	key_t key=255;
	int sem_key;
	int ret,nsem,fd,nread;
	struct data_info data;
	pthread_mutex_t Get_Result;
	nsem =2;
	printf(" -----SERVER-----\n");
	if(access("client_data",F_OK))
	{
		ret = mkfifo("client_data",0777);
		if(ret == 0)
			printf("client_data fifo created successfully \n");
	}
	else
		printf("client_data fifo already exist in file system\n");
	
	if(access("Result_File",F_OK))
	{
		ret = mkfifo("Result_File",0777);
		if(ret == 0)
			printf("Result file created successfully \n");
	}
	else
		printf("Result file already exist in file system\n");
			
	sem_key = semget(key,nsem,IPC_CREAT); //creating semaphore

	if(ret < 0)
	{
		perror("Semaphore not created \n");
		//exit(EXIT_FAILURE);
	}
	else
		printf("Semaphore Created\n");
	init_sem(sem_key,nsem);

	pthread_mutex_init(&Get_Result,NULL);
//	fd = open("Semaphore_Key",O_WRONLY|O_CREAT);
//	write(fd,&sem_key,4);
/*	ret = entry_check(sem_key,0);
	if(ret < 0)
	{
		perror("Semaphore Entry check fail \n");
		exit(EXIT_FAILURE);
	}
	ret=exit_check(sem_key,0);
	if(ret < 0)
	{
		perror("Semaphore Exit Check fail \n");
		exit(EXIT_FAILURE);
	}
	
*/	
	do
	{
		fd = open("client_data",O_RDONLY);
		if(fd < 2)
		{
			perror("Client_ Data fifo not opened");
	//		sleep(1);
		}
		nread = read(fd,&data,sizeof(struct data_info));	
		printf("SErver Read %d bytes data of client %d\n",nread,data.pid);
		ret = entry_check(sem_key,0);
		if(ret < 0)
		{
			perror("Semaphore Entry check fail \n");
			exit(EXIT_FAILURE);
		}
		ret = call_processor(data);
		if(ret == 0)
		{
			perror("Semaphore Exit Check fail \n");
			exit(EXIT_FAILURE);
		}
		
		ret=exit_check(sem_key,0);
		if(ret < 0)
		{
			perror("Semaphore Exit Check fail \n");
			exit(EXIT_FAILURE);
		}

		//sleep(1);

		close(fd);
	}while(nread);
	
	

	unlink("client_data");
	unlink("Result_File");	
	//remove_semaphore(sem_key,nsem);
	printf("---Exit from %s---\n",__FILE__);
	exit(EXIT_SUCCESS);
}
