#include <stdio.h>

/**
 * main - program multiplies two numbers
 * @argc: arguments count
 * @argv: arguments
 *
 * Return: Alwyas 0.
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
