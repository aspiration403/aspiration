//int (*open) (struct block_device *, fmode_t);
#include"header.h"
int sbull_open(struct block_device *drive, fmode_t file_mode)
{
	#ifdef DEBUG
	printk(KERN_INFO "Inside %s\n",__func__);
	#endif
	


	#ifdef DEBUG
	printk(KERN_INFO "Exit form %s\n",__func__);
	#endif
	
	return 0;
}
