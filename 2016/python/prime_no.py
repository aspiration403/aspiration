#! /usr/bin/python
flag=0
for i in range(10,200):
 #print "Value of i ",i
 for j in range(2,i):
  flag = 0
 # print "Value of j",j
  if(i%j==0):
   flag=1
   break;
 if (flag ==0) :	
		print "Prime Number",i


	  



