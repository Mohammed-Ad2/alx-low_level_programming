#include"main.h"
#include <stdlib.h>

/**
 * _strdup - Duplicates a string using dynamic memory allocation.
 *
 * @str: The input string to be duplicated.
 *
 * Return: A pointer to the newly duplicated string, or
 *	   NULL if it fails or if the input string is NULL.
 */
char *_strdup(char *str)
{
	char *ptr;
	unsigned int i;
	int len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		ptr[i] = str[i];

	ptr[i] = '\0';
	return (ptr);
}
