#include "main.h"

/**
 * cap_string - Capitalizes all words in a string.
 * @str: The input string.
 *
 * Return: A pointer to the modified string.
 */
char *cap_string(char *str)
{
	int i, j;
	char separators[] = " \t\n,;.!?\"(){}";

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 'a' - 'A';

	for (i = 1; str[i] != '\0'; i++)
	{
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (str[i - 1] == separators[j] && (str[i] >= 'a' && str[i] <= 'z'))
			{
				str[i] -= 'a' - 'A';
				break;
			}
		}
	}

	return (str);
}
