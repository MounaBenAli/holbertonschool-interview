#include "search_algos.h"


/**
 * advanced_binary - searches for a value in a sorted array of integers
 *
 * @array : pointer to the first element of the array to search in
 * @size :  number of elements in array
 * @value : value to search for
 *
 * Return: the index where value is located or -1
 */
int advanced_binary(int *array, size_t size, int value)
{

	int low = 0;
	int high = (int)size - 1;

	if (array == NULL || size == 0)
		return (-1);

	return (findFirstOccurnce(array, low, high, value));
}

/**
 * findFirstOccurnce - Binary search for finding the first occurence
 * @arr:  the array to search in
 * @low: first index of array
 * @high : last index of array
 * @value:  the target element to be found
 *
 * Return:  the first index where value is located or if no value -1
 */

int findFirstOccurnce(int *arr, int low, int high, int value)
{
	int mid;

	if (!arr || low == high)
		return (-1);

	_printSearch(arr, low, high);

	mid = low + (high - low) / 2;

	if (arr[mid] < value)
		return (findFirstOccurnce(arr, mid + 1, high, value));

	if (arr[mid] > value)
		return (findFirstOccurnce(arr, low, mid, value));

	if (arr[mid] == value && arr[mid - 1] != value)
		return (mid);

	if (arr[mid] == value && arr[mid - 1] == value)
		return (findFirstOccurnce(arr, low, mid, value));
	return (-1);
}



/**
 * _printSearch- printing the searched array
 * @array : a pointer to the first element of the array to search in
 * @start : index of beginning
 * @end : index of end
 *
 * Return:  nothing
 */
void _printSearch(int *array, int start, int end)
{
	int j;

	j = start;
	printf("Searching in array: ");

	while (j <= end)
	{
	if (j > start)
		printf(", ");
		printf("%d", array[j]);
		j++;
	}
	printf("\n");
}
