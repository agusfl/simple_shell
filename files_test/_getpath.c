#include "../main.h"

/**
 * _getpath - Search the PATH variable in environ
 *Return: Returns a pointer to the position of PATH variable
 **/
char *_getpath()
{
	char *path = NULL;
	int i = 0;

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
	return (path);
}

/**
 * _realpath - Change the = from PATH to : (make it tokenizable)
 *@path: string returned from _getpath()
 *Return: 
 **/
void _realpath(char *path)
{
	
}

char *_
