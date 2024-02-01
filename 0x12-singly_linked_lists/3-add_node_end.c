#include "lists.h"
#include <string.h>

/**
 * add_node_end - Add a new node at the end of a linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 * @str: The string to be stored in the new node.
 *
 * Return: NULL if memory allocation fails or if the string copy fails,
 *         otherwise, returns a pointer to the newly created node.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *last;

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = strlen(str);
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}

	return (new_node);
}
