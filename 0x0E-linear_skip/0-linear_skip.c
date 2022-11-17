#include "search.h"
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list:  Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer on the first node where value is located
 * if not located or if head in NULL return NULL
 *
 * Description: Skip Lists: A Probabilistic Alternative to Balanced Trees
 * It is a simple associative data structure.
 * That is, it maps keys to values, in very much the same way
 * as a hash table/dictionary/HashMap/map from other programming language.
 *  Requires only Θ(logn) time in the average case for all operations.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skip = list->express;
	skiplist_t *x = list;

	if (list == NULL)
		return (NULL);


	while (skip)
	{
		printf("Value checked at index [%lu] = [%d]\n", skip->index, skip->n);
		if (skip->n >= value)
			break;

		x = skip;
		if (skip->express == NULL)
		{
			while (skip)
				skip = skip->next;
			break;
		}
		skip = skip->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
		   x->index, skip->index);
	while (x && x->index <= skip->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", x->index, x->n);
		if (x->n == value)
			return (x);
		x = x->next;
	}
	return (NULL);
}
