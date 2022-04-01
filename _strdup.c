#include "main.h"

/**
 *_strdup - asd
 *@str: asd
 *Return: asd
 **/
char *_strdup(char *str)
{
	int i = 0, length = 0;
	char *str_copy;

	if (str == NULL)
		return (NULL);

	while (*(str + length))
		length++;

	length += 1;

	str_copy = malloc(sizeof(char) * length);

	if (str_copy == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		*(str_copy + i) = *(str + i);

	return (str_copy);

}
