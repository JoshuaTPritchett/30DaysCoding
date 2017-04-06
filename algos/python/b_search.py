"""
    All I had time for today was some binary seaerch review
    Tomorrow is another day!
"""


def b_search_recursion(ar, low, high, key):
    #basic implementation of middle point
    #mid = low + high/2
    #can lead to arithmetic overflow for large arrays
    #then value of L+R may exceed range
    mid = low + (high-low) / 2; #takes the floor
    if low > high:
        return -1
    if ar[mid] == key:
        return ar[mid]
    if ar[mid] < key:
        #make sure to return recursive value
        return b_search_recursion(ar, mid + 1, high, key)
    if ar[mid] > key:
        return b_search_recursion(ar, low, mid - 1, key)

def b_search_non_recur(ar, low, high, key):
    l = low
    h = high - 1
    while l <= h:
        mid = l + (h - l) / 2
        if ar[mid] == key:
            return ar[mid]
        if ar[mid] < key:
            l = mid + 1
        if ar[mid] > key:
            h = mid - 1

    return -1


# Well what if we want to search an unbounded list? How would
# we achieve this goal?
# perform exponential search
# this will perform log(i) where i = position of search key in list
def expo_search(ar, ar_size, key):
    if ar_size == 0:
        return -1

    #Yo maybe we will get lucky
    if ar[start_bound] == key:
        return ar[start_bound]

    start_bound = 1
    #Must set to one as we are taking an exponent of 2^i
    # Lul the wikipedia page is wrong!
    while start_bound < ar_size and ar[start_bound] <= key:
        start_bound *= 2

    #perform binary search
    return b_search_non_recur(ar, start_bound/2, min(start_bound, ar_size), key)




a = [1,2,3,4,5,6,7]

b = b_search_recursion(a, 0, len(a) - 1, 7)
print "recursive Value", b

b = b_search_non_recur(a, 0, len(a), 7)
print "non Value", b

b = expo_search(a, len(a), 1)
print "expo search value", b
