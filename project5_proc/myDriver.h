#include<linux/cdev.h>
#include<linux/semaphore.h>

struct qset
{
	char data[8];
};


struct Qset
{
	struct Qset *next;
	void **data;
};
 struct dev
{
	 int deviceSize;
	 struct cdev kern_cdev;
	 struct Qset *qset_node;
	int qset_size;
	int quantum_size;
	volatile int data_size; 
	int num_quantum;
	int num_qset;
//	struct semaphore sem;
	int cur_file_pos;
	int time_spent;
};

//static inline void sema_init(struct semaphore *sem, int val);
//extern void down(struct semaphore *sem);
//extern int __must_check down_interruptible(struct semaphore *sem);

extern struct proc_dir_entry *create_proc_entry(const char *name, umode_t mode,
                                                struct proc_dir_entry *parent);
extern void remove_proc_entry(const char *name, struct proc_dir_entry *parent);

int (driver_proc)(char *page, char **start, off_t off,
                          int count, int *eof, void *data);

extern int trim_scull(struct dev *);

extern struct dev *Dev;
//container_of(ptr, type, member)
extern struct Qset * create_sqset(int );
extern int create_qsetarr(int ,struct Qset * );
extern int create_quantum(int ,struct Qset *);
extern ssize_t driver_read (struct file *,  char __user *, size_t, loff_t *);
extern int cal_nqset(int );   //calculate the numbet of qset using data size;
extern ssize_t driver_writer (struct file *, const char __user *, size_t, loff_t *);
extern int  driver_open(struct inode *,struct file *);
//int (*release) (struct inode *, struct file *);
loff_t driver_lseek (struct file *, loff_t, int);

long driver_ioctl(struct file *,unsigned int,unsigned long *);
extern int driver_release(struct inode *,struct file *);

//int (read_proc_t)(char *page, char **start, off_t off, int count, int *eof, void *data);
