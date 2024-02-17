#include "main.h"

/**
 * _strstr - Locate a substring.
 * @haystack: The main string to search in.
 * @needle: The substring to search for.
 *
 * Return: Pointer to the beginning of the located substring,
 *	   or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	char *start_haystack;
	char *pattern;

	while (*haystack != '\0')
	{
		start_haystack = haystack;
		pattern = needle;

		while (*pattern != '\0' && *haystack != '\0' && *haystack == *pattern)
		{
			haystack++;
			pattern++;
		}

		if (*pattern == '\0')
			return (start_haystack);

		haystack = start_haystack + 1;
	}

	return (NULL);
}
