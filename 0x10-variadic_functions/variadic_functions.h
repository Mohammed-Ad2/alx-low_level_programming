#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * struct formatter - A new struct type defining a printer.
 * @spec: A symbol representing a data type.
 * @print: A function pointer that prints a data
 *         type corresponding to symbol.
 */
typedef struct formatter
{
	char spec;
	void (*print)(va_list *);
} fmt;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
