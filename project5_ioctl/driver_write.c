#include "header.h"
#include "myDriver.h"
// ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);

int cal_nqset(int size)
{
	int nqset;
	nqset=size/(qset_size);
	if(size%(qset_size)>0)
		nqset++;
	return nqset;
}
int cal_nsqset(int size)
{
	int nsqset;
	nsqset=size/(quantum_size*qset_size);
	if(size%(quantum_size * qset_size)>0)
		nsqset++;
	return nsqset;
}


ssize_t driver_writer(struct file *fp, const char  __user *ubuf, size_t size, loff_t * offset) 
{

	struct dev *f_ldev;
	struct Qset* sqset=NULL;
	int nsqset,i,q=0,ret,nqset,loc=0,bytes_to_write=QUANTUM_SIZE,remaining_bytes,bytes_written=0;
	printk(KERN_INFO "Entry In function ------>%s",__func__);
	printk(KERN_INFO "Data in ubuff is %s \n and size is %d \n",ubuf,size);
	nsqset=cal_nsqset(size);
	printk(KERN_INFO "Number of Struct Qset =%d\n",nsqset);
	nqset=cal_nqset(size);
	
	printk(KERN_INFO "Number of  Qset array =%d \n",nqset);
	f_ldev=fp->private_data;

	if(down_interruptible(&f_ldev->sem))
		return ERESTARTSYS;

	f_ldev->qset_node=create_sqset(nsqset);
	sqset = f_ldev-> qset_node;
	create_qsetarr(nsqset,sqset);
	create_quantum(nqset,sqset);
	if(size < bytes_to_write)
	{
		bytes_to_write = size;
	}
	remaining_bytes=size;
	for(i=0;i<nqset;i++)
	{	
		ret=copy_from_user(sqset->data[q],ubuf+loc,bytes_to_write);
		remaining_bytes -= (bytes_to_write + ret);
		printk(KERN_INFO "No. of byts written :%d \t and \n Data is :%s\n",bytes_to_write,sqset->data[q]);

		bytes_written +=(bytes_to_write - ret);
		loc = bytes_written;
		if(remaining_bytes < bytes_to_write)
			bytes_to_write=remaining_bytes;
		

		if((q==QSET_SIZE-1 && i < nqset)&& (sqset->next))
		{
				sqset = sqset->next;
				q=0;
		}	
		else
			q++;
		fp ->f_pos = bytes_written;
		f_ldev->cur_file_pos = bytes_written;
	}
	
	
	
		
	
	up(&f_ldev->sem);
	f_ldev->data_size = bytes_written;
	f_ldev->num_qset = nqset; 
		
	fp ->f_pos = bytes_written;
	
	printk(KERN_INFO "updated file position %d\n",fp->f_pos);
	printk(KERN_INFO "Exit from  function ------>%s\n",__func__);
	return bytes_written;
}
struct Qset* create_sqset(int nsqset)
{
	struct Qset *fsqset,*sqset;
	int i;
	fsqset = NULL;
	sqset = NULL;
	for(i=0;i<nsqset;i++)
	{
		if(i==0)
		{
			fsqset=sqset=(struct Qset *)kmalloc(sizeof(struct Qset ),GFP_KERNEL);	
			
			if(fsqset)
			{
				printk(KERN_INFO "Memory Alocated for  Sqset");
				fsqset->data=NULL;
				fsqset->next=NULL;
			}
			else
				printk(KERN_ERR "Memory not allocated for strut qset");
		}
		else
		{
	
			sqset->next=(struct Qset *)kmalloc(sizeof(struct Qset ),GFP_KERNEL);	
			
			if(sqset->next)
			{
				printk(KERN_INFO "Memory Alocated for  Sqset");
				sqset=sqset->next;
				
				sqset->data=NULL;
				sqset->next=NULL;
			}

			else
				printk(KERN_ERR "Memory not allocated for strut qset");
	
		}
	}
	return fsqset;
}
int create_qsetarr(int nsqset,struct Qset *ldev )
{
	struct Qset *localdev;
	int i=0;
	localdev=ldev;
	for(i=0; i< nsqset;i++)
	{
		if(localdev)
		{
			localdev->data=kmalloc((sizeof(struct qset * )*QSET_SIZE),GFP_KERNEL);	
			if(NULL!=localdev->data)
			{
				printk(KERN_INFO "Memory Alocated for  qset Array");
				if(localdev->next)
					localdev=localdev->next;
			}	
			else
				printk(KERN_ERR "Memory not allocated for  qset");
		}
		else
		{
			
			printk(KERN_ERR "Memory not allocated for  qset");
			goto OUT;
		}	
		
	
	}
OUT:
	return -1;
return 0;
}


int create_quantum(int quant,struct Qset *ldev)
{
	int i=0,q=0;
	struct Qset *sqset;
	sqset=ldev;
	for(i=0;i<quant;i++)
	{
		if(sqset)
		{
			sqset->data[q]=(struct qset *)kmalloc((sizeof(struct qset )),GFP_KERNEL);	
			if(sqset->data[q])
			{
				printk(KERN_INFO "Memory Alocated for  quantum \n");
			}	
			else
				printk(KERN_ERR "Memory not allocated for  qset");
		}
		if((q==QSET_SIZE-1 && i < quant)&& (sqset->next))
		{
				sqset = sqset->next;
				q=0;
		}	
		else
			q++;
	}
	return 0;
}
