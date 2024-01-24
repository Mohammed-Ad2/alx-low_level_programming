#include "function_pointers.h"

/**
 * print_name - Prints a name
 *
 * @name: Name to print
 * @f: function to callback
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
