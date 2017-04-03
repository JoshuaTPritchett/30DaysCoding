from file_reader import FileReader
from os.path import exists


strings = ['Hello', 'goodbye', 'you_suck']
fr1 = FileReader(strings, 'test_file1.txt')
fr2 = FileReader([''], 'test_file2.txt')

def check_file_exists():
    return fr1.exists() and fr2.exists()

def print_information():
    print fr1.contents
    print fr1.cfile
    print fr2.cfile

'''
    Check the files existstance
'''
if check_file_exists():
    fr1.open()
    fr1.read()
    fr2.open()
    print_information()
    fr2.write(fr1.contents)
else:
    print 'One of the files were not found'
