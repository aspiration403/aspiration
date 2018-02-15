#include"header.h"
#include"declaration.h"
#include"file_operation.h"
int minor =0,major; 
dev_t pdevice;
struct mydev *Dev;
unsigned long num_port 		= NUM_PORT;
unsigned long first_port	= FIRST_PORT;
static int __init entry(void)
{
	//#ifdef DEBUG
	printk(KERN_INFO "let's start learning of parallel port\n");
	//#endif
	//extern int alloc_chrdev_region(dev_t *, unsigned, unsigned, const char *);  
	alloc_chrdev_region(&pdevice,minor,1,"P_Port_Driver");
	major = MAJOR(pdevice);
	//#ifdef DEBUG
	printk(KERN_INFO "Major No. =%d\n",major);
	//#endif
	
	Dev = (struct mydev *)kmalloc((sizeof(struct mydev)),GFP_KERNEL);
	memset(Dev,'\0',sizeof(struct mydev)); 
       //cdev_init(struct cdev *, const struct file_operations *);		initialize device
	cdev_init(&Dev->kern_dev,&fops);
	//int cdev_add(struct cdev *, dev_t, unsigned); //unsigned is no. od device adding ata time
	
	cdev_add(&Dev->kern_dev,pdevice,1);

	
	if(check_region(first_port,num_port)<3)
	{
		printk(KERN_ERR "release region first\n");
		release_region(first_port,num_port);
		printk(KERN_ERR "release region firsti\n");
	}
	
	request_region(first_port,num_port,"P_PORT_DRIVER\n");


	return 0;
}
module_init(entry);



