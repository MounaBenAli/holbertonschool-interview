#include "sort.h"

/**
* find_max - Find the maximum element in an integer array
* @arr: Array of integers
* @n: Number of elements in the array
* Return: Maximum element in the array
*/
int find_max(int *arr, int n)
{
	int max_element = arr[0];
	int i;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > max_element)
		{
			max_element = arr[i];
		}
	}
	return (max_element);
}

/**
* countingSort - Sort an integer array using the counting sort algorithm
* @array: Array of integers to be sorted
* @n: Number of elements in the array
* @pos: Position of the digit to be sorted
* Return: None
*/
void countingSort(int *array, int n, int pos)
{
	int *result = malloc(sizeof(int) * (n + 1));
	int count[10] = {0};
	int i;


	for (i = 0; i < n; i++)
		count[(array[i] / pos) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];


	for (i = n - 1; i >= 0; i--)
	{
		result[count[(array[i] / pos) % 10] - 1] = array[i];
		count[(array[i] / pos) % 10]--;
	}

	for (i = 0; i < n; i++)
		array[i] = result[i];

	free(result);
}


/**
* radix_sort - Sort an integer array using the radix sort algorithm
* @array: Array of integers to be sorted
* @size: Number of elements in the array
* Return: None
*/

void radix_sort(int *array, size_t size)
{

	int max_element = find_max(array, size);
	int pos;

	for (pos = 1; max_element / pos > 0; pos *= 10)
	{
		countingSort(array, size, pos);
		print_array(array, size);
	}
}
