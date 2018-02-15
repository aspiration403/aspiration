#! /usr/bin/python

name="raMan what aRe you doing   wow !!!"
print r'c:\\nowhere'

print u"Hello World !"

print name.capitalize()
print len(name)
print name.upper()
print name.lower()
print name

sub= 'a';
print "substring count :",name.count( sub, 5, 40)
print "Sub string count :",name.count('a')

## string encoding and decoding str.encode(encoding='UTF-8',errors='strict')

name=name.encode('base64','strict')
print "Encoded string :",name

name=name.decode('base64','strict')
print "Decoded string :",name 

##endswith str.endswith(suffix,beg,end=len(str))

suffix="!!!"
print name.endswith(suffix,0,len(name))


