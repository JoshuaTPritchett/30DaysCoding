#include <stdio.h>

void qsort(int a[], int start, int end);
void swap(int a[], int s, int e);
void print_array(int a[]);

int
main (int main, char *argv[]) {
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    qsort(a, 0, 10);
    return 0;
}

void qsort(int a[], int start, int end) {
    int i, last;

    if (start >= end)
        return;

    swap(a, start, (start + end) / 2);
    last = start;
    for (i = last + 1; i <= end; i++)
        if (a[i] < a[start]) {
            printf("These values are less than: %d, %d\r\n", a[i], a[start]);
            printf("i value: %d, l value: %d\r\n", i, last);
            print_array(a);
            swap(a, ++last, i);
    }
    swap(a, start, last);
    puts("pass complete");
    print_array(a);
    qsort(a, start, last - 1);
    qsort(a, last + 1, end);

}

void swap(int a[], int s, int e) {
    int val;
    val = a[s];
    a[s] = a[e];
    a[e] = val;
}

void print_array(int a[]) {
    unsigned int i;
    printf("array values: ");
    for (i = 0; i < 11; i++)
        printf("%d ", a[i]);
    printf("\n");
}
