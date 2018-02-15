CC = gcc
CFLAGS = -c -g -Wall
OFLAGS = -o

ALL: server client

server: server.o functions.o
	$(CC) $(OFLAGS) server server.o functions.o

client: client.o functions.o
	$(CC) $(OFLAGS) client client.o functions.o

server.o: server.c 
	$(CC) $(CFLAGS) -I. server.c

client.o: client.c
	$(CC) $(CFLAGS) -I. client.c

functions.o: functions.c
	$(CC) $(CFLAGS) -I. functions.c


clean:
	rm client
	rm server
	rm *.o
