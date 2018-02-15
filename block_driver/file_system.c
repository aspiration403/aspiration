#include"header.h"
#include"declaration.h"
  //    int (*getgeo)(struct block_device *, struct hd_geometry *);
int sbull_getgeo(struct block_device * bd,struct hd_geometry *geo)
{
	long size;
	
        /* We have no real geometry, of course, so make something up. */
        size = (bdev->device_size )* (HW_SECTOR_SIZE/SECTOR_SIZE);
        geo->cylinders = 20;
        geo->heads = 4;
        geo->sectors = 16;
        geo->start = 0;
	return 0;
}
