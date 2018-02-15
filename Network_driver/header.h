#include<linux/module.h>
#include<linux/netdevice.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/pci.h>
#include<linux/stddef.h>

#define REALTEK_VENDER_ID 0x10EC
#define REALTEK_DEVICE_ID 0x8168

#ifndef DEBUG
#define DEBUG
#endif

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAMAN");
MODULE_DESCRIPTION("Writing Network Driver for REaltek PCI DEvice 8168");
