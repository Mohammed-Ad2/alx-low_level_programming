#include"main.h"

/**
 * _strstr - Locates a substring
 * @haystack: The main string
 * @needle: The substring to find
 *
 * Return: A pointer to the beginning of the located substring,
 *         or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *start = haystack;
		char *pattern = needle;

		while (*haystack && *pattern && *haystack == *pattern)
		{
			haystack++;
			pattern++;
		}

		if (!*pattern)
			return (start);

		haystack = start + 1;
	}

	return ('\0');
}
