#include"header.h"
#include "declaration.h"
//#include "block_dev_operations.h"
int major;
int minor; 
struct SBULL *bdev;

struct block_device_operations bop= {
					getgeo : sbull_getgeo
				};


static int __init entry(void)
{
	 major = MAJOR_NO;
	 minor = MINOR_NO; 
	#ifdef DEBUG
	printk(KERN_INFO "Inside %s \n",__FILE__);
	#endif
	
	bdev = kmalloc(sizeof(struct SBULL),GFP_KERNEL);	
	if(!bdev)
	{
	#ifdef DEBUG
	printk(KERN_ERR "Memory for Scull Not found !!!\n");
	#endif
	unregister_blkdev(major,DRIVER);
	goto OUT;	
	}

	bdev ->sector_size = SECTOR_SIZE;
	bdev ->num_sectors = NUM_SECTORS;
	bdev->device_size = (bdev->sector_size)*(bdev->num_sectors);
	
	#ifdef DEBUG
	printk(KERN_INFO "DEVICE SIZE =:%d \n ",bdev->device_size);
	#endif
		
	bdev ->data = vmalloc(bdev->device_size); //data array size	
	if(!bdev ->data)
	{
	#ifdef DEBUG
	printk(KERN_ERR "Memory not allocated for data\n");
	#endif
	goto OUT;
	}

	spin_lock_init(&bdev->lock);
	bdev->Queue = blk_init_queue(request_fun,&bdev->lock);

	//extern void blk_queue_logical_block_size(struct request_queue *, unsigned short);
	//seccond argument is sector size
	blk_queue_logical_block_size(bdev ->Queue, bdev->sector_size );
	
	major = register_blkdev(major,DRIVER);
	#ifdef DEBUG
	printk(KERN_INFO "MAJOR NO.:%d \n ",major);
	#endif
	
	bdev->gd = alloc_disk(16);
	if(!bdev->gd)
	{
		#ifdef DEBUG
		printk(KERN_ERR "Memory not allocated for gendisk\n");
		#endif
		goto OUT;
	}
	else
	{
		#ifdef DEBUG
		printk(KERN_INFO "Initializing parameters for gendisk\n");
		#endif
		
		bdev ->gd->major = major;
		bdev ->gd->first_minor = 0;
	//	bdev ->gd->minors = NUM_MINORS;
		sprintf(bdev->gd->disk_name,"%s",DISK_NAME);
		bdev ->gd->fops = &bop;
		bdev->gd->queue = bdev ->Queue;
		bdev->gd->private_data = bdev;
		set_capacity(bdev->gd,bdev->num_sectors );
		
		add_disk(bdev->gd);
		
	}
	
	#ifdef DEBUG
	printk(KERN_INFO "Exit from %s \n",__FILE__);
	#endif
	return 0;
OUT:
	return -1;
}
module_init(entry);
