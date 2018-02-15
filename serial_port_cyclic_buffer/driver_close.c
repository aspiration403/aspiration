#include"header.h"
   //int (*open) (struct inode *, struct file *);
 int s_close(struct inode *ip,struct file *fp)
{
	printk(KERN_INFO "in %s file releasing successfully",__func__);
	/*struct mydev ldev;
	
	ldev = container_of(ip->i_cdev,struct mydev,kern_cdev);
	if(!ldev)
	
		printk(KERN_ERR "container of error \n");
 	else
		printk(KERN_INFO "Mapped to io space successfully");
	fp->private_data = ldev;
	*/
	return 0;
}
