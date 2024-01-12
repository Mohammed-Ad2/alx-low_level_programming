#include <stdio.h>
#include <stdlib.h>

/**
 * count_coins - Count the minimum number of coins
 *		 needed to make change.
 * @cents: The amount in cents for which to calculate
 *	   the minimum coins.
 *
 * Return: The minimum number of coins needed.
 */
int count_coins(int cents)
{
	int coins = 0;

	while (cents > 0)
	{

		if (cents >= 25)
		{
			cents -= 25;
			coins++;
		}
		else if (cents >= 10)
		{
			cents -= 10;
			coins++;
		}
		else if (cents >= 5)
		{
			cents -= 5;
			coins++;
		}
		else if (cents >= 2)
		{
			cents -= 2;
			coins++;
		}
		else if (cents >= 1)
		{
			cents -= 1;
			coins++;
		}
	}

	return (coins);
}

/**
 * main - Main Entry
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: Always 0 (success)
 **/
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int cents = atoi(argv[1]);

		if (cents < 0)
		{
			printf("0\n");
			return (0);
		}

		int coins = count_coins(cents);

		printf("%d\n", coins);
	}
	else
	{
		printf("Error\n");
		return (1);
	}

	return (0);
}
