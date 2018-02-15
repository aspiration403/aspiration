#include"header.h"
#include"declaration.h"
//extern void unregister_chrdev_region(dev_t, unsigned nod);
static void __exit out(void)
{
	printk(KERN_INFO "Bye.. Bye..  parallel port driver\n");
	cdev_del(&Dev->kern_dev);
	unregister_chrdev_region(pdevice,1);
	release_region(BASE,8);
	kfree(Dev);	
}
module_exit(out);



