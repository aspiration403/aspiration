#include "myDriver.h"
#include "header.h"
#include "ioctl_header.h"
long driver_ioctl(struct file *fp,unsigned int cmd,unsigned long *arg) 

//long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
{
	struct dev *ldev;
	ldev = fp ->private_data;
	printk(KERN_INFO "______Inside %s_____",__FILE__);
	switch(cmd)
	{
		case SCULL_RESET:
				//trim_scull(Dev);
				ldev->quantum_size = 8;
				ldev->qset_size = 8;
				ldev->data_size = 0;
				ldev->num_quantum = 0;
				ldev->num_qset = 0;
				break;	
		case SCULL_QUANTUM_OUT:
				put_user(ldev->quantum_size,(unsigned int  __user*)arg); 
				break;	
		case SCULL_QSET_SIZE:
				put_user(ldev->qset_size,(unsigned int __user*)arg); 
				break;	
		case SCULL_QUANTUM_SET:
				get_user(ldev->num_quantum,(unsigned int __user*)arg);
				break;	
		case SCULL_QSETSIZE_SET:
				get_user(ldev->qset_size,(unsigned long __user*)arg);
				break;	
	}
	return 0;	
}
