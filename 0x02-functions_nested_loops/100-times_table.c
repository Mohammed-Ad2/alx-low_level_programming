#include "main.h"

/**
 * print_times_table - Prints the times table of the input,
 *		       starting with 0.
 *
 * @n: The value of the times table to be printed.
*/
void print_times_table(int n)
{
	if (n > 15 || n < 0)
	{
	}
	else
	{
		int i, j, p = 0;

		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				p = i * j;
				if (p > 0 && p <= 9 || j == 0)
					_putchar(p + '0');
				if (p > 9 && p < 100)
				{
					_putchar(p / 10 + '0');
					_putchar(p % 10 + '0');
				}
				if (p >= 100)
				{
					_putchar(p / 100 + '0');
					_putchar((p / 10 % 10) + '0');
					_putchar(p % 10 + '0');
				}
				if (j != n)
				{
					_putchar(',');
					_putchar(' ');
				}
			}
			_putchar('\n');
		}
	}
}
