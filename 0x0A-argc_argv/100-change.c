#include <stdio.h>
#include <stdlib.h>
/**
 * main - Main Entry
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Always 0 (success)
**/
int main(int argc, char *argv[])
{
	int cents = atoi(*(argv + 1)), coins = 0;

	if (argc == 2)
	{
		while (cents > 0)
		{
			if (cents % 25 < cents)
			{
				cents -= 25;
				coins++;
			}
			else if (cents % 10 < cents)
			{
				cents -= 10;
				coins++;
			}
			else if	(cents % 5 < cents)
			{
				cents -= 5;
				coins++;
			}
			else if	(cents % 2 < cents)
			{
				cents -= 2;
				coins++;
			}
			else if (cents % 1 < cents)
			{
				cents -= 1;
				coins++;
			}
		}
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", coins);
	return (0);
}
