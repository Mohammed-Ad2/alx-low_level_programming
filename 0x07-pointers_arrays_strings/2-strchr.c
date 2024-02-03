#include "main.h"

/**
 * _strchr - locates a character in a string
 * @c: occurrence of the character
 * @s: in the string
 *
 * Return: a pointer to the first occurrence of the character
 */
char *_strchr(char *s, char c)
{
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return (&s[i]);

	if (c == '\0')
		return (&s[i]);

	return (NULL);
}
