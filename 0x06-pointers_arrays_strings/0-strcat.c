#include "main.h"

/**
 * _strcat - Concatenates two string
 * @dest: string
 * @src:string
 *
 * Return: Pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i, len1, len2;

	len1 = len2 = 0;
	while (dest[len1] != '\0')
		len1++;

	while (src[len2] != '\0')
		len2++;

	for (i = 0; i < (len1 + len2); i++)
		dest[len1 + i] = src[i];

	dest[len1 + i] = '\0';

	return (dest);
}

