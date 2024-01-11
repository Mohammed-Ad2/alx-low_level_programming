#include"main.h"

/**
 * _sqrt_helper - recursive helper function to find the square root
 * @n: the number to calculate the square root for
 * @guess: current guess for the square root
 *
 * Return: natural square root of n, or -1 if n
 *	   doesn't have a natural square root
 */
int _sqrt_helper(int n, int guess)
{
	if (n < 0)
		return (-1);

	if (guess * guess == n)
		return (guess);

	if (guess * guess > n)
		return (-1);

	return (_sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to calculate the square root for
 *
 * Return: natural square root of n, or -1 if n
 *	   doesn't have a natural square root
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_helper(n, 1));
}
