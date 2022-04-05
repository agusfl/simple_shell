#include "main.h"

/**
 * main - simple shell
 * @argc: argument counter
 * @argv: argument vector of strings
 * Return: 0 if success
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	char *str = NULL;
	char **array = NULL;
	int space = 0;

	while (1) /* infinite while --> kill with exit */
	{
		/*signal(SIGINT, SIG_IGN); -> para usar cuando tengamos exit*/
		printf("$ ");
		str = _getline();
		space = spaces(str);
		array = _strtok(str, space);

		if (str[0] == '\n')
			continue;

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
			}
		}
		else
		{
			wait(&status);
		}
		_free(1, str);
		_free(2, array);
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
	size_t bufsize = 0;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer ");
		free(buffer);
		exit(0);
	}
	getline(&buffer, &bufsize, stdin);

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
	token_array = malloc(sizeof(char *) * size);

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
