#include "main.h"

/**
 * rev_str - Reverse a string
 * @num: Pointer to the string to be reversed
*/
void rev_str(char *num)
{
	int i = 0, j = 0;
	char temp;

	while (num[i] != '\0')
		i++;
	i--;
	for (j = 0; j < i; j++, i--)
	{
		temp = num[j];
		num[j] = num[i];
		num[i] = temp;
	}
}

/**
 * infinite_add - Add two numbers represented as strings
 * @n1: Text representation of the first number to be added
 * @n2: Text representation of the second number to be added
 * @r: Pointer to the buffer to store the result
 * @size_r: Size of the buffer to store the result
 * Return: Pointer to the result stored in the buffer `r`, or
 *	   `0` if the result exceeds the buffer size.
*/
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, overflow = 0, digits = 0;
	int val1 = 0, val2 = 0, total_sum = 0;

	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;
	i--;
	j--;
	if (j >= size_r || i >= size_r)
		return (0);
	while (j >= 0 || i >= 0 || overflow == 1)
	{
		if (i < 0)
			val1 = 0;
		else
			val1 = n1[i] - '0';
		if (j < 0)
			val2 = 0;
		else
			val2 = n2[j] - '0';

		total_sum = val1 + val2 + overflow;

		if (total_sum >= 10)
			overflow = 1;
		else
			overflow = 0;
		if (digits >= (size_r - 1))
			return (0);
		r[digits] = (total_sum % 10) + '0';
		digits++;
		j--;
		i--;
	}
	if (digits == size_r)
		return (0);
	r[digits] = '\0';
	rev_str(r);
	return (r);
}
