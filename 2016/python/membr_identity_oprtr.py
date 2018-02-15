#!/usr/bin/python


##membership oprator : in,not in
a = 50
b='Raman'

list = [10,25,"Raman","o my god",30];

if ( a in list ):

	print "a is  in array list"
else:
	print "a is not in arr_list"

if (b not in list):
	print "b is not in list"
else:
	print "b is in list"

##identity operator : is,is not

c=30

if(a is c):
	print "value of a and c is equal",a;
else:
	print 'a is not c'
d =30
if(id(c) == id(d)):
	print "c is d"
if(c is d):
	print "value of c,d is :",c 
