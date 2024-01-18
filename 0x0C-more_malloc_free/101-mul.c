#include "main.h"
#include <stdlib.h>

/**
 * main - Multiplies two positive numbers
 * @argc: The argument count
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int *ptr;
	int num1, num2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	if (!(num1 >= 0 && num1 <= 9) || !(num2 >= 0 && num2 <= 9))
	{
		printf("Error\n");
		exit(98);
	}

	ptr = malloc(sizeof(int));
	if (ptr == NULL)
	{
		printf("Memory allocation error\n");
		exit(1);
	}

	*ptr = num1 * num2;
	printf("%d\n", *ptr);

	free(ptr);

	return (0);
}
