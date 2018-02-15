#include"header.h"
/*static inline struct pci_dev *pci_get_device(unsigned int vendor,
                                             unsigned int device,
                                            struct pci_dev *from)*/
static struct pci_dev* detect_and_enable_device(void);
static struct pci_dev* detect_and_enable_device(void)
{
	struct pci_dev *ldev;
//	const struct pci_device_id *mydev = PCI_DEVICE(REALTEK_VENDER_ID,REALTEK_DEVICE_ID);
	
	ldev = pci_get_device(REALTEK_VENDER_ID,REALTEK_DEVICE_ID,NULL);	
	
	if(ldev)
	{
		#ifdef DEBUG
		printk(KERN_INFO"Realtek device found \n");
		#endif	

		if(pci_enable_device(ldev))
		{
		#ifdef DEBUG
		printk(KERN_INFO" device enabled \n");
		#endif	
		}
	
	}
	else
	{
		
		#ifdef DEBUG
		printk(KERN_INFO"Realtek device Not Found \n");
		#endif	
		
		goto OUT;
	}
	return ldev;

OUT:
	return NULL;
}


static int __init  entry(void)
{
	struct pci_dev *device;
	int ret;
	#ifdef DEBUG
	printk(KERN_INFO"Inside %s \n",__func__);
	#endif	
	

	device = detect_and_enable_device();
	
	if(device)
	{
		#ifdef DEBUG
		printk(KERN_INFO"Realtek device found \n");
		#endif
		
		
		
		
	}
	else
		goto OUT;
	pci_dev_put(device);
		




	#ifdef DEBUG
	printk(KERN_INFO"outside %s \n",__func__);
	#endif	
	
	return 0;
OUT:
	return -1;
}
module_init(entry);

