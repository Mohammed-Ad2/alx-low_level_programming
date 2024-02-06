#include <stddef.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: A pointer to a pointer to the head node of the list
 * @idx: The index of the list where the new node should be added
 * @n: The data to be stored in the new node
 *
 * Return: The address of the new node, or NULL if it failed
 *         If the index is invalid or if memory allocation fails, return NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node, *temp;
	unsigned int i = 0;

	if (*head == NULL && idx != 0)
		return (NULL);

	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	node->n = n;

	if (idx == 0)
	{
		node->next = *head;
		*head = node;
		return (node);
	}

	temp = *head;
	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	if (temp == NULL)
	{
		free(node);
		return (NULL);
	}

	node->next = temp->next;
	temp->next = node;

	return (node);
}
