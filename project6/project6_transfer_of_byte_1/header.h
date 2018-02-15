#ifndef __HEADER__
#define __HEADER__
 
	#include<linux/kernel.h>
	#include<linux/module.h>
	#include<linux/parport.h>
	#include<linux/init.h>
	#include<linux/fs.h>
	#include<linux/cdev.h>
	#include<asm/uaccess.h>
	#define NUM_PORT 3
	#define FIRST_PORT 0x378	
//	#define BUF_SIZE 8	


	MODULE_AUTHOR("RAMAN");
	MODULE_DESCRIPTION("PARALLEL PORT DRIVER");
	MODULE_LICENSE("GPL");
#endif
