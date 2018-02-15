#ifndef HEADER
#define HEADER
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <errno.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <unistd.h>
	#include <fcntl.h>
	
	#define SUCCESS 0
	#define FAILURE -1
	#define BUFFER_SIZE 255
	
	int write_data(int, char*);
	int read_data(int, char*);

#endif
