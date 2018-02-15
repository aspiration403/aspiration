#! /usr/bin/python

str = "Hello Raman";

print str
print str[0]
print str[2 : 5]
print str[5 : ]

print str*2 + 'Panakj'


#list is compound data type

infolist = ['Raman' ,21,9069301069,77.8]

print infolist
print infolist[0]
print infolist[1:3]
print infolist[3]


##tuples :similar to read only list

tuple = ("Raman",1234,"Nice to meet u",20.5)
print tuple
print tuple[2:]
#tuple[1] = 3456 #invalid synax :tuple is read only can't change the value
infolist[1] = 25 #valid with listi
print infolist



#Dictionary is data types similar to hash

dict = {}
dict['one']="This is one"
dict[2]="This is two"

print dict
print dict.keys()
print dict.values()


raman_dict = {'Name':'Raman' ,'Age':21, 'Mobile_No. ':9069}

print raman_dict.keys()
print raman_dict['Name']


