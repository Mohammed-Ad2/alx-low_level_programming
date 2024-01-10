#include "main.h"
/**
 * more_numbers - Prints the numbers 0 to 14 ten times, followed by a new line.
 *
 * Description: This function prints the numbers 0 to 14 in a loop,
 * repeating the sequence ten times. Each set of numbers is followed
 * by a new line.
 */
void more_numbers(void);

{
	int i, j;

	for (i = 1; i <= 10; i++)
	{
		for (j = 0; j <= 14; j++)
			if (j >= 10)
				_putchar('1');

		_putchar (j % 10 + '0');
		_putchar('\n');
	}
}
