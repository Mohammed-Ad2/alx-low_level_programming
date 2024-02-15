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
	while (*haystack != '\0')
	{
		char *start = haystack;
		char *pattern = needle;

		while (*start == *pattern && *pattern != '\0')
		{
			start++;
			pattern++;
		}

		if (*pattern != '\0')
			return (haystack);
	}

	return (0);
}
