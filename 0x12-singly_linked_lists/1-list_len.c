#include "lists.h"

/**
 * list_len - Count the number of elements in a linked list
 * @h: A pointer to the head of the linked list
 *
 * Return: The number of elements in the linked list
 */
size_t list_len(const list_t *h)
{
	int count = 0;
	const list_t *curr = h;

	while (curr != NULL)
	{
		count++;
		curr = curr->next;
	}

	return (count);
}
