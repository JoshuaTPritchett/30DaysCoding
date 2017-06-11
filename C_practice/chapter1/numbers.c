#include <stdio.h>
#include <stdlib.h>
#define KEY 9
#define ARRAY_SIZE 10

int binary_search(int[], int, int, int);
int galloping_search(int[], int, int);
int min(int, int);
void perform_b_search(int[], int, int);

int main() {
    int a[ARRAY_SIZE];
    int b[ARRAY_SIZE];
    int i;

    for(i = 0; i < ARRAY_SIZE; i++)
        a[i] = i + 1;
    perform_b_search(a, ARRAY_SIZE, 8);
    i = ARRAY_SIZE - 1;
    for(; i >= 0; i--)
        b[i] = i;
    perform_b_search(a, ARRAY_SIZE, 1);

    return 0;
}

void perform_b_search(int a[], int size, int key) {
    int ret_val = galloping_search(a, ARRAY_SIZE, 1);
    printf("%dRETURN VALUE\n", ret_val);
}
/**
 * Implemented to help with lists in which we do not know the size
 * @param int array a the array that holds the values
 * @param int size  size of the array we are dealing with
 * @param int key   search value we are looking for
 */
int galloping_search(int a[], int size, int key) {
    //Decalre the bound to one because we are going to do log2(i^1)
    //Need a start
    int bound = 1;

    //Get the size of a
    //int is 16 bits on most architectures 2^(value-1)-1
    //long int is 32
    //float is 32bits
    //double float is 64 bits
    if(a[bound] == key)
        return a[bound];

    //take the powers of two
    while(bound < size && a[bound] <= key)
        bound *= 2;

    //Perform binary search bound/2 for the lower part of the search bounds
    //take the min of the bound itself or the size of the array
    //why was (sizeof(a)/sizeof(a[0])
    int m = min(bound, size);
    return binary_search(a, bound/2, m, key);
}

int min(int a, int b) {
    return a < b ? a : b;
}

int binary_search(int a[], int low, int high, int key) {
    int l = low;
    int h = high - 1;
    while(l <= h) {
        int mid = l + (h-l) / 2;
        if(a[mid] == key)
            return a[mid];
        if(a[mid] < key)
            l = mid + 1;
        if(a[mid] > key)
            h = mid - 1;
    }
    return -1;
}
