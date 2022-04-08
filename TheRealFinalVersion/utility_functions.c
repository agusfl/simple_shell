#include "main.h"

/**
 * ign_spaces_break_tab - function to ignore spaces, break line and tab to use
 * in the main function.
 * @str: string to search for spaces and break line
 * Return: 1 if there is a space and a break line or 0 if there isnt
 */

int ign_spaces_break_tab(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != 32 && str[i] != '\n' && str[i] != '\t')
		/**
		 * 32 number representation of space character in ASCII
		 **/
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * spaces - function to get the number of spaces of a string.
 * @str: string to count spaces
 * Return: number of spaces plus 1 for the null byte of the last word
 */

int spaces(char *str)
{
	int space = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == 32) /*number representation of space character in ASCII */
		{
			space++;
		}
		i++;
	}
	space += 2;/*added space for a new word and the NULL element of array*/

	return (space);
}

/**
 * _colons - function to get the number of spaces of a string.
 * @str: string to count spaces
 * Return: number of spaces plus 1 for the null byte of the last word
 */

int _colons(char *str)
{
	int colons = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ':') /*number representation of space character in ASCII */
		{
			colons++;
		}
		i++;
	}
	colons += 2;/*added space for a new word and the NULL element of array*/

	return (colons);
}

/**
 *_isletter - asas
 *
 *@c: sdf
 * Return:asd
*/
int _isletter(int c)
{
	if ((c >= 'a' &&  c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}