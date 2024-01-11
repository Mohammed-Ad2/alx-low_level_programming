#include"main.h"

/**
 * is_palindrome_recursive - Returns 1 if a substring is a palindrome
 *                           and 0 if not.
 * @s: The input string.
 * @start: The starting index of the substring.
 * @end: The ending index of the substring.
 *
 * Return: 1 if the substring is a palindrome, 0 otherwise.
 */
int is_palindrome_recursive(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (is_palindrome_recursive(s, start + 1, end - 1));
}

/**
 * is_palindrome - Checks if a given string is a palindrome.
 * @s: The input string.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;

	return (is_palindrome_recursive(s, 0, length - 1));
}
