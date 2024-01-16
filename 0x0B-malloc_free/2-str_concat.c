#include"main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 *
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: A pointer to the newly concatenated string, or
 *	   NULL if it fails to allocate memory.
 */
char *str_concat(char *s1, char *s2)
{
	char *ptr;
	int i, len1, len2;

	len1 = len2 = 0;
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	if (s1 == NULL || s2 == NULL)
	{
		s1 = "";
		s2 = "";
	}

	ptr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		ptr[i] = s1[i];

	for (i = 0; i < len2; i++)
		ptr[i + len1] = s2[i];

	ptr[i + len1] = '\0';

	return (ptr);
}
