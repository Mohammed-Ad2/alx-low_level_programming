#include<stdio.h>

/**
 * main - prints the largest prime factor of the number 612852475143
 *
 * Return: Always 0 (Success)
*/
int main(void)
{
	long long num;
	int maxPrime, oddPrime;

	num = 612852475143;

	if (num <= 1)
	{
		printf("No prime factor for numbers less than or equal to 1\n");
		return (0);
	}

	maxPrime = 0;
	oddPrime = 3;

	while (num % 2 == 0)
	{
		maxPrime = 2;
		num /= 2;
	}

	while (num != 1)
	{
		while (num % oddPrime == 0)
		{
			maxPrime = oddPrime;
			num /= oddPrime;
		}

		oddPrime += 2;
	}

	printf("%d\n", maxPrime);
	return (0);
}

