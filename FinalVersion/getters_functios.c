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
				_free(1, path);
				exit(-1);
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
	path -= 5;
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
	size_t bufsize = 100; /* if we set the value on 0 there are leaks */

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		_free(1, buffer);
		exit(4);
	}
	if (getline(&buffer, &bufsize, stdin) == -1)
	{
		if (isatty(STDIN_FILENO) == 1)/*if it is interactive mode make a break line*/
		{
			write(1, "\n", 1);
			_free(1, buffer);
			exit(4);
		}
		else /*if not interactive mode dont make the break line*/
		{
			_free(1, buffer);
			exit(4);
		}
	}

	return (buffer);
}

