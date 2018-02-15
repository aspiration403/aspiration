#ifndef __HEADER__
#define __HEADER__
 
	#include<linux/kernel.h>
	#include<linux/module.h>
//	#include<linux/parport.h>
	#include<linux/init.h>
	#include<linux/fs.h>
	#include<linux/cdev.h>
	#include<asm/uaccess.h>
	#include<linux/slab.h>
	#include<linux/wait.h>
	#include<linux/io.h>
	#include<linux/ioport.h>
	#include<linux/delay.h>
	#include<linux/sched.h>
	#define DEVICE_SIZE 64
	#define NUM_PORT 8 
	#define BASE 0x3f8	
	#define DLL 0x3f8	
	#define RBR 0x3f8
	#define THR 0x3f8
	#define IER 0x3f9
	#define DLM 0x3f9
	#define IIR 0x3fa
	#define FCR 0x3fa
	#define LCR 0x3fb
	#define MCR 0x3fc
	#define LSR 0x3fd
	#define MSR 0x3fe
	#define SCR 0x3ff
		

	//#define BUF_SIZE 8	
	//#define MAX_SIZE 8

	MODULE_AUTHOR("RAMAN");
	MODULE_DESCRIPTION("SERIAL PORT DRIVER");
	MODULE_LICENSE("GPL");
#endif
