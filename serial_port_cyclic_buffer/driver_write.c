#include"header.h"
#include"declaration.h"
//  ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
ssize_t s_write(struct file *fp,const char __user *ubuf,size_t size,loff_t *offset)
{

	int ret = 0,i =0;
	unsigned char data_w;
	
	//unsigned int ret=0,nocsw=0,noctw=0,flag =0;
	//int rear =-1,front=-1,lsize,i;
	struct mydev *pldev;
	printk(KERN_INFO "inside %s file\n",__FILE__);
	pldev = fp->private_data;
	printk(KERN_INFO "size of data from user =%ld \n",size);
//	lsize = size;
	
//	outb(0x00,LCR);
	for(i =0;i<size;i++)
	ret = copy_from_user(&pldev->scull_data.data[i], ubuf+i ,1);
	printk(KERN_INFO "Data in writer :%s\n",pldev->scull_data.data);
	i = 0;
	
	do
	{
		data_w = pldev->scull_data.data[i];
		printk(KERN_INFO "data from user =%c \n",data_w);
		outb(data_w,THR);    //writing data to transmiter hold register
	
	/*	lsr =lsr^lsr;
		lsr = inb(LSR);
		lsr = lsr<<2;
		lsr = lsr>>7;
		
		printk(KERN_INFO "data from user =%c \n",data_w);
		outb(data_w,THR);    //writing data to transmiter hold register
	*/
		ssleep(1);	 
		i++;
	}while(i<size);
	//outb(data_w,THR);    //to make bidirectional




/*
	while(nocsw < size)
	{
		rear ++;
		if(rear == MAX_SIZE )
		{
			rear = 0;
		}
		
			
		if(lsize > MAX_SIZE)
			noctw = MAX_SIZE;
		else
			noctw = lsize;
		
		
		
			
			ret = copy_from_user(pldev->device_scull[rear].quantum,ubuf + nocsw,noctw);
		printk(KERN_INFO "character copy from user at rear =%d  %s \n",rear,pldev->device_scull[rear].quantum);
			nocsw += (noctw - ret);
			lsize= size -nocsw;
//	}
		 
		//printk(KERN_INFO "character copy from user at rear =%d  %c \n",rear,pldev->device_scull[rear].quantum[i]);
		//nocw+= noctw - ret;
	//	printk(KERN_INFO "No. of characters =%d written  at rear =%d  \n",nocw,rear);
		
			
			front++;
			if(front == MAX_SIZE)
			front = 0;
			i = 0;
			flag = 0;

		loop2:
		{
			do{
				status^=status;
				status=inb(0x379);
				status=status>>7;
			 }while(!status);
			temp_char^=temp_char;
			temp_char = pldev->device_scull[front].quantum[i];
			if(flag == 0)
			{
				data^=data;
				temp_char = temp_char << 4;
				data = temp_char >> 4;
				flag = 1;
			}
			else
			{
				temp_char = temp_char >> 4;
				data = data | (temp_char << 4);
				flag = 0;
			}
			outb(data,first_port);
			outb(0x00,0x37A);  //making strobe to 0
			
			printk(KERN_INFO "Character written on led quantum[%d] :%c \n",i,data);
			//outb(0x01,0x37A);  //making strobe to 0
			ssleep(1);
			do
			{
				status^=status;
				status = inb(0x379);
				status=status>>7;
				printk(KERN_INFO "Checking acknowledgement %d",status);
	
			}while(!status);
			
			outb(0x21,0x37A);
			if(flag == 0)			
			{
				i++;
			}
			if(i < noctw-ret )
			{
				goto loop2;
			}
		}
			
			


	}
		
		
		//////////////////////////////////////////////////////////////////////////////////////	
	
*/
	//below code is for compatibility mode
//	outb(0x01,0x37A);	
//	outb(0x41,0x37A);    //to make bidirectional
//	outb(0x00,0x379);
	/*do
	{
		ch = ch ^ch;
		ch = inb(0x379);        //checking status reg busy pin
		ch = ch>>7;
		//if(0 == ch >>7)
		//	ssleep(1);
	}while(ch);*/
	//printk(KERN_INFO "Now device is free..\n");
	//ret = copy_from_user(&pldev->buff,ubuf ,1);
	//printk(KERN_INFO "Writer written %c \n",pldev->buff);
//	outb(pldev->buff,0x378); //data written
//	printk(KERN_INFO "Writer written_1 %c \n",pldev->buff);
	//outb(0x00,0x37A);  //making strobe to 0
//	wake_up_interruptible((&pldev->queue));
/* 	
	do
	{
		ch = ch ^ch;
		ch = inb(0x37A);   //checking acknowledgement
		ch = ch<<7;
		ch = ch>>7;
	}while(!ch);
			
*/	
	printk(KERN_INFO "writer recieve acknowledgement of receiving data \n");
	
	printk(KERN_INFO "outside %s \n",__FILE__);

	return ret;
}
