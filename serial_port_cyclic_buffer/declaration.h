#include"header.h"
extern dev_t pdevice;
extern int major,minor;
//extern unsigned long first_port,num_port;
struct scull
{
	char data[DEVICE_SIZE];
};
struct mydev
{
	struct cdev kern_dev;
//	char buff;
	wait_queue_head_t queue,queue1;
	struct scull scull_data;
	
};
/*struct __wait_queue_head {
        spinlock_t lock;
        struct list_head task_list;
};*/



extern int s_open (struct inode *, struct file *);
extern int s_close (struct inode *, struct file *);
extern ssize_t s_write (struct file *, const char __user *, size_t, loff_t *);
extern ssize_t s_read (struct file *,  char __user *, size_t, loff_t *);
extern struct mydev *Dev;





