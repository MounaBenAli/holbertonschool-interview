#include "sort.h"

/**
 * swap_values - swap values
 *
 * @a: first element
 * @b: second element
 */
void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * build_heap - builds heap out of array
 * sift-down heap sort algorithm
 * @array: the array
 * @i: heap size
 * @j: root index
 * @size: Number of elements of the array
 */
void build_heap(int *array, int i, int j, size_t size)
{
	int max = j;
	int left_child = j * 2 + 1;
	int right_child = j * 2 + 2;

	if (left_child < i && array[left_child] > array[max])
		max = left_child;

	if (right_child < i && array[right_child] > array[max])
		max = right_child;

	if (max != j)
	{
		swap_values(&array[j], &array[max]);
		print_array(array, size);
		build_heap(array, i, max, size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: an unordered array
 * @size: Number of elements of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		build_heap(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap_values(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		build_heap(array, i, 0, size);
	}
}
