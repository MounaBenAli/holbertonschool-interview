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

	if (array == NULL || size == 0)
		return (-1);

	return (findFirstOccurnce(array, size, value));
}

/**
 * findFirstOccurnce - Binary search for finding the first occurence
 * @A :  the array to search in
 * @n : size of array
 * @target :  the target element to be found
 *
 * Return:  the first index where value is located or if no value -1
 */
int findFirstOccurnce(int A[], int n, int target)
{
	int low = 0, high = n - 1;
	int mid;

	if (!A || high < low)
		return (-1);

	while (low <= high)
	{
		_printSearch(A, low, high);
		mid = low + (high - low) / 2;
	if ((mid == 0 || A[mid - 1] < target) && A[mid] == target)
		return (mid);
	else if (target > A[mid])
		low = mid + 1;
	else
		high = mid - 1;
	}
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
