#include "sort.h"
/**
 * merge - function that merges two sub-arrays
 * @array: pointer to the original array
 * @start: index where the left sub-array starts
 * @middle: index where the division of the sub-arrays happens
 * @end: index where the right sub-array ends
 * @temp: pointer to the temporary array used for merging
 *
 * Return: void
 */
void merge(int *array, int start, int middle, int end, int *temp)
{
	int left_array_size, right_array_size;
	int i, j, k;

	left_array_size = middle - start + 1;
	right_array_size = end - middle;

	for (i = 0; i < left_array_size; i++)
		temp[i] = array[start + i];
	for (j = 0; j < right_array_size; j++)
		temp[left_array_size + j] = array[middle + 1 + j];

	i = j = 0;
	k = start;
	while (i < left_array_size && j < right_array_size)
	{
	if (temp[i] <= temp[left_array_size + j])
		array[k++] = temp[i++];
	else
		array[k++] = temp[left_array_size + j++];
	}

	while (i < left_array_size)
		array[k++] = temp[i++];

	while (j < right_array_size)
		array[k++] = temp[left_array_size + j++];
	}

/**
 * merge_sort_recursive - function that sorts and merges sub-arrays
 * @array: pointer to the original array
 * @start_idx: index where the sub-array starts
 * @end_idx: index where the sub-array ends
 * @tmp: pointer to the temporary array used for merging
 *
 * Return: void
 */
void merge_sort_recursive(int *array, int start_idx, int end_idx, int *tmp)
{
	int middle_index;

	if (start_idx < end_idx)
	{
	middle_index = start_idx + (end_idx - start_idx) / 2;
	merge_sort_recursive(array, start_idx, middle_index, tmp);
	merge_sort_recursive(array, middle_index + 1, end_idx, tmp);
	merge(array, start_idx, middle_index, end_idx, tmp);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start_idx, middle_index - start_idx + 1);
	printf("[right]: ");
	print_array(array + middle_index + 1, end_idx - middle_index);
	printf("[Done]: ");
	print_array(array + start_idx, end_idx - start_idx + 1);
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
	int *temp_array;

	if (!array || size == 1)
		return;

	temp_array = malloc(size * sizeof(int));
	if (!temp_array)
		return;

	merge_sort_recursive(array, 0, size - 1, temp_array);
	free(temp_array);
}
