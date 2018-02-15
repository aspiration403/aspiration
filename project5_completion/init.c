#include"header.h"
#include"myDriver.h"
#include"file_operations.h"
//extern int alloc_chrdev_region(dev_t *, unsigned, unsigned, const char *);
// int cdev_add(struct cdev *, dev_t, unsigned);//unsigned is num of devices
//void cdev_init(struct cdev *, const struct file_operations *);
int nod;
module_param(nod,int,S_IRUGO);


struct dev *Dev;  
struct completion comp;
dev_t devNo,dev_nod;
int major ,minor=0;
int quantum_size=QUANTUM_SIZE;
int qset_size = QSET_SIZE;
static  int __init entry(void)
	{
		int lv=0;
		printk(KERN_ALERT "Hello inserted into kernel module\n");
		 alloc_chrdev_region(&devNo, minor, nod, "Character_driver");
		major=MAJOR(devNo);
		Dev=(struct dev *)kmalloc((sizeof(struct dev )*nod),GFP_KERNEL);
		memset(Dev,'\0',sizeof(struct dev)*nod);
		init_completion(&comp);
		for(lv=0;lv<nod;lv++)
		{
		//	Dev[lv]=(struct dev *)kmalloc((sizeof(struct dev )*nod),GFP_KERNEL);
			
			cdev_init(&Dev[lv].kern_cdev,&fileop);
			dev_nod=MKDEV(major,lv);
			minor=MINOR(dev_nod);
			major=MAJOR(dev_nod);
			Dev[lv].quantum_size=QUANTUM_SIZE;
			Dev[lv].qset_size=QSET_SIZE;
			Dev[lv].data_size=DATA_SIZE;
			Dev[lv].num_quantum=NUM_QUANTUM;
			Dev[lv].num_qset=NUM_QSETARR;
//			sema_init(&Dev[lv].sem,1);			
//			init_completion(&Dev[lv].comp);
			printk(KERN_INFO "Major No. =%d \n",major);
			printk(KERN_INFO "Minor No. =%d \n",minor);
			cdev_add(&Dev[lv].kern_cdev,devNo,1);
				
		}
//			INIT_COMPLETION(comp);
		return 0;
	}
module_init(entry);
