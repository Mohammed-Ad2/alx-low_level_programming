#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: Input string
 *
 * Return: String in reverse
 */
void rev_string(char *s)
{
	int i, len = 0;
	char temp;

	while (s[len] != '\0')
		len++;

	len--;

	for (i = 0; i < len; i++)
	{
		temp = s[i];
		s[i] = s[len];
		s[len] = temp;
		len--;
	}
}
