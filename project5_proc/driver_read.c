#include "header.h"
#include "myDriver.h"
// ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);


ssize_t driver_read(struct file *fp,  char  __user *ubuf, size_t size, loff_t * ofset) 
{

	struct dev *ldev;
	struct Qset* sqset=NULL;
	int nbr,q,ret,loc,i,nqset,bytes_to_read,nbrs,remaining_byte=0,offset,offset1,start_point=0;
	
	printk(KERN_INFO "Entry In function ------>%s\n",__func__);
	wait_for_completion(&comp);	
	offset=offset1 = fp->f_pos;
	ldev = fp->private_data;
	sqset=ldev->qset_node;
//	if(down_interruptible(&ldev->sem))
//		return ERESTARTSYS;
	
	printk(KERN_INFO "value of offset=  ------>%d\n",*ofset);
	printk(KERN_INFO "value of file->position =  ------>%d\n",fp->f_pos);
	printk(KERN_INFO "Data Size :%d\n",ldev->data_size);
	
	i=q=nbrs=loc=0;
	start_point = nbr=(ldev->data_size) ;
	nqset =ldev ->num_qset;	
	
	if(size < nbr)
		nbr = size;
	else
		size = nbr - offset;


	

	while(offset1 > QSET_SIZE * QUANTUM_SIZE)
 	{

		if(sqset -> next)
		{
			sqset = sqset->next;
			offset1 = offset1 - (QSET_SIZE * QUANTUM_SIZE);
		}
		else
			printk(KERN_INFO " Data is not available");
	}
	
	q+=(offset/QSET_SIZE);
	nqset =nqset - q;
	if(q > QSET_SIZE)
	{
		q = q % QSET_SIZE;	
	} 
	offset = offset % QUANTUM_SIZE;  // if offset is greater than quantum size

	bytes_to_read=QUANTUM_SIZE-offset;
	
	
	
	//loc+=offset%QSET_SIZE;
	//size-=offset;
	if(size < bytes_to_read)
		bytes_to_read = size;
	//nqset = nqset -q;
	printk(KERN_INFO " No. of Bytes to read= %d\n and number of qset=%d\n",nbr,nqset);
	for(i=0;i<nqset;i++)
	{
		if(i==0)
		{
		ret=copy_to_user(ubuf+loc,sqset->data[q]+offset,bytes_to_read);
		
		nbrs +=(bytes_to_read-ret);
		ldev->cur_file_pos= nbrs + fp->f_pos;
		printk(KERN_INFO " Value of q =%d and i=%d and ret= %d and loc =%d \n and Data --->%s \n", q,i,ret,loc,ubuf+loc);
		
		}
		else
		{
		ret=copy_to_user(ubuf+loc,sqset->data[q],bytes_to_read);
		
		nbrs +=(bytes_to_read-ret);
		ldev->cur_file_pos +=(bytes_to_read - ret);
		printk(KERN_INFO " Value of q =%d and i=%d and ret= %d and loc =%d \n and Data --->%s \n", q,i,ret,loc,ubuf+loc);
		
		}
				
		remaining_byte = size - nbrs;
		if(remaining_byte < QUANTUM_SIZE)
			bytes_to_read = remaining_byte;
		else
			bytes_to_read = QUANTUM_SIZE;

		if((q==QSET_SIZE-1)&&(sqset->next))
		{
			q=0;
			sqset=sqset->next;
		}
		else
			q++;
		loc =nbrs;
		fp ->f_pos = loc;
	}
	//up(&ldev->sem);

//	printk(KERN_INFO " in file %s  \n-------sizeof data =%d------ Data --->\n%s \n",__FILE__,sizeof(ubuf),ubuf);

	





	printk(KERN_INFO "Exit from  function ------>%s",__func__);
	return nbrs;
}
