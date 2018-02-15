LIB = -L/usr/lib64/mysql 
LIBNAME=-lmysqlclient
INCLUDE=-I/usr/include/mysql

Result:exampl1.o
	gcc -o example1	exampl1.o	$(LIB) $(LIBNAME)		
exampl1.o:exampl1.c
	gcc -c exampl1.c	$(INCLUDE)
