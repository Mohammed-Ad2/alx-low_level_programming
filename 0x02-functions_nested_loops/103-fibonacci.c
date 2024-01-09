#include<stdio.h>

/**
 * main - Finds and prints the sum of the even-valued terms
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	unsigned long int a, b, result, sum;

	a = 1;
	b = 2;
	sum = 0;
	for (i = 0; a < 4000000; i++)
	{
		if ((a % 2) == 0)
			sum += a;

		result = a + b;
		a = b;
		b = result;
	}
	printf("%d\n", sum);

	return (0);
}
