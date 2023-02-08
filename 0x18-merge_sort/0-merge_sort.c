#include "sort.h"

/**
 * merge - function that merges two sub-arrays
 * @array: pointer to the original array
 * @start_index: index where the left sub-array starts
 * @middle_index: index where the division of the sub-arrays happens
 * @end_index: index where the right sub-array ends
 *
 * Return: void
 */
void merge(int *array, int start_index, int middle_index, int end_index)
{
	int left_array_size, right_array_size;
	int *left_array, *right_array;
	int i, j, k;

	left_array_size = middle_index - start_index + 1;
	right_array_size = end_index - middle_index;
	left_array = malloc(left_array_size * sizeof(int));
	if (!left_array)
		return;

	right_array = malloc(right_array_size * sizeof(int));
	if (!right_array)
	{
	free(left_array);
	return;
	}

	for (i = 0; i < left_array_size; i++)
		left_array[i] = array[start_index + i];
	for (j = 0; j < right_array_size; j++)
		right_array[j] = array[middle_index + 1 + j];

	i = j = 0;
	k = start_index;
	while (i < left_array_size && j < right_array_size)
	{
	if (left_array[i] <= right_array[j])
		array[k++] = left_array[i++];
	else
		array[k++] = right_array[j++];
	}

	while (i < left_array_size)
		array[k++] = left_array[i++];

	while (j < right_array_size)
		array[k++] = right_array[j++];

	free(left_array);
	free(right_array);
}


/**
 * merge_sort_recursive - function that sorts and merges sub-arrays
 * @array: pointer to the original array
 * @start_index: index where the sub-array starts
 * @end_index: index where the sub-array ends
 *
 * Return: void
 */
void merge_sort_recursive(int *array, int start_index, int end_index)
{
int middle_index;

	if (start_index < end_index)
	{
	middle_index = start_index + (end_index - start_index) / 2;
	merge_sort_recursive(array, start_index, middle_index);
	merge_sort_recursive(array, middle_index + 1, end_index);
	merge(array, start_index, middle_index, end_index);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start_index, middle_index - start_index);
	printf("[right]: ");
	print_array(array + middle_index, end_index - middle_index);
	printf("[Done]: ");
	print_array(array + start_index, end_index - start_index);
}
}

/**
 * merge_sort - function that sorts an array using the merge sort algorithm
 * @array: pointer to the original array
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, int size)
{
	if (!array || size == 1)
		return;
	merge_sort_recursive(array, 0, size - 1);
}
