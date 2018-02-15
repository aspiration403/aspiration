#include"header.h"
#include"declaration.h"
//  ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
ssize_t p_read (struct file *fp, char __user *ubuf,size_t size,loff_t *offset)
{
	unsigned int ret = 0;
	unsigned char ch;
	printk(KERN_INFO "Inside %s file\n",__FILE__);
	outb(0x00,RBR);
	ch = ch^ch;
	ch = inb(RBR);
		
	printk(KERN_INFO "data in reader :%c\n",ch);
	ret = copy_to_user(&ch,ubuf,1);
	printk(KERN_INFO "Data read  in Driver  %c ,%d:\n",ch,ch);
	printk(KERN_INFO "OUT from %s file\n",__FILE__);
	return ret;



}
