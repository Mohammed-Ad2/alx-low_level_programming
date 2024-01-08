#include <stdlib.h>
#include <time.h>
#include<stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program generates a random number
 *              and prints whether it is positive,
 *              negative, or zero.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	/* Seed the random number generator with the current time */
	srand(time(0));
	/* Generate a random number and store it in the variable n */
	n = rand() - RAND_MAX / 2;

	if (n > 0)
		printf("%d is positive", n);

	if (n == 0)
		printf("%d is zero", n);

	if (n < 0)
		printf("%d is negative", n);

	return (0);
}
