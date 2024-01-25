#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * sum_them_all - Calculates the sum of a variable number of unsigned integers.
 * @n: The number of unsigned integers to sum.
 * @...: The unsigned integers to sum.
 *
 * Return: The sum of the provided unsigned integers.
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i, sum = 0;
	va_list args;

	if (n == 0)
		return (0);

	va_start(args, n);

	for (i = 0; i < n; i++)
		sum += va_arg(args, const unsigned int);

	va_end(args);

	return (sum);
}
