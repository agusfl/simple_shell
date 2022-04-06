#include "../main.h"

/**
 *
 *
 *
 *
 *
 *
 **/
char *_getpath()
{
	char *path = NULL;
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strcomparer(environ[i], "PATH") == 0)
		{
			path = malloc(sizeof(char *) * (strlarge(environ[i])));
			if (path == NULL)
			{
				freedom(1, path);
				exit(-1);
			}
			_strcpy(path, environ[i]);
			break;
		}
	}
	return (path);
}
