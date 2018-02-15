#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
#include<string.h>
// int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
//int msgget(key_t key, int msgflg);
// msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,int msgflg);
//                     
//       int msgctl(int msqid, int cmd, struct msqid_ds *buf);
int delete_msgque1(int msgqid)
{
	int ret=-1;
	ret=msgctl(msgqid,IPC_RMID,0);
	return ret;	
}
struct msgbuf
{
	long mtype;
	char mtext[BUFSIZ];
}block,block1;	

int main()
{
	struct msgbuf recv_data,recv_data1;
	char buf[BUFSIZ],buf1[BUFSIZ],chk[5];
	key_t key=15;
	int msgqid,ret=-1;
	printf("Creating Message Queue \n");	
	msgqid=msgget(key,IPC_CREAT);
        if(msgqid==-1)
		perror("Msgque not created");
	//creating payload structure
	printf("Enter message or For exit enter exit\n");
	do
	{
		printf("Enter message :%d\n",getpid());
		memset(buf,0,BUFSIZ);
		fgets(buf,BUFSIZ,stdin);
		block.mtype=12;
		strcpy(block.mtext,buf);
	//block1.mtype=11;
	//strcpy(block1.mtext,"I am raman");
		strncpy(chk,buf,4);
		ret=msgsnd(msgqid,&block,BUFSIZ,0);	
		if(ret==-1)
		perror("Message not sent!!\n");
		
	}while(strcmp(chk,"exit"));
	
	/*ret=msgsnd(msgqid,&block1,BUFSIZ,0);	
	if(ret==-1)
		perror("Message not sent!!\n");
	printf("Now inside receiver :\n");
	while(1)
	{ret=msgrcv(msgqid,&recv_data,BUFSIZ,12,0);
	
	
	printf("data is %s\n",recv_data.mtext);
	}*/
	//printf("data is %s\n",recv_data.mtext);
	delete_msgque1(msgqid);	
	return 0;
}
