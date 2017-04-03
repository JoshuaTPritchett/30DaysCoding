'''
Simple file reader object that will teach
me how to properly read files
'''
#hmmm
import json
from os.path import exists
class FileReader(object):

    def __init__(self, strings, mfile):
        self.strings = strings
        self.mfile = mfile
        self.cfile = None

    def print_those_damn_strings(self):
        for s in self.strings:
            print s

    # must specify the w/r of content
    # w for only writing
    # r for only reading
    # b binary mode
    # rb, wb, r+b
    def open(self):
        self.cfile = open(self.mfile, 'r+')

    def truncate(self):
        self.cfile.truncate()

    def close(self):
        self.cfile.close()

    def read(self, read_num=0):
        if read_num:
            self.contents = self.read(read_num)
        else:
            self.contents = self.cfile.read()

    def readline():
        self.contents = self.cfile.readlines()

    def readlines():
        self.contents = self.cfile.readlines()

    def xreadlines():
        self.contents = self.cfile.xreadlines()

    def read_close(self):
        with open(self.mfile, 'r') as f:
            self.contents = f.read()

    def write(self, output):
        if output:
            self.cfile.write(output)
            self.cfile.write("\n")
        #for s in self.strings:
        #    self.cfile.write(s)
        #    self.cfile.write("\n")
    def seek_file(self, seek_num):
        self.cfile.seek(seek_num)

    def json_dump(self):
        json.dump(self.strings, self.cfile)

    def exists(self):
        return exists(self.mfile)
