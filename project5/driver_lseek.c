#include "header.h"
#include "myDriver.h"

loff_t driver_lseek(struct file *fp , loff_t offset, int pos)
{	
	struct dev *f_ldev;
	int total_data;
	printk(KERN_INFO "Entry in %s \n",__func__);
	printk(KERN_INFO "offset = %ld \n",offset);
	printk(KERN_INFO "Starting Point for offset=%d \n",pos);
	printk(KERN_INFO "file position =%d \n",fp->f_pos);	
	f_ldev = fp ->private_data;
	total_data = f_ldev ->data_size;
	switch(pos)
	{
		case SEEK_SET:
				fp->f_pos = offset;	
				printk(KERN_INFO "New File Position =%d \n",fp->f_pos);
				break;
		case SEEK_END:
				fp->f_pos = total_data - offset;
				printk(KERN_INFO "New File Position =%d \n",fp->f_pos);
				
				//fp->f_pos = offset;	
				break;
		case SEEK_CUR:
				fp->f_pos = f_ldev->cur_file_pos + offset;	
				printk(KERN_INFO "New File Position =%d \n",fp->f_pos);
				break;
		default :
			goto OUT;
		
	}
	
	
	printk(KERN_INFO "Exit from %s \n",__func__);
		
	return fp->f_pos;
OUT :
	return -1;
}
