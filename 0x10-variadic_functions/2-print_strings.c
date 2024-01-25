#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - Print strings
 *
 * @separator: The string to be printed between the strings
 * @n: The number of strings passed to the function
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list str;
	char *current_str;

	va_start(str, n);

	for (i = 0; i < n; i++)
	{
		current_str = va_arg(str, char *);

		if (current_str == NULL)
			printf("(nil)");
		else
			printf("%s", current_str);

		if (separator != NULL && i != (n - 1))
			printf("%s", separator);
	}

	va_end(str);

	printf("\n");
}
