#include "main.h"

/**
 * _strcmp - Compares two strings
 * @s1: input parameter
 * @s2: input parameter
 *
 * Return: 0 if equal or a if is different
 */
int _strcmp(char *s1, char *s2)
{
	int i, a = 0;

	for (i = 0; s1[i] != '\0' && a == 0; i++)
		a = s1[i] - s2[i];

	return (a);
}
