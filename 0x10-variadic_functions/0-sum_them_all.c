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
	unsigned int i, sum;

	va_list args;

	va_start(args, n);

	sum = n;
	for (i = 0; i < n; i++)
		sum += va_arg(args, const unsigned int);

	va_end(args);
	return (sum);
}
