#include "main.h"

/**
 * print_rev - imprime en reversa
 * @s: string
 * return: 0
 */
void print_rev(char *s)
{
	int i, lenght = 0;

	while (*s != '\0')
	{
		lenght++;
		s++;
	}

	s--;

	for (i = lenght; i > 0; i--)
	{
		_putchar(*s);
		s--;
	}

	_putchar('\n');
}

