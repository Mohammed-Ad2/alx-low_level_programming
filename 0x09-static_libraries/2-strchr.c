#include "main.h"

/**
 * _strchr - Locates a character in a string
 * @c: occurrence of the character
 * @s: in the string
 *
 * Return: a pointer to the first occurrence of the character
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	/**
	 * if c is '\0', you should return
	 * the pointer to the '\0' of the
	 * string s
	*/
	if (*s == c)
		return (s);

	/*return null if not found*/
	return ('\0');
}
