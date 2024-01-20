#include "main.h"

/**
 *_strncpy - Copies a string
 * @src: The source of strings
 * @dest: The destination of the string
 * @n: The length of int
 *
 * Return: Pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, len;

	len = 0;
	while (src[len] != '\0' && len < n)
		len++;

	for (i = 0; i < len; i++)
		dest[i] = src[i];

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
