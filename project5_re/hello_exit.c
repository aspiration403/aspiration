#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
MODULE_AUTHOR("RAMAN");
MODULE_DESCRIPTION("WRITTING HELLO PROGRAM");
MODULE_LICENSE("GPL");
static void  __exit out(void)
{

	printk(KERN_INFO "OK..Bye Bye cruel world of Device Driver\n");
	
} 
module_exit(out);


