#include <time.h>
#include <stdio.h>
#define ARR_SIZE 65535

void check_binsearch(int arr[]);
int binsearch_2(int x, int v[], int n);
int binsearch_1(int x, int v[], int n);

int main(int arg, char **argv) {

    int arr[ARR_SIZE];
    unsigned int i;

    /* init functions */
    for(i = 0; i < ARR_SIZE; ++i)
        arr[i] = i;

    check_binsearch(arr);

    return 0;
}


/*
 * Calculates the CPU time used for binary search in both cases
 * @param int[] array of integers with values
 *
 */
void check_binsearch(int arr[]) {
    clock_t start = clock();
    clock_t end = 0;

    int val = binsearch_1 (65000, arr, ARR_SIZE);
    end = clock();

    double time_spent = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Time spent 1: %f\r\n", time_spent);

    if (val != -1)
        printf("found %d: \r\n", val);

    start = clock();
    val = binsearch_2(65000, arr, ARR_SIZE);
    end = clock();
    time_spent = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Time spent 1: %f\r\n", time_spent);

    if (val != -1)
        printf("found %d: \r\n", val);

}


int binsearch_2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid =  (low + high) / 2;
        if (x > v[mid])
            low = mid + 1;
        else
            break;
    }
    if (x == v[mid])
        return mid;

    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high  = mid - 1;
        else
            break;
    }

    if (x == v[mid])
        return mid;

    return -1;
}

/*
 * Determines if a given element @param x exists within
 * a given array; returns the position if found
 *
 * @param int element to be found
 * @param int[] array of elements that contain values
 * @param int n the bounds of the array
 *
 * @return int position(mid) of element found in array
 *
 */
int binsearch_1(int x, int v[], int n) {
    int mid, low, high;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) /2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }

    return -1; /* no match */
}
