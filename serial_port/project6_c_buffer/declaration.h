#include"header.h"
extern dev_t pdevice;
extern int major,minor;
extern unsigned long first_port,num_port;
struct quantum
{
	char data[MAX_SIZE];
};
struct scull
{
	struct quantum quant[MAX_SIZE];
};
struct mydev
{
	struct cdev kern_dev;
	char buff;
	struct scull qset[MAX_SIZE];
	
};
extern int p_open (struct inode *, struct file *);
extern int p_close (struct inode *, struct file *);
extern ssize_t p_write (struct file *, const char __user *, size_t, loff_t *);
extern struct mydev *Dev;





