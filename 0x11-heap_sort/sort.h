#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Helpers*/
void print_array(const int *array, size_t size);
void swap_values(int *a, int *b);

/*Heap Sort*/
void heap_sort(int *array, size_t size);

#endif /* _HEAP_SORT_H_ */