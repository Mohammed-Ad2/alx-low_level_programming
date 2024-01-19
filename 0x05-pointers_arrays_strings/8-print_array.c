#include "main.h"
#include <stdio.h>

/**
 * print_array - Prints n element of an array of integers
 *
 * @a: input
 * @n: Number of elements to be printed
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i != (n - 1))
			printf(", ");
		else
			printf("\n");
	}
}
