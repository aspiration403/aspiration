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

int major,minor;


MODULE_LICENSE("Dual BSD/GPL");
static struct SBULL
{
        int device_size;
        int sector_size;        //device size in sector
        u8 *data;       //Thr data array
        short users;    //how many users
        int num_sectors;
        spinlock_t lock;
        struct request_queue *Queue;  //device request queue
        struct gendisk *gd;
}*bdev;

//static void data_io(struct request *q,unsigned int offset, unsigned int num_sector,unsigned int RW_dr);

//static void data_io(struct request *q,unsigned int offset, unsigned int num_sector,unsigned int RW_dr)
            


static void data_io(struct SBULL *ldev,char * buffer,unsigned int offset, unsigned int num_sector,unsigned int RW_dr)
{
        int num_b_RW =0;  //number of bytes to write or read
        #ifdef DEBUG
        printk(KERN_INFO "Inside %s \n",__func__);
        #endif

        num_b_RW = ( num_sector )*SECTOR_SIZE;
        if((offset + num_sector) > NUM_SECTORS )
        {
                printk(KERN_ERR "ERROR : Memory not available\n");
                return ;
        }

        if(RW_dr == 1)
        {
                printk(KERN_INFO "writing data to block device\n");
                printk(KERN_INFO "Data to write :%s\n",(char *)buffer);
                memcpy((ldev->data)+offset , buffer,num_b_RW);
        }
        if(RW_dr == 0 )
        {

                printk(KERN_INFO "Reading data to block debvice\n");
                memcpy(buffer,(ldev->data)+offset ,num_b_RW);
		   printk(KERN_INFO "Data read from disk :%s\n",(char *)buffer);

        }

        #ifdef DEBUG
        printk(KERN_INFO "out from %s \n",__func__);
        #endif
}

static void request_fun(struct request_queue *q)
{
        struct request *temp_req;
        #ifdef DEBUG
        printk(KERN_INFO "Inside %s \n",__func__);
        #endif
        temp_req = blk_fetch_request(q);
        while(temp_req != NULL)
        {
                if(temp_req == NULL || (temp_req->cmd_type != REQ_TYPE_FS))
                {
                        printk(KERN_ALERT "Skip Non Cmd Request\n");
                        __blk_end_request_all(temp_req,-EIO);
                        continue;
                }


                data_io(bdev,temp_req->buffer,blk_rq_pos(temp_req),blk_rq_sectors(temp_req),rq_data_dir(temp_req));
                if(!__blk_end_request_cur(temp_req,0))
                {
                        temp_req = blk_fetch_request(q);
                }
        }

 #ifdef DEBUG
        printk(KERN_INFO "out from %s \n",__func__);
        #endif
}

static int sbull_getgeo(struct block_device * bd,struct hd_geometry *geo)
{
        long size;

        /* We have no real geometry, of course, so make something up. */
        size = (bdev->device_size )* (HW_SECTOR_SIZE/SECTOR_SIZE);
        geo->cylinders = (size & ~0x3f)>>6;
        geo->heads = 4;
        geo->sectors = 16;
        geo->start = 0;
        return 0;
}
static struct block_device_operations bop= {
					.owner = THIS_MODULE,
					.getgeo = sbull_getgeo
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
static void __exit out(void)
{
	#ifdef DEBUG
	printk(KERN_INFO "Inside %s \n ",__func__);
	#endif
	//del_gendisk(bdev->gd);
	del_gendisk(bdev->gd);
	put_disk(bdev->gd);
	unregister_blkdev(major,DRIVER);
	blk_cleanup_queue(bdev->Queue);
	vfree(bdev->data);
	
	
	#ifdef DEBUG
	printk(KERN_INFO "Exit from %s \n",__func__);
	#endif

}
module_exit(out);
