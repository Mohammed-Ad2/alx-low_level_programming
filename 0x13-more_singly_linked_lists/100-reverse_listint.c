#include <stddef.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list
 * @head: A pointer to a pointer to the head node of the list
 *
 * Return: A pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *curr = *head, *next;

	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;
	return (*head);
}
