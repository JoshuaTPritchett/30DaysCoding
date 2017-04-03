import random
class MyList(object):

    def __init__(self):
        self.mylist = []


    def fill_list(self):
        for i in xrange(60):
            self.mylist.append(random.randint(1,1000))

    def empty_list(self):
        #empties memory location
        # self.mylist = [] will repoint the pointer
        # to a new list in memory
        self.mylist[:] = []

    def append(self, value):
        self.mylist.append(value)

    def append_position(self, position, value):
        self.mylist.insert(position, value)
