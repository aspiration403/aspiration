#ifndef __HEADER__
#define __HEADER__
#define BUFSIZE 255
#define ERROR_NO 0
#define ERROR_FAIL -1


typedef int error_t;
 
struct shared_memory
{
  char buffer[BUFSIZE];
  pid_t pid;
} ;    


union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                              (Linux-specific) */
           };
#endif
