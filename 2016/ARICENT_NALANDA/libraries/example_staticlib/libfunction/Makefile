#############################################################
#		MAKEFILE FOR static Libraric inclusion
##############################################################
LIBPATH = ../library/

library:	libmylib.a
libmylib.a:add.o	sub.o
	ar -qcv	libmylib.a	add.o	sub.o
	ranlib libmylib.a
	mv	libmylib.a	$(LIBPATH)
			
add.o:	add.c	add.h	
	gcc -c add.c
sub.o:	sub.c	sub.h
	gcc -c sub.c
	
clean:	
	rm *.o
	rm $(LIBPATH)*.a	
	



