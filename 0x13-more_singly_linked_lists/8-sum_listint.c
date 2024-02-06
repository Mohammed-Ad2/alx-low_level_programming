#include <stddef.h>
#include "lists.h"

/**
 * sum_listint - returns the sum of all the data(n) of a listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: The sum of all the data (n) of the list, or 0 if the list is empty
 */
int sum_listint(listint_t *head)
{
	listint_t *temp = head;
	int data = 0;

	if (head == NULL)
		return (0);

	while (temp != NULL)
	{
		data += temp->n;
		temp = temp->next;
	}

	return (data);
}
