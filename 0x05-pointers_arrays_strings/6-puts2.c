#include "main.h"

/**
 * puts2 - Print only one character out of two
 *	   starting with the first one
 * @str: input
 */
void puts2(char *str)
{
	int i, len = 0;

	while (str[len] != '\0')
		len++;

	for (i = 0; i < len; i++)
		if (i % 2 == 0)
			_putchar(str[i]);

	_putchar('\n');
}
