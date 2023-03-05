#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a circular doubly linked list.
 * @list: A pointer to the head of the list.
 * @str: The string to be stored in the new node.
 *
 * Return: If successful - a pointer to the new node, otherwise - NULL.
 */
List *add_node_end(List **list, char *str)
{
	List *new, *head;

	new = duplicate_node(str);
	if (new == NULL)
		return (NULL);

	if (*list == NULL)
	{
		*list = new;
		new->prev = new;
		new->next = new;
	}
	else
	{
		head = (*list)->prev;
		while (head->next != *list)
		head = head->next;

		head->next = new;
		new->prev = head;
		new->next = *list;
		(*list)->prev = new;
	}
	return (new);
}

/**
 * add_node_begin - Adds a new node to the beginning of a circular doubly
 *                  linked list.
 * @list: A pointer to the head of the list.
 * @str: The string to be stored in the new node.
 *
 * Return: If successful - a pointer to the new node, otherwise - NULL.
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *head;

	new = duplicate_node(str);
	if (new == NULL)
		return (NULL);

	if (*list == NULL)
	{
		*list = new;
		new->prev = new;
		new->next = new;
	}
	else
	{
		head = (*list)->prev;
		head->next = new;
		new->prev = head;
		new->next = *list;
		(*list)->prev = new;
		*list = new;
	}
	return (new);
}

/**
 * duplicate_node - Creates a new node containing a copy of a string.
 * @str: The string to be copied into the new node.
 *
 * Return: If successful - a pointer to the new node, otherwise - NULL.
 */
List *duplicate_node(char *str)
{
	List *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	/* Duplicate the string */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Initialize the prev and next pointers */
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}
