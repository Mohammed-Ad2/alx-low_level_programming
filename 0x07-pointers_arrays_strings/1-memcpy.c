#include "main.h"

/**
 * _memcpy - Copies @n bytes from memory area @src
 *	     to memory area @dest
 * @n: function copies
 * @src: bytes from memory area
 * @dest: to memory area
 *
 * Return: a pointer to @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
