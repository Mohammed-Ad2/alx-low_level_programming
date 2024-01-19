#include "main.h"

/**
 * puts_half - Prints half of a string
 *	       if len is odd, n = (len - 1) / 2
 * @str: input
 */
void puts_half(char *str)
{
	int i, len = 0, n;

	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		n = len / 2;

	else
		n = ((len + 1) / 2);

	for (i = n; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}
