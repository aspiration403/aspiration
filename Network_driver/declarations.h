
struct my_private
{
	struct net_device_stats stats;
	int status;
	struct snull_packet *ppool;
	struct snull_packet *rx_queue;
	int rx_int_enabled;
	int tx_packetlen;
	u8 *tx_packetdata;
	struct sk_buff *skb;
	spinlock_t lock;

};

struct snull
{
	struct net_device *snull_dev[2];
	struct my_private_info prvt;


};
