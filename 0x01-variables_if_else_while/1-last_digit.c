#include <stdlib.h>
#include <time.h>
#include<stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: This program generates a random number,
 *		calculates the last digit, and prints a
 *		message based on the conditions.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n, last_digit;

	/* Seed the random number generator with the current time */
	srand(time(0));
	/* Generate a random number and store it in the variable n */
	n = rand() - RAND_MAX / 2;

	/* Calculate the last digit of the random number */
	last_digit = n % 10;

	printf("Last digit of %d is %d ", n, last_digit);
	if (last_digit > 5)
		printf("and is greater than 5\n");

	else if (last_digit == 0)
		printf("and is 0\n");

	else
		printf("and is less than 6 and not 0\n");

	return (0);
}
