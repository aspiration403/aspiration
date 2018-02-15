#include"header.h"

//  int (*release) (struct gendisk *, fmode_t)
int sbull_close(struct gendisk * lgd, fmode_t file_mode)
{
	#ifdef DEBUG
	printk(KERN_INFO "Inside %s\n",__func__);
	#endif
	


	#ifdef DEBUG
	printk(KERN_INFO "Exit form %s\n",__func__);
	#endif
	
	return 0;
}
