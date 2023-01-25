#include "lists.h"

/**
 * find_listint_loop -  finds the loop/cycle in a linked list
 * @head: list to verify for cycle detection
 * Return: if there is no cycle NULL,
 * if there is a cycle the address of the entry point of the cycle
 * solution Floyd's cycle detection algorithm (Tortoise and Hare)
 * Tcomplexity O(n) Scomplexity O(1)
 */


listint_t *find_listint_loop(listint_t *head)
{

	listint_t *tortoise = head;
	listint_t *hare = head;

	if (!head)
		return (NULL);


	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
		{
			break;
		}
	}

	if (!hare || !hare->next)
	{
		return (NULL);
	}

	tortoise = head;
	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		hare = hare->next;
	}

	return (tortoise);
}
