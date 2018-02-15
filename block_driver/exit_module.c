#include"header.h"
#include"declaration.h"
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
