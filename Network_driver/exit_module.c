#include"header.h"

void __exit out(void)
{
	#ifdef DEBUG
	printk(KERN_INFO"Inside %s \n",__func__);
	#endif	
	



	#ifdef DEBUG
	printk(KERN_INFO"outside %s \n",__func__);
	#endif	
	
}
module_exit(out);

