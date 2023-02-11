#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge(int *array, int start, int middle, int end, int *temp);
void merge_sort_recursive(int *array, int start_idx, int end_idx, int *tmp);
void merge_sort(int *array, int size);

#endif /* SORT_H */
