#include"header.h"
#include"declaration.h"
void data_io(struct request *q,unsigned int offset, unsigned int num_sector,unsigned int RW_dr)
{
	int num_b_RW =0;  //number of bytes to write or read
	#ifdef DEBUG
	printk(KERN_INFO "Inside %s \n",__func__);
	#endif
		
	num_b_RW = ( num_sector )*SECTOR_SIZE;


	if((offset + num_sector) > NUM_SECTORS )
	{
		printk(KERN_ERR "ERROR : Memory not available\n");
		return ;
	}

	
	
	if(RW_dr == 1)
	{
		printk(KERN_INFO "writing data to block device\n");
		printk(KERN_INFO "Data to write :%s\n",(char *)q->buffer);
		memcpy((bdev->data)+offset , q->buffer,num_b_RW);
	}
	if(RW_dr == 0 )
	{
	
		printk(KERN_INFO "Reading data to block debvice\n");
		memcpy(q->buffer,(bdev->data)+offset ,num_b_RW);
		printk(KERN_INFO "Data read from disk :%s\n",(char *)q->buffer);
	
	}








	#ifdef DEBUG
	printk(KERN_INFO "out from %s \n",__func__);
	#endif
}
