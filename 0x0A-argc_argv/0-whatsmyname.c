#include <stdio.h>

/**
 * main - prints the first argument to stdout
 *
 * @argc: arguments count
 * @argv: arguments
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);

	return (0);
}
