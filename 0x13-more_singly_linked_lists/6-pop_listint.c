#include <stddef.h>
#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list
 * @head: A pointer to a pointer to the head node of the list
 *
 * Return: The data (n) of the head node that was deleted,
 *	   0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int popped_value = 0;

	if (*head == NULL)
		return (0);

	temp = *head;
	*head = (*head)->next;
	popped_value = temp->n;
	free(temp);

	return (popped_value);
}
