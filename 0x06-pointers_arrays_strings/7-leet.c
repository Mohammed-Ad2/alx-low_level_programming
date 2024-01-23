#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: input string
 *
 * Return: Pointer to the resulting string
 */
char *leet(char *str)
{
	int i, j;
	char *leetChar = "aAeEoOtTlL";
	char *leetReplacements = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; leetChar[j] != '\0'; j++)
		{
			if (str[i] == leetChar[j])
			{
				str[i] = leetReplacements[j];
				break;
			}
		}
	}

	return (str);
}

