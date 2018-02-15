#############################################################
#		MAKEFILE FOR dynamic Libraries 		    #
##############################################################
#################### run using setting LD_LIBRARY PATH##############
LIB_NAME=addlib
LIB_FUNCTION = ./libfunction/
LIB_PATH=./library/

###########################compling our application ###############
###############1. Here to run this way we need to set the path 

Result:main.o
	gcc -o Result	main.o	-L$(LIB_PATH)	-l$(LIB_NAME)

main.o:main.c	$(LIB_FUNCTION)add.h	$(LIB_FUNCTION)sub.h
	gcc -c main.c	-I./libfunction/
###############################using  Path ####################





#################################MAKING LIBRARY#################

library:	lib$(LIB_NAME).so
		
lib$(LIB_NAME).so:$(LIB_FUNCTION)add.o	$(LIB_FUNCTION)sub.o
		gcc -shared -o lib$(LIB_NAME).so	$(LIB_FUNCTION)add.o	$(LIB_FUNCTION)sub.o 				
		mv	lib$(LIB_NAME).so		$(LIB_PATH)

add.o:	$(LIB_FUNCTION)add.c	$(LIB_FUNCTION)add.h	
	gcc -c -fpic	-Wall	$(LIB_FUNCTION)add.c
	mv	add.o	$(LIB_FUNCTION)

sub.o:	$(LIB_FUNCTION)sub.c	$(LIB_FUNCTION)sub.h	
	gcc -c -fpic	-Wall	$(LIB_FUNCTION)sub.c
	mv	sub.o	$(LIB_FUNCTION)

clean_lib:
	rm	$(LIB_PATH)*.so
	rm	$(LIB_FUNCTION)*.o
	
##########################################################################

clean:
	rm Result
	rm *.o

