#ifndef __HEADER__
#define __HEADER__

	#include<linux/kernel.h>
	#include<linux/module.h>
	#include<linux/init.h>
	#include<linux/fs.h> //for alloc_chardev_region
	#include<linux/cdev.h>   //for cdev
	#include<linux/slab.h>  //for kfree
	#include<linux/moduleparam.h>
	#include <asm/uaccess.h>
	#include<linux/ioctl.h>

	#define QUANTUM_SIZE 8
	#define QSET_SIZE 8
	#define DATA_SIZE 0
	#define NUM_QUANTUM 0
	#define NUM_QSETARR 0
	extern dev_t devNo;
	extern int nod,qset_size,quantum_size;	
	extern int major,minor;	
	MODULE_AUTHOR("Raman");
	MODULE_DESCRIPTION("Started Character Driver Module");
	MODULE_LICENSE("GPL");
#endif
