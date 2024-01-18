#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: The size in bytes for the new memory block.
 *
 * Return:
 *   - If new_size equals old_size, return ptr.
 *   - If new_size is 0 and ptr is not NULL, return NULL.
 *   - Otherwise, return a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *nptr;

	if (old_size == new_size)
		return (ptr);

	if (ptr == NULL)
	{
		nptr = malloc(new_size);
		return (nptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	nptr = malloc(new_size);
	if (nptr == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		nptr[i] = ((char *)ptr)[i];

	free(ptr);

	return (nptr);
}
