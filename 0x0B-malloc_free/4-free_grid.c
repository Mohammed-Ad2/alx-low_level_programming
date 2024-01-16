#include <stdlib.h>

/**
 * free_grid - Frees the memory allocated for a two-dimensional
 *	       grid of integers.
 *
 * @grid: A pointer to the grid to be freed.
 * @height: The height of the grid.
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid != NULL && height != 0)
	{
		for (i = 0; i < height; i++)
			free(grid[i]);

		free(grid);
	}
}
