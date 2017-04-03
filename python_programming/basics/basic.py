from sys import argv
from sys import exit
#Like a module however import class
from file_reader import FileReader
from mylist import MyList
#module import
import module
'''
print "Hello World"
print 3
print 12/7
print 12.0/7 #will result in an integer
print float(12) / 7 #lets cast that shit to float
print 3 + (2*4) #order of operations sure
#_ #stores last value?
#_ * 3 #what is this wizardry..
a, b = 1, 2
print(a)
print(b)
'''

'''
#god lets goo
print """
    Yo how tall are you:
"""
age = raw_input()
print age
'''

#input seems too easy...
#script, first, second, third = argv
#print "you entered 1:%s 2:%s 3:%s"% (first, second, third)
#print "you entered 1: 2: 3:", first, second, third
'''
script, user_name = argv
print "Hello ", user_name

prompt = '> '
print "What's your name? "
name = raw_input(prompt)
print "Age? "
age = raw_input(prompt)
print "Computer Type? "
computer_type = raw_input(prompt)

print """
    Hello bruh, your name %s
    Your Age %s
    Your Computer %s
""" % (name,age,computer_type)
'''
'''module.print_test()
print module.test_string
#My first object
fr = FileReader(strings, "test_file.txt")
fr.read()
print fr.test
print fr.cfile
fr.print_those_damn_strings()'''
'''
strings =["String 1","String 2","String 3"]
fr = FileReader(strings, 'test_file.txt')
print fr.mfile
fr.open() # open the file
fr.read() # read the file
print fr.contents
print fr.cfile
fr.truncate() #truncate the file
fr.json_dump()
'''

'''fr.read() # read the new file information
print fr.contents
fr.write()
fr.read()
print fr.contents
fr.close()'''
'''
# well this is fancy packing stuff
# even for arugments?
def what(*arguments):
    a, b = arguments
    return a, b

a, b = what(1, 2)
print a
print b
a, b = what("string 1", "string 2")
print a
print b

