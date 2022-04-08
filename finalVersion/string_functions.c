#include "main.h"

/**
 * _strlen - our own implementation of strlen function
 * @str: string that we want to know the length
 * Return: length of the string
 */

int _strlen(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: copy source to this buffer
 * @src: source to copy
 * Return: copy of the original source
 */

char *_strcpy(char *dest, char *src)
{
	int i, length = 0;

	char *new = dest;

	length = _strlen(src);

	for (i = 0; i <= (length + 1); i++)
		new[i] = src[i];

	return (new);
}

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

/**
 * _strcat - concatenates two strings
 * @dest: copy source to this buffer
 * @src: source to copy
 * Return: concatenate strings
 */

char *_strcat(char *dest, char *src)
{
	int i, d;

	i =  _strlen(dest);

	for (d = 0; src[d] != '\0'; i++, d++)
	{
		dest[i] = src[d];
	}
	dest[i] = '\0';
	return (dest);
}
