#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: compare strings
 */

int _strcmp(char *s1, char *s2)
{
	int diff = 0, i = 0;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		diff = s1[i] - s2[i];

		if (diff != 0)
			break;

		i++;
	}

	return (diff);
}
