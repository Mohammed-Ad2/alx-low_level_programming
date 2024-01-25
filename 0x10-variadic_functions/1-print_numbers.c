#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - Print numbers
 *
 * @separator: The string to be printed between numbers
 * @n: The number of integers passed to the function
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, const unsigned int));
		if (separator != NULL && i != (n - 1))
		printf("%s", separator);
	}

	va_end(args);
	printf("\n");
}
