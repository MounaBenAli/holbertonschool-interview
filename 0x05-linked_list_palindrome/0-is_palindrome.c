#include "lists.h"


/**
* is_palindrome - checks if a listint_t singly linked list is a palindrome
* @head: a reference (pointer to pointer) to the head of the list listint_t
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/


int is_palindrome(listint_t **head)
{

	int stack[MAX], i, j, len;
	listint_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		return (1);
	}

	temp = *head;
	i = 0;
	while (temp != NULL)
	{
		stack[i] = temp->n;
		temp = temp->next;
		i++;
	}

	len = i - 1;
	for (j = 0; j < ((len + 1) / 2); j++)
	{
	if (stack[j] != stack[len    - j])
	return (0);
	}
	return (1);
}
