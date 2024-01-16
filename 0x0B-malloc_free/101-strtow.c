#include"main.h"
#include <stdlib.h>

/**
 * word_count - Counts the number of words in a string
 * @str: The string to count
 *
 * Return: The number of words in the string
 */
int word_count(char *str)
{
	int i, count, flag;

	count = 0;
	flag = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (flag == 0)
			{
				count++;
				flag = 1;
			}
		}
		else
			flag = 0;
	}
	return (count);
}

/**
 * word_len - Calculates the length of a word
 * @str: The string to measure
 *
 * Return: The length of the word
 */
int word_len(char *str)
{
	int i, len;

	len = 0;
	for (i = 0; str[i] != '\0' && str[i] != ' '; i++)
		len++;

	return (len);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, w, len, n;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	n = word_count(str);
	if (n == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (n + 1));
	if (words == NULL)
		return (NULL);
	i = 0;
	w = 0;
	while (w < n)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break;
		len = word_len(str + i);
		words[w] = malloc(sizeof(char) * (len + 1));
		if (words[w] == NULL)
		{
			for (k = 0; k < w; k++)
			free(words[k]);
			free(words);
			return (NULL);
		}
		for (j = 0; j < len; j++)
			words[w][j] = str[i + j];
		words[w][j] = '\0';
		i += len;
		w++;
	}
	words[w] = NULL;
	return (words);
}
