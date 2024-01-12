#include <stdio.h>

/**
 * main - prints all the arguments the program receives
 *
 * @argc: arguments count
 * @argv: arguments
 *
 * Return: always 0.
 */
int main(int argc, char *argv[])
{
	(void)argv;

	printf("%d\n", argc - 1);

	return (0);
}
