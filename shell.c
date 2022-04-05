#include "main.h"

/**
 * main - simple shell
 * @argc: argument counter
 * @argv: argument vector of strings
 * Return: 0 if success
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	char *str = NULL, **array = NULL;
	int space = 0;

	while (1) /* infinite while --> kill with exit or ctrl + d */
	{
		signal(SIGINT, _ctrl_c); /*ctrl c - ignore and make a break line*/
		printf("$ ");
		str = _getline();
		space = spaces(str);

		if (str[0] == '\n')
		{
			_free(1, str);
			continue;
		}
		array = _strtok(str, space);
		pid_t child;
		char *env[] = {NULL};
		int status;

		child = fork();
		if (child == -1)
		{
			perror("Error while creating a child process");
			exit(1);
		}
		if (child == 0) /*if it is 0 means that is the child process */
		{
			if (execve(array[0], array, env) == -1)
			{
				perror("Could not execute execve");
				_free(1, str), _free(1, array);/*In case of error free allocated memory*/
				return (0);
			}
			else if (EOF == 1) /*ctrl d*/
				return (0);
		}
		else /* parent process */
			wait(&status);
		_free(1, str), _free(1, array);
	}
	return (0);
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
 * _strtok - function for make tokens from a string
 * @str: string to be tokenaized
 * @size: spaces to tokenaized in the string
 * Return: pointer to an array of the string tokens
 **/

char **_strtok(char *str, int size)
{
	char *token, *separator = " ", *exitt = "exit";
	char **token_array;
	int i = 0;

	size = spaces(str);
	token_array = _calloc(size, sizeof(char *));

	token = strtok(str, "\n"); /*Tokenize with \n to remove it from the string*/
	token = strtok(str, separator);

	while (token != NULL)
	{
		token_array[i] = token;
		if (strcmp(token, exitt) == 0)
		{
			_free(1, str), _free(1, token_array);
			exit(1);
		}
		if (token_array == NULL)
		{
			_free(1, token_array);
			return (NULL);
		}
		token = strtok(NULL, separator);
		i++;
	}
	token_array[i] = NULL;

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
