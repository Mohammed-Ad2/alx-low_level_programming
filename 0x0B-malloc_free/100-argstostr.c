#include"main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates command-line arguments into a single
 *	       string.
 *
 * @ac: The number of command-line arguments.
 * @av: An array of strings representing command-line arguments.
 *
 * Return: A pointer to the newly allocated string, or NULL if
 *	   memory allocation fails or if ac is 0 or av is NULL.
 */
char *argstostr(int ac, char **av)
{
	char *ptr;
	int i, j, k = 0, len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
		len++;
	}

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			ptr[k++] = av[i][j];

		ptr[k++] = '\n';
	}

	ptr[k] = '\0';
	return (ptr);
}
