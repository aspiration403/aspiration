#include "header.h"
#include "myDriver.h"
int extern driver_release(struct inode *p,struct file * fp) 
{
	printk(KERN_INFO "in %s File released successfully",__func__);
	return 0;
}
