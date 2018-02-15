#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
MODULE_AUTHOR("RAMAN");
MODULE_DESCRIPTION("WRITTING HELLO PROGRAM");
MODULE_LICENSE("GPL");
static int __init entry(void)
{
	printk(KERN_INFO "hi..WELCOME to world of Device Driver\n");
	return 0;
} 
module_init(entry);


