#include "test.h"

int main()
{
	char **patty;
	int i = 0;
	char *asd = "asd";
	char *commando; 
	patty = _getpath();

	putchar('\n');
	for (i = 0; patty[i] != NULL; i++)
	{
		patty[i] = _strcat(patty[i], "ls");
		printf("%d%s\n",i, patty[i]);
	}

	_execute(patty, NULL);

/*	if (_isletter(asd[0]) == 0)
		printf("a\n");
	else
		printf("b\n");
*/	

	return (0);
}



int _execute(char **command_path, char* command)
{
	char **path = NULL;
	int i = 0, status = 0;
	pid_t child;
	struct stat st;
	char *env[] = {NULL};

	if (command == NULL && command_path == NULL)
		return (0);

	printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");

	if (command != NULL)
	{
		printf("CCCCCCCCCCCCCCCCCCCCCC");
		path = _getpath();

		if (stat(path[i], &st) == 0) /*En caso de que exista el commando devuelve uno, crea el hijo y ejecuta*/
		{
			child = fork();
                        if (child == -1)
                        {
                        	perror("asd");
                                return (-1);
                        }
                        if (child == 0)
                        {
                                if (execve(command_path[i], command_path, env) == -1)
                        	{
                                	perror("asd");
                                        /*FREES*/
                                        return (0);
                                }
                        }
                        else
                        {
                                wait(&status);
                        }
	
		}
		else
		{
			perror("asd");
		}
	}
	
	if (command_path != NULL)
	{
		printf("BBBBBBBBBBBBBBBBBBBBBBBBBBB\n");
		for (i = 0; command_path[i] != NULL; i++)
		{
			if(stat(command_path[i], &st) == 0)
			{
				child = fork();
				if (child == -1)
				{
					perror("ad");
					return (-1);
				}
				if (child == 0)
				{
					if (execve(command_path[i], command_path, env) == -1)
					{
						perror("asd");
						/*FREES*/
						return (0);
					}
				}
				else
				{
					wait(&status);
				}
			}
			else
			{
				perror("asd");
			}
		}
	}
	else
	{
		return (0);
	}



}


/**
 *_isletter - asas
 *
 *@c: sdf
 * Return:asd
*/
int _isletter(int c)
{
	if ((c >= 'a' &&  c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _strcat - concatenates two strings
 * @dest: copy source to this buffer
 * @src: source to copy
 * Return: concatenate strings
 */

char *_strcat(char *dest, char *src)
{	
	int dest_length = 0, src_length = 0, i = 0;
	char *new_string = NULL;

	while (dest[dest_length] != '\0')
		dest_length++;

	while (src[src_length] != '\0')
		src_length++;

	new_string = _calloc(2, (dest_length + src_length + 1) * sizeof(char));

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
 * _getpath - Search the PATH variable in environ
 *Return: Returns a pointer to the position of PATH variable
 **/
char **_getpath()
{
	char *path = NULL, **tokenized_path;
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


	return (tokenized_path);
}

/**
 * strcomparer - Compares two given  strings
 * @s1: Given S1 String
 * @s2: Given S2 String
 * Return: 0 if both are equals or ascii diff
*/
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
 * _strlen - our own implementation of strlen function
 * @str: string that we want to know the length
 * Return: length of the string
 */

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

/**
 * _strcpy - copies the string pointed to by src
 * @dest: copy source to this buffer
 * @src: source to copy
 * Return: copy of the original source
 */

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
 * _pathtok - function for make tokens from a string
 * @str: string to be tokenaized
 * @size: spaces to tokenaized in the string
 * Return: pointer to an array of the string tokens
 **/

char **_pathtok(char *str, int size)
{
	char *token, *separator = ":", *exitt = "exit";
	char **tokenized_path;
	int i = 0;

	size = _colons(str); //CAMBIAR POR COLONS
	tokenized_path = _calloc(size, sizeof(char *));

	token = strtok(str, "\n"); /*Tokenize with \n to remove it from the string */
	token = strtok(str, separator);

	while (token != NULL)
	{
		tokenized_path[i] = token;
		if (_strcmp(token, exitt) == 0)/*If input is "exit" free memoryandExitShell*/
		{
			_free(1, str), _free(1, tokenized_path);
			exit(1);
		}
		if (tokenized_path == NULL)
		{
			_free(1, tokenized_path);
			return (NULL);
		}
		token = strtok(NULL, separator);
		i++;
	}
	tokenized_path[i] = NULL;

	return (tokenized_path);
}

/**
 * _colons - function to get the number of spaces of a string.
 * @str: string to count spaces
 * Return: number of spaces plus 1 for the null byte of the last word
 */

int _colons(char *str)
{
	int colons = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ':') /*number representation of space character in ASCII */
		{
			colons++;
		}
		i++;
	}
	colons += 2;/*added space for a new word and the NULL element of array*/

	return (colons);
}

/**
 *_calloc - allocates memory for an array
 *@nmemb: number of elements of the array
 *@size: size in bytes of the array
 *Return: pointer to the array or NULL if it fails
 **/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *mem_space;
	unsigned int i, limit = 0;

	limit = nmemb * size;

	if (limit <= 0)
		return (NULL);

	mem_space = malloc(limit);

	if (mem_space == NULL)
		return (NULL);

	for (i = 0; i < limit; i++)
		*((char *)mem_space + i) = 0;

	return (mem_space);
}
