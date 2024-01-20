#include "main.h"
/**
 * reverse_array - Reverses the content of an array of integers.
 *
 * @a: The array to be reversed.
 * @n: The number of elements in the array.
 */
void reverse_array(int *a, int n)
{
	int i, temp;

	n--;
	for (i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = a[n];
		a[n] = temp;
		n--;
	}
}

