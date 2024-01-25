#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

void print_char(va_list *args);
void print_int(va_list *args);
void print_float(va_list *args);
void print_string(va_list *args);
void print_all(const char * const format, ...);

/**
 * print_char - Print a character.
 *
 * @args: A pointer to va_list containing the character
 *	  to be printed.
 */
void print_char(va_list *args)
{
	printf("%c", va_arg(*args, int));
}

/**
 * print_int - Print an integer.
 *
 * @args: A pointer to va_list containing the integer to be printed.
 */
void print_int(va_list *args)
{
	printf("%d", va_arg(*args, int));
}


/**
 * print_float - Print a floating-point number.
 *
 * @args: A pointer to va_list containing the floating-point
 *	  number to be printed.
 */
void print_float(va_list *args)
{
	printf("%f", va_arg(*args, double));
}

/**
 * print_string - Print a string.
 *
 * @args: A pointer to va_list containing the string to be printed.
 *        If the string is NULL, "(nil)" is printed instead.
 */
void print_string(va_list *args)
{
	char *spec = va_arg(*args, char *);

	if (spec == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", spec);
}

/**
 * print_all - Print values based on the format string provided.
 *
 * @format: The format string containing format specifiers.
 *          Each specifier corresponds to the type of the
 *	    following argument.
 *          Specifiers: 'c' - char, 'i' - integer, 'f' - float,
 *			's' - string.
 */
void print_all(const char * const format, ...)
{
	fmt f[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL},
	};

	int i = 0, j = 0;
	const char *separator = "";
	va_list args;

	va_start(args, format);

	while (format[i] != '\0')
	{
		j = 0;
		while (f[j].spec != '\0')
		{
			if (format[i] == f[j].spec)
			{
				printf("%s", separator);
				f[j].print(&args);
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
