#############################################################
#		MAKEFILE FOR static Libraric inclusion
##############################################################
LIBPATH = ../library/

library:	libmylib.so
libmylib.so:add.o	sub.o
	gcc -shared -o libmylib.so	add.o	sub.o
	mv	libmylib.so	$(LIBPATH)
			
add.o:	add.c	add.h	
	gcc -c -Wall	-Werror	-fpic	add.c
sub.o:	sub.c	sub.h
	gcc -c -Wall	-Werror	-fpic	sub.c
	
clean:	
	rm *.o
	rm $(LIBPATH)*.so	
	



