#include"header.h"
#include"declaration.h"
#include"file_operation.h"
int minor =0,major; 
dev_t pdevice;
struct mydev *Dev;
unsigned long num_port 		= NUM_PORT;

unsigned long first_port	= BASE;
static int __init entry(void)
{
	//#ifdef DEBUG
	printk(KERN_INFO "let's start learning of serial port\n");
	//#endif
	//extern int alloc_chrdev_region(dev_t *, unsigned, unsigned, const char *);  
	alloc_chrdev_region(&pdevice,minor,1,"SERIAL_Port_Driver");
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

//	init_waitqueue_head(&Dev->queue);	
//	init_waitqueue_head(&Dev->queue1);	
	if(check_region(BASE,num_port)<8)
	{
		printk(KERN_ERR "release region first\n");
		release_region(BASE,num_port);
		printk(KERN_ERR "release region firsti\n");
	}
	
	request_region(first_port,num_port,"SERIAL_PORT_DRIVER\n");
	
	//set_register();	
	outb(0x83,LCR);
	outb(0x0c,DLL);
	outb(0x00,DLM);
	
	outb(0x00,LSR);
	//outb(0x01,IER);
	outb(0x03,LCR);
/*	outb(0x00,IIR);
	outb(0x00,IER);
	outb(0x00,FCR);
	outb(0x00,MCR);
	outb(0x00,MSR);
	outb(0x00,SCR);
*/	
//	outb(0x00,LCR);

	return 0;
}
module_init(entry);


/*int set_register()
{
	
	outb(0x81,LCR);
	outb(0x00,LSR);
	outb(0x00,IIR);
	outb(0x00,IER);
	outb(0x00,FCR);
	outb(0x00,MCR);
	outb(0x00,MSR);
	outb(0x00,SCR);
	outb(0x0b,DLL);
	outb(0x00,DLM);
	return 0;
}*/
