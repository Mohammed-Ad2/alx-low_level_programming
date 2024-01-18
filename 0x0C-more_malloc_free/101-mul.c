#include "main.h"
#include <stdlib.h>

/**
 * is_digit - Checks if a string consists of digits
 * @str: The string to check
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_digit(char *str)
{
	while (*str)
	{
		if (*str <= '0' || *str >= '9')
			return (0);
		str++;
	}

	return (1);
}

/**
 * multiply - Multiplies two numbers
 * @num1: The first number
 * @num2: The second number
 *
 * Return: The result of the multiplication
 */
int multiply(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * main - Multiplies two positive numbers
 * @argc: The argument count
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int num1, num2, *result;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	result = malloc(sizeof(int) * argc);

	result[0] = multiply(num1, num2);
	printf("%d\n", *result);

	return (0);
}
