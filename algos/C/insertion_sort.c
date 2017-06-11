/*
 * First algorithm invovles the sorting problem
 * Assume we have:
 *  Input: A sequence of n numbers (a1,a2,...,an)
 *  Output: A permutation (reordering) (a'1, a'2, ..., a'n) of the input sequence
 *          such that a'1 <= a'2 <= ... <= a'n
 *
 * The numbers we want to sort are the __keys__
 *
 * This example will focus on insertion sort
 *  *Efficient algorithm for sorting a small number of elements
 *
 * Example:
 *  Imagine you have a deck of cards
 *  We want to sort these cards
 *
 *  Start with an empty left hand and all cards __face down__ on table
 *
 *  We then remove one card at a time from the table and insert it into the correct position in the hand
 *
 *  In order to find the correct position we must compare it with each of the cards
 *  that already exist within the hand
 *
 *  The cards held in the left hand are sorted and these cards were originally the top
 *  cards of the pile on the table
 *
 *  This algorithm will sort __ IN PLACE __
 *
 *  IT will sort the numbers in the array with at most a constant number of them outside
 *  of the array
 *
 *
 */

#include <stdio.h>

void insertion_sort(int a[], int length);
void decreasing_insertion_sort(int a[], int length);
size_t linear_search(int a[], int key, int length);


int
main(int argc, char *argv[]) {
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    insertion_sort(a, 10);
    size_t i;
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    decreasing_insertion_sort(a, 10);
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");

    size_t index = linear_search(a, 1, 10);
    printf("index of search key %lu\n", index);
    return 0;
}


void insertion_sort(int a[], int length) {
    int j, i;
    int key;
    for (j = 1; j < length; j++) {
        key = a[j]; /* store the value to be swapped */
        i = j; /* Get all the indexes of the values that have already been sorted */
        /* Move through the left side array that is sorted and check against key */
        /* for every value less than swap the original value with the indexed value*/
        while (--i >= 0 && a[i] > key)
            a[i + 1] = a[i];

        a[i + 1] = key;
    }
}

void decreasing_insertion_sort(int a[], int length) {
    int i, j, key;
    /* Start at one to save us an interation */
    for (j = 1; j < length; j++) {
        key = a[j];
        i = j;
        while (--i >= 0 && a[i] < key)
            a[i + 1] = a[i];
        a[i + 1] = key;
    }
}

size_t linear_search(int a[], int key, int length) {
    size_t i;
    for (i = 0; i < length; i++)
        if (a[i] == key)
            return i;

    return -1;

}
