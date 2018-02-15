#include"header.h"
#include"declaration.h"
void check(void);
ssize_t s_read(struct file *fp,char __user *ubuff,size_t size,loff_t *offset)
{
	#ifdef DEBUG
	printk(KERN_INFO "Begin..%s\n",__FILE__);
	#endif

//struct mydev *rdev;
	unsigned char ch,data_buff[DEVICE_SIZE];
	int ret =0,rear = -1;
	ch=ch^ch;
//rdev = fp->private_data;
	do
	{
		check();
		ch=inb(RBR);
		rear++;
		data_buff[rear]=ch;
		printk(KERN_INFO "Data in driver...%c\n",ch);
		if(rear == DEVICE_SIZE-1)
		{
			printk(KERN_INFO "Buffer is full...%c\n",ch);
		
			rear = -1;
		}
	}while(ch!='z');
	
	if(size >= DEVICE_SIZE )
		size=DEVICE_SIZE;
	data_buff[rear] = '\0';	
	ret  =copy_to_user(ubuff,data_buff,size);
//if(!ret)
//{
//	printk(KERN_ERR "copy from user failed....%s\n",__FILE__);
//	return -1;
//}
	#ifdef DEBUG_C
	printk(KERN_INFO "bytes read for user..:%d\n",ret);
	#endif

	#ifdef DEBUG
	printk(KERN_INFO "End....%s\n",__FILE__);
	#endif

	return ret;
}
void check(void)
{
	char temp;
	do
	{
		temp = temp ^ temp;
		temp = inb(LSR);
		temp = temp<<7;
		temp = temp>>7;

//		printk(KERN_INFO "ready bit. =%d\n",temp);
	}while(!temp);
}
