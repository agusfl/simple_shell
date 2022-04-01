#include "main.h"

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
