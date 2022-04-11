#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: copy source to this buffer
 * @src: source to copy
 * Return: concatenate strings
 **/

char *_strcat(char *dest, char *src)
{
	int dest_length = 0, src_length = 0, i = 0;
	char *new_string = NULL;

	while (dest[dest_length] != '\0')
		dest_length++;

	while (src[src_length] != '\0')
		src_length++;

	new_string = _calloc(2, (dest_length + src_length + 1) * sizeof(char));

	if (new_string == NULL)
	{
		free(new_string);
		return (NULL);
	}

	while (dest_length > i)
	{
		new_string[i] = dest[i];
		i++;
	}

	i = 0;

	while (src_length > i)
	{
		new_string[dest_length + i] = src[i];
		i++;
	}

	new_string[dest_length + i + 1] = '\0';

	return (new_string);
}

/**
 * _strlen - our own implementation of strlen function
 * @str: string that we want to know the length
 * Return: length of the string
 **/

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
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: compare strings
 **/

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
 * _strcpy - copies the string pointed to by src
 * @dest: copy source to this buffer
 * @src: source to copy
 * Return: copy of the original source
 **/

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
 *_strdup - duplicate a string
 *@str: string to be copied
 *Return: NULL if str is NULL or a pointer to the duplicateed string
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
	{
		free(str_copy);
		return (NULL);
	}

	for (i = 0; i < length; i++)
		*(str_copy + i) = *(str + i);

	return (str_copy);
}
