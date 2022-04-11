#include "main.h"

/**
 * _getpath - Search the PATH variable in environ
 *Return: Returns a pointer to the position of PATH variable
 **/

char **_getpath()
{
	char *path = NULL, **tokenized_path = NULL;
	int i = 0, size = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], "PATH") == 0)
		{
			path = malloc(sizeof(char *) * (_strlen(environ[i])));
			if (path == NULL)
			{
				free(path);
				exit(0);
			}
			_strcpy(path, environ[i]);
			break;
		}
	}
	path += 5;

	size = _colons(path);
	tokenized_path = _pathtok(path, size);

	for (i = 0; tokenized_path[i] != NULL; i++)
	{
		tokenized_path[i] = _strcat(tokenized_path[i], "/");
	}
	path -= 5; /* go back 5 places so path can be freed */
	free(path);
	return (tokenized_path);
}

/**
 * _getline - implementation of getline() for getting a string from the user
 * Return: 0 if success
 **/

char *_getline(void)
{
	char *buffer = NULL;
	size_t bufsize = 0; /* if we set the value on 0 there are leaks */

	if (getline(&buffer, &bufsize, stdin) == -1)
	{
		if (isatty(STDIN_FILENO) == 1)/*if it is interactive mode make a break line*/
		{
			write(1, "\n", 1);
			free(buffer);
			exit(0);
		}
		else /*if not interactive mode dont make the break line*/
		{
			free(buffer);
			exit(0);
		}
	}

	return (buffer);
}

/**
 * print_env - print environmental variables
 * Return: 0 if success
 */

int print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	/*environ is the global variable and was declared in the main.h*/
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		/*print in standard output the environ variable*/
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

/**
 * _realpath - function to search path of command
 * @path: tokenaized path
 * @command: command to search
 * Return: string with the path of the command
 **/

char *_realpath(char **path, char *command)
{
	char *realpath = NULL;
	struct stat st;
	int i = 0;

	for (i = 0; path[i] != NULL; i++)
	{
		realpath = _strcat(path[i], command);

		if (stat(realpath, &st) == 0)
		{
			return (realpath);
		}
		free(realpath);
	}

	return (NULL);
}
