#include "main.h"

/**
 * array_range - Creates an array of integers.
 * @min: The minimum value.
 * @max: The maximum value.
 *
 * Return: A pointer to the newly created array, or
 *	   NULL if min > max or if memory allocation fails.
 */
int *array_range(int min, int max)
{
	int *str, i;

	if (min > max)
		return (NULL);

	str = malloc(sizeof(int) * (max - min + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; i <= (max - min); i++)
		str[i] = min + i;

	return (str);
}
