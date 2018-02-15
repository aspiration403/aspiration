#include"header.h"
#include"declaration.h"
//  ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
ssize_t p_write(struct file *fp,const char __user *ubuf,size_t size,loff_t *offset)
{
	unsigned int ret=0;
	struct mydev *pldev;
	printk(KERN_INFO "inside %s file",__FILE__);
//	unsigned char ch;
	pldev = fp->private_data;
	
		
	
		ret = copy_from_user(&pldev->buff,ubuf,1);

		printk(KERN_INFO "buff =  %c \n",pldev->buff);

		outb(pldev->buff,first_port);
	 
	
	
	printk(KERN_INFO "outside %s \n",__FILE__);

	return ret;
}
