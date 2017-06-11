a = [10,3,5,30,35]

def maxPairProduct(a):
    q = z = max_val = -1
    for i in a:
        if q == -1 and z == -1:
            q = i
        if q != -1 and z == -1:
            z = i
        if z * q == max_val:

        print q

if __name__ == '__main__':
    maxPairProduct(a)
