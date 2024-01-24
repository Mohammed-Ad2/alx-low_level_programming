#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - Search for an integer
 * @array: The array to be searched.
 * @size: The number of elements in the array
 * @cmp: A pointer to the function to be used to compare values
 *
 * Return: i if a match is found, otherwise -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
		if (cmp(array[i]) != 0)
			return (i);

	return (-1);
}
