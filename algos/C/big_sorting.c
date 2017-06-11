nclude <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

int simple_strcmp(char *s1, char *s2);
size_t get_size(char line[]);
void insertion_sort(char *a[], size_t);
void print_elements(char *a[], size_t);


int main(){
        size_t elements, i;
            scanf("%lu", &elements);

                 /*
                  *       * If we are parsing larger than 100 considering 10^6
                  *             * we are fucked... considering 10 ^ 6 = 1000000 ()
                  *                   */
                char line[10000000];
                    char *arr[elements];
                        size_t b;
                            for (i = 0; i <= elements; i++) {
                                        scanf("%s", line);
                                                b = get_size(line);
                                                        *(arr + i) = malloc(sizeof(char) * b);
                                                                strncpy(*(arr + i), line, b);
                                                                    }
                                insertion_sort(arr, elements);
                                    print_elements(arr, elements);
                                        return 0;
}

size_t get_size(char line[]) {
        char *s = &line[0];
            size_t b = 0;
                while (*s++)
                            b++;
                    return b;
}

int simple_strcmp(char *s1, char *s2) {
        size_t l1 = get_size(s1);
            size_t l2 = get_size(s2);
                if (l1 > l2)
                            return 1;
                    if (l2  > l1)
                                return -1;

                        return strcmp(s1, s2);
}
/* Just refreshed on IS gonna use it, will upgrade as needed
 * *   Only use size_t for number of bytes... idiot..
 * */
void insertion_sort(char *a[], size_t length) {
        int j, i;
            char *key;
                for (j = 0; j < length; j++) {
                            key = a[j];
                                    i = j;
                                           // printf("%lu I:\n", i);
                                           //         while (--i >= 0 && simple_strcmp(key, a[i]) < 0)
                                           //                      a[i + 1] = a[i];
                                           //                              /* Swap the final element and the key each iteration*/
                                           //                                      a[i + 1] = key;
                                           //                                          }
                                           //                                          }
                                           //
                                           //                                          void print_elements(char *a[], size_t length) {
                                           //                                              size_t i;
                                           //                                                  for (i = 0; i < length; i++)
                                           //                                                          printf("%s\n", a[i]);
                                           //                                                          }
                                           //
                                           //
