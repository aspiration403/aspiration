//typedef int (read_proc_t)(char *page, char **start, off_t off,
//                          int count, int *eof, void *data);

#include "header.h"
#include "myDriver.h"
//struct proc_dir_entry myproc;
driver_proc(char *page,char **start,off_t off,int count,int *eof,void *data)
{
	struct dev *ldev;
	char *buf;
	int len = 0;
	start = NULL;
	off = 0;
	buf = (char *)kmalloc((sizeof(buf)*100),GFP_KERNEL);
	if(!buf)
	{
		printk(KERN_ERR "Kmalloc Failed");
//		goto out;
	}
	memset(buf,'\0',(sizeof(buf)*100));
	ldev = (struct dev *)data;
	if(!ldev)
	{
		printk(KERN_ERR "ldev address not found");
	//	goto out;
	}
	strcpy(page,"Raman Character Driver Description \n");
	len = strlen(page);
	sprintf(buf,"Quantum size :%d",ldev->quantum_size);
	strcpy(page+len,buf); 
	len = strlen(page);
	//strcpy(page+len,"Quantum Size :");*/
		
//	sprintf(page+strlen(buf),"\n 
	kfree(buf);	
	
//out:
//	return -1;

	return len;
}	

