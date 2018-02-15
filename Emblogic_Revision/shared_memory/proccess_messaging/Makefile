SRC=./src/
ALL:server	client
server:server.o
			gcc -o server	server.o
			 
server.o:$(SRC)server.c	./header/common.h
		gcc -c $(SRC)server.c	-I./header/

client:client.o
			gcc -o client	client.o
			 
client.o:$(SRC)client.c	./header/common.h
		gcc -c $(SRC)client.c	-I./header/


