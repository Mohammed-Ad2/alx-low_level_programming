#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The times table to print (up to 15).
 */
void print_times_table(int n)
{
	int i, j, prod;

	if (n >= 0 && n < 15)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				prod = i * j;
				if (prod > 99)
				{
					_putchar(',');
					_putchar(32);
					_putchar((prod / 100) + '0');
					_putchar(((prod / 10) % 10) + '0');
					_putchar((prod % 10) + '0');
				}
				else if (prod > 9)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
					_putchar(((prod / 10) % 10) + '0');
					_putchar((prod % 10) + '0');
				}
				else
				{
					if (j != 0)
					{
						_putchar(',');
						_putchar(' ');
						_putchar(' ');
						_putchar(' ');
					}
					_putchar(prod + '0');
				}
			}
			_putchar('\n');
		}
	}
}
