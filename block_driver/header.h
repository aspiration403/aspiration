#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/blkdev.h>
#include<linux/types.h>
#include<linux/blkdev.h>
#include<linux/genhd.h>
#include<linux/hdreg.h>
#define MAJOR_NO 0
#define MINOR_NO 0
#define NUM_MINORS 16 
#define SECTOR_SIZE 512
#define HW_SECTOR_SIZE 512
#define NUM_SECTORS 1280 
#ifndef DEBUG
#define DEBUG
#endif

#define DRIVER "R_BLK_DRIVER"
#define DISK_NAME "R_BLK_DISK"



MODULE_AUTHOR("RAMAN");
MODULE_DESCRIPTION("Started Block Driver writting");
MODULE_LICENSE("Dual BSD/GPL");

