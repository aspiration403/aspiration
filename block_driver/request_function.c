#include"header.h"
#include"declaration.h"
void request_fun(struct request_queue *q)
{
	struct request *temp_req;
	#ifdef DEBUG
	printk(KERN_INFO "Inside %s \n",__func__);
	#endif
	temp_req = blk_fetch_request(q);
	while(temp_req != NULL)
	{
		if(temp_req == NULL || (temp_req->cmd_type != REQ_TYPE_FS))
		{
			printk(KERN_ALERT "Skip Non Cmd Request\n");
			__blk_end_request_all(temp_req,-EIO);
			continue;
		}
		

		data_io(temp_req,blk_rq_pos(temp_req),blk_rq_sectors(temp_req),rq_data_dir(temp_req));
		if(!__blk_end_request_cur(temp_req,0))
		{
			temp_req = blk_fetch_request(q);
		}
	}



	#ifdef DEBUG
	printk(KERN_INFO "out from %s \n",__func__);
	#endif
}
