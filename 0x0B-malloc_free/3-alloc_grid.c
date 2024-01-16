#include"main.h"
#include <stdlib.h>

/**
 * alloc_grid - Allocates a two-dimensional grid of integers
 *		with given width and height.
 *
 * @width: The width of the grid.
 * @height: The height of the grid.
 *
 * Return: A pointer to the newly allocated grid, or NULL if
 *	   width or height is 0 or if memory allocation fails.
 */
int **alloc_grid(int width, int height)
{
	int **ptr, i, j;

	if (width == 0 || height == 0)
		return (NULL);

	ptr = malloc(sizeof(int *) * height);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		ptr[i] = malloc(sizeof(int) * width);
		if (ptr[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(ptr[j]);

			free(ptr);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			ptr[i][j] = 0;

	return (ptr);
}
