#include <stdio.h>
#include <math.h>

/**
 * maxPrimeFactor - Finds the largest prime factor of a given number.
 *
 * @n: The input number for which the largest prime factor is to be found.
 *
 * Return: The largest prime factor of the input number.
 */
long long maxPrimeFactor(long long n)
{
	long long maxPrime = -1;

	while (n % 2 == 0)
	{
		maxPrime = 2;
		n /= 2;
	}

	for (long long i = 3; i <= sqrt(n); i += 2)
	{
		while (n % i == 0)
		{
			maxPrime = i;
			n /= i;
		}
	}

	if (n > 2)
		maxPrime = n;

	return (maxPrime);
}

/**
 * main - Find the largest prime factor.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long long n = 612852475143;

	printf("%lld\n", maxPrimeFactor(n));

	return (0);
}
