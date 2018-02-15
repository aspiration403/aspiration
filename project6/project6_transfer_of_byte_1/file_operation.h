
 struct file_operations fops = 
	{
		open	 :p_open,
		write	:p_write,
		release	 : p_close
	};	
