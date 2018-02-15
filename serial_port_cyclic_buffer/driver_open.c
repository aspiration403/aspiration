#include"header.h"
#include"declaration.h"
   //int (*open) (struct inode *, struct file *);
 int s_open(struct inode *ip,struct file *fp)
{
	struct mydev *ldev;
	
	ldev = container_of(ip->i_cdev, struct mydev, kern_dev);
	if(!ldev)
	
		printk(KERN_ERR "container of error \n");
 	else
		printk(KERN_INFO "Mapped to io space successfully\n");
	fp->private_data = ldev;
	
	return 0;
}
