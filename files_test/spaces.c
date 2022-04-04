#include "main.h"

/**
 * spaces - function to get spaces of a string
 * Return: number of spaces plus 1 for the null byte of the last word
 */

int spaces(void)
{
	char *str;
	int space = 0, i = 0;

	str = _getline();

	while (str[i] != '\0')
	{
		if (str[i] == 32)
		{
			space++;
		}
		i++;
	}
	space++;
	return (space);
}
