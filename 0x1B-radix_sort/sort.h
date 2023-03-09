#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int find_max(int *arr, int n);
void countingSort(int *array, int n, int pos);

#endif /* _SORT_H_ */
