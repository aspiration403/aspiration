#include "header.h"
#include "myDriver.h"
int extern driver_open(struct inode *p,struct file * fp) 
{

	struct dev *ldev;
	printk(KERN_INFO "in %s File open sucessfully",__func__);
//	struct inode *cdev_addr;
	 ldev = container_of(p->i_cdev,struct dev,kern_cdev);
//
	if(!ldev)
		printk(KERN_ERR "container of error");
	else
		printk(KERN_INFO "mapped to io space sucessfully");

	if((fp->f_flags & O_ACCMODE)==O_WRONLY)
	{
		trim_scull(ldev);	
	}

	fp->private_data=ldev;
	return 0;
}
