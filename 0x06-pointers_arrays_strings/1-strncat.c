#include "main.h"

/**
 * _strncat - Concatenates two strings
 * @src: The source of strings
 * @dest: The destination of the string
 * @n: The length of int
 *
 * Return: Pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, len1, len2;

	len1 = len2 = 0;
	while (dest[len1] != '\0')
		len1++;
	while (src[len2] != '\0' && len2 < n)
		len2++;

	for (i = 0; i < len2; i++)
		dest[(len1) + i] = src[i];

	dest[len1 + i] = '\0';
	return (dest);
}
