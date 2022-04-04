#include "main.h"

/**
 * main - simple shell
 * Return: 0 if success
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	
}

/**
 * _getline - implementation for getting a string from the user
 * Return: 0 if success
 **/

int _getline(void)
{
	char *buffer = NULL;
	size_t bufsize = 1024;

	buffer = malloc(bufsize * sizeof(char));
	printf("$ ");
	getline(&buffer, &bufsize, stdin);

	return (buffer);
}

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

/**
 *_strtok - function for make tokens of a string
 * Return: pointer to an array of the string tokens
 **/
char **_strtok(void)
{
	char *str, *token;
	char *separator = " ";
	int i = 0, size;

	str = _getline();
	size = spaces();

	char **token_array = malloc(sizeof(char *) * size);

	token = strtok(str, separator);
	while (token != NULL)
	{
		printf("%s\n", token);
		token_array[i] = _strdup(token);
		if (token_array == NULL)
		{
			_free(2, token_array);
			return (NULL);
		}
		token = strtok(NULL, separator);
		i++;
	}
	token_array[i] = token;

	return (token_array);
}

/**
 * _free - function to free 1 pointer or a double pointer
 * @n: indicates if it is a 1 pointer to be freed or a double pointer
 **/

void _free(int n, ...)
{
	char *ptr;
	char **dptr;
	va_list valist;
	int i;

	va_start(valist, n);

	if (n == 1)
	{
		ptr = va_arg(valist, char *);
		if (ptr == NULL)
		{
			return;
		}
		free(ptr);
	}
	if (n == 2)
	{
		dptr = va_arg(valist, char **);
		if (dptr == NULL)
		{
			return;
		}
		for (i = 0; dptr[i] != NULL; i++)
		{
			free(dptr);
		}
		free(dptr);
	}
	va_end(valist);
}
