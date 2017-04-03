try:
    from mylist import Mylist
except ImportError as lerr:
    print lerr
    Mylist = None
try:
    from exceptions import MyListError
except ImportError as merr:
    print merr
    MyListError = None
from sys import exit
from mylist import MyList
def end(reason):
    print reason, "Exiting.."
    exit(0)
def start():
    try:
        mlist = MyList()
        mlist.fill_list()

        for value in mlist.mylist:
            print value

        mlist.mylist.append(60)
        if 60 in mlist.mylist:
            end("This is over!")
    except MyListError as lerr:
        print lerr
#:HMM
start()
