#ifndef __CLIENT_H__
#define __CLIENT_H__
int send_data(int fd[2], int num1, int num2, char operator);
int read_data(int fd[2]);
#endif
