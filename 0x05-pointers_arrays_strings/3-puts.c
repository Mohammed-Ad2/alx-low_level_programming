#include "main.h"

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: string to print
 */
void _puts(char *str)
{
	int i;

	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}

	_putchar('\n');
}
