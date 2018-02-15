
#define SCULL_MAGIC 'K'
#ifndef SCULL_RESET	
#define SCULL_RESET _IO(SCULL_MAGIC,0)
#endif

#ifndef SCULL_QUANTUM_OUT				//quantum size
#define SCULL_QUANTUM_OUT _IOR(SCULL_MAGIC,1,int)
#endif

#ifndef SCULL_QSET_SIZE
#define SCULL_QSET_SIZE _IOR(SCULL_MAGIC,2,int)
#endif

#ifndef SCULL_QUANTUM_SET
#define SCULL_QUANTUM_SET _IOW(SCULL_MAGIC,3,int)
#endif

#ifndef SCULL_QSETSIZE_SET
#define SCULL_QSETSIZE_SET _IOW(SCULL_MAGIC,4,int)
#endif

