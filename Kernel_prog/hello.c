#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <asm/current.h>         //to acess current process properties
MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
  
	printk(KERN_ALERT"Hello World \n");
  printk(KERN_ALERT,"Current Process: pid :%d\n",current->pid);
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT"Goodbye,Cruel World");
}

module_init(hello_init);
module_exit(hello_exit);
