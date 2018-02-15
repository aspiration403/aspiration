
 struct file_operations fops = 
	{
		open	 :p_open,
		write	:p_write,
		read	:p_read,
		release	 : p_close
	};	
