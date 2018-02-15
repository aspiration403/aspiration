
struct file_operations fileop= {
	open:driver_open,
	write:driver_writer,
	release :driver_release,
	read:driver_read,
	llseek:driver_lseek,
	unlocked_ioctl:driver_ioctl
}; 
