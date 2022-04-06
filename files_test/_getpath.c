#include "../main.h"

/**
 * _getpath - asd
 *Return: asd
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
 *
 *
 *
 *
 **/
char **_realpath(char *)
{
	recibe el path, le cambia el signo de igual por : y lo tokeniza respecto a : y le concatena a cada
	toek la ruta ingresada, devuelve un nuevo char ** con el path + ruta

}

char *_
