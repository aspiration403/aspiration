#include"header.h"
#include"myDriver.h"
//extern void unregister_chrdev_region(dev_t, unsigned);
//struct dev *Dev;
static void __exit out(void)
{
	printk(KERN_INFO"Bye Bye Kernel.......\n");
	unregister_chrdev_region(devNo,nod);
	kfree(Dev);
	
}
module_exit(out);
