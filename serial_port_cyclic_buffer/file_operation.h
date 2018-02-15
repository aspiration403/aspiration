
 struct file_operations fops = 
	{
		open	 :s_open,
		write	:s_write,
		read	:s_read,
		release	 : s_close
	};	
