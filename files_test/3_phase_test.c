#include "../main.h"

/**
 * 
**/
char **reading_phase()
{
	int size, colons, i; 
	char *input, *path;
	char **tokenized_input, **tokenized_path, **command;

	path = getenv("PATH");
	input = _getline();
	size = _spaces(input);
	colons = _colons(path);
	tokenized_input = _strtok(input, spaces);
	tokenized_path = _pathtok(path, colons);

	if (input[0] == '/')
	{
		return (tokenized_input);
	}
	else
	{
		for (i = 0; i < colons; i++)
		{
			command = _strncat(tokenized_path[i], tokenized_input, colons);
		}
		
	}
}

/**
 * 
**/
char *searching_phase()
{
	Recibe char ** tokenizado por reading y compara con PATH hasta encontrar la coincidencia, al encontrar retirna un char *
	a execution_phase para ser ejecutado

	char *string;
	
	int size;
	char **tokenized_path;
		
}

/**
 * 
**/
char *execution_phase()
{
	Recibe un char * el cual tendra la ruta del path mas el conado y lo ejecutara
}

/**
 * main - simple shell
 * @argc: argument counter
 * @argv: argument vector of strings
 * Return: 0 if success
 */
char *main(void)
{
	char *PATH = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	
	char *str = NULL, **array = NULL;
	int space = 0;

	
}

/**
 * _getline - implementation of getline() for getting a string from the user
 * Return: 0 if success
 **/
char *_getline(void)
{
	char *buffer = NULL;
	size_t bufsize = 100; /* if we set the value on 0 there are leaks */

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer ");
		_free(1, buffer);
		exit(1);
	}
	if (getline(&buffer, &bufsize, stdin) == -1)
	{
		perror("Error in getline");
		_free(1, buffer);
		exit(1);
	}

	return (buffer);
}

/**
 * colons - function to get the number of spaces of a string.
 * @str: string to count spaces
 * Return: number of spaces plus 1 for the null byte of the last word
 */
int _colons(char *str)
{
	int colons = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == 32) /*number representation of space character in ASCII */
		{
			colons++;
		}
		i++;
	}
	colons += 2;/*added space for a new word and the NULL element of array*/

	return (colons);
}

/**
 * spaces - function to get the number of spaces of a string.
 * @str: string to count spaces
 * Return: number of spaces plus 1 for the null byte of the last word
 */
int _spaces(char *str)

{
	int spaces = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == 32) /*number representation of space character in ASCII */
		{
			spaces++;
		}
		i++;
	}
	spaces += 2;/*added space for a new word and the NULL element of array*/

	return (spaces);
}

/**
 * _strtok - function for make tokens from a string
 * @str: string to be tokenaized
 * @size: spaces to tokenaized in the string
 * Return: pointer to an array of the string tokens
 **/
char **_strtok(char *str, int size)
{
	char *token, *separator = " ";
	char **token_array;
	int i = 0;

	size = spaces(str);
	token_array = _calloc(size, sizeof(char *));

	token = strtok(str, "\n"); /*Tokenize with \n to remove it from the string*/
	token = strtok(str, separator);

	while (token != NULL)
	{
		token_array[i] = token;
		if (token_array == NULL)
		{
			_free(2, token_array);
			return (NULL);
		}
		token = strtok(NULL, separator);
		i++;
	}
	token_array[i] = NULL;

	return (token_array);
}

/**
 * _pathtok - function for make tokens from a string
 * @str: string to be tokenaized
 * @size: spaces to tokenaized in the string
 * Return: pointer to an array of the string tokens
 **/
char **_pathtok(char *str, int size)
{
	char *token, *separator = ":";
	char **token_array;
	int i = 0;

	size = spaces(str);
	token_array = _calloc(size, sizeof(char *));

	token = strtok(str, "\n"); /*Tokenize with \n to remove it from the string*/
	token = strtok(str, separator);

	while (token != NULL)
	{
		token_array[i] = token;
		if (token_array == NULL)
		{
			_free(2, token_array);
			return (NULL);
		}
		token = strtok(NULL, separator);
		i++;
	}
	token_array[i] = NULL;

	return (token_array);
}

/**
*_strncat - asd
*@dest: asd
*@src: asd
*@n: asd
*Return: asd
*
**/
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, length = 0;

	while (dest[i++] != '\0')
		length++;

	for (i = 0; i < n && src[i] != '\0'; i++, length++)
		dest[length] = src[i];

	return (dest);
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
