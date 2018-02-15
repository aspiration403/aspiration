#############################################################
#		MAKEFILE FOR static Libraric inclusion
##############################################################

Result:main.o
	gcc -o Result	main.o	-L./library/	-lmylib

main.o:main.c	
	gcc -c main.c	-I./libfunction/

#library:	libmylib.a
#		ranlib libmylib.a
#libmylib.a:add.o	sub.o
#	ar -qcv	libmylib.a	add.o	sub.o
			
#add.o:	add.c	add.h	
#	gcc -c add.c
#sub.o:	sub.c	sub.h
#	gcc -c sub.c
	
clean:
	rm Result
	rm *.o
	



