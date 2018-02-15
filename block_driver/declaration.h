extern int major;
extern int minor;
struct SBULL 
{
	int device_size;
	int sector_size;	//device size in sector
	u8 *data;       //Thr data array
	short users;    //how many users
	int num_sectors;
	spinlock_t lock;
	struct request_queue *Queue;  //device request queue
	struct gendisk *gd;
};
extern struct SBULL *bdev; 
extern void request_fun(struct request_queue *);
extern int sbull_open(struct block_device *drive, fmode_t file_mode);
extern int sbull_close(struct gendisk * lgd, fmode_t file_mode);
void data_io(struct request *q,unsigned int offset, unsigned int num_sector,unsigned RW_dr);
int sbull_getgeo(struct block_device * bd,struct hd_geometry *geo);
//struct request_queue *blk_init_queue(request_fn_proc *, spinlock_t *);

