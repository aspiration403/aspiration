#include"header.h"
#include"myDriver.h"
 int trim_scull(struct dev *ldev)
{
	struct dev *tdev=NULL;
	struct Qset *start,*lqset,*prev_qset=NULL; 
	int start_flag=0,i,count,num_qntm,nq;
	tdev=ldev;
	num_qntm = tdev->num_qset;
	printk(KERN_INFO "Entry inside %s",__func__);
	printk(KERN_INFO "Number of Quantum=%d \n",num_qntm);
	if(tdev->qset_node)
	{
		prev_qset=start=lqset=tdev->qset_node;
	
	}
	else
	{
		printk(KERN_INFO "Scull is Empty \n");
		goto OUT;
	}
	while(start)
	{
		count = 0;
		lqset = start;
		if(NULL== start->next)
		{
			printk(KERN_INFO " Trimming first node\n");
			start_flag = 1;
		}
		
		while(lqset->next)
		{
			count++;
			prev_qset = lqset;
			lqset = lqset->next;
		}   
	    
        	if(lqset->data)
		{
			
			printk(KERN_INFO " -----Trimming  -----%d ---qset----\n ",count);
			if(num_qntm > 0 && ((num_qntm % QSET_SIZE)!=0))
			{
				nq= (num_qntm % QSET_SIZE);	
			}
			else if(num_qntm == 0)
			{
				printk(KERN_INFO "!!!!!! This qset has no Quantum \n");
				nq = 0;
			}
			else
				nq = QSET_SIZE;
	
					
                        for(i=0; i < nq;i++)
			{
				if(lqset->data[i])
				{
					kfree(lqset->data[i]);
					lqset->data[i] = NULL;
					printk(KERN_INFO "Quantum --->%d   is Now freed up  \n",i);
				}
				else
				{
					printk(KERN_INFO "Quantum %d  Data is NULL  \n",i);
					kfree(lqset->data[i]);
				
				}		
			
			}
			num_qntm = num_qntm-nq;
			lqset->data = NULL;
			if(start_flag == 1)
			{
				kfree(lqset);
				lqset = NULL;
				prev_qset = NULL;
			}
			else
			{
				kfree(lqset);
				lqset =NULL;
				prev_qset->next = NULL;
			}
		
		}
		else
		{
			printk(KERN_INFO "--------free the Scull Data ------  \n");
			kfree(lqset);
			lqset = NULL;
			prev_qset->next = NULL;
		}
		
		if(start_flag == 1)
			break;
	}





	
	printk(KERN_INFO "End inside %s",__func__);
		
	return 0;
	
	OUT:
		return -1;
}
