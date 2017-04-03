import math
import unittest
"""
        Bruh here is a fun test of basic python skills
"""
def convert_binary(num):
    test = []
    a = num
    while a > 0:
        test.insert(0,str(a%2))#little edian format
        a = a/(2)
    ret_value = ''.join(e for e in test) #create a string
    return ret_value


def convert_binary_decimal(str_num):
    a = 0
    twos_power = 0
    #convert back to big endian
    for s in str_num[::-1]:
        if s == '1':
            a = a + 2 ** twos_power
            twos_power = twos_power  + 1
    return a


def convert_binary_octal(str_num):
    octal_string = ''
    twos_power = 0
    tracking_num = 0
    for s in str_num[::-1]:
        if s == '1':
            tracking_num = tracking_num + (2 ** twos_power)
            twos_power = twos_power  + 1
            if twos_power % 3 == 0:
                octal_string  = str(tracking_num) + octal_string
                    twos_power = 0
                    tracking_num = 0
    if tracking_num != 0:
        octal_string  = str(tracking_num) + octal_string
    return octal_string

def convert_binary_hex():
    return

def built_in_binary(x):
    return bin(x)[2:]

print convert_binary(8)
print convert_binary_octal('100011')
print convert_binary_octal('0111')
print convert_binary_octal('1000')
print convert_binary_decimal('1000')


#Shit I suck lemme practice that slicing stuff....
"""
s = 'Don Quijote'
print s[4:8] # from 4-8
print s[4:] # to end of string
print s[:4] # 1-4
print s[:] #why? well because...
print s[:6] + s[6:] #this is trill but liek ....
print s[-3:-1]
print s[4:8:1] #from 4-8 skip by 1
print s[4:8:2] #from 4-8 skip by 2
print s[8:4:-1] # 8-4 going by 1
print s[4::-1] #from 4-1 going by -1 going backwards
print s[:4:-1] #end of string to 4 -1 going backwards
"""
#LETS PRACTICE HERP
#print s[len(s): -3:1]
#print s[0:1]
#print s[6:9]
#print s[len(s):-3:1]
#str_num = '01000'
#list_A = 	[str_num[i:i-3] for i in range(len(str_num) - 1, -1, -3)]
"""for i in range(len(str_num), 0, -n):
        if i - n > 0:
                print str_num[i-n:i]
        else:
                print str_num[i - (i % n): i]
"""
#GOT IT
