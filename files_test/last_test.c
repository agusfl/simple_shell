#include "test.h"

int main(void)
{
	char *str = NULL, **array = NULL, *envv = "env";
	int space = 0, status = 0;
	pid_t child;
	char *env[] = {NULL};

	while (1) /* infinite while --> kill with exit or ctrl + d */
	{
		signal(SIGINT, _ctrl_c); /*ctrl c - ignore and make a break line*/
		if (isatty(STDIN_FILENO) == 1) /* If it is 1 the interactive mode is on */
			write(1, "$ ", 2); /* 1 is equal to standard output (pantalla) */
		str = _getline();
		space = spaces(str);
		if (ign_spaces_break_tab(str) != 1)/*Ignore spaces, break line and tabs*/
		{
			_free(1, str);
			continue;
		}
		if (_strcmp(str, envv) == 0)
		{
			print_env();
			_free(1, str);
			continue;
		}
		array = _strtok(str, space);

		_execute(array);
	}
	return (0);
}

void _execute(char **tokenized_input)
{
	int status = 0;
	struct stat st;
	pid_t child;

	if (tokenized_input[0] != NULL)
	{
		if (_isletter(tokenized_input[0][0]) == 1)
		{
			tokenized_input[0] = _realpath(tokenized_input);

			if (tokenized_input[0] == NULL)
			{
				/*free a tok*/
				perror("");
				return;
			}
		}
		if (stat(tokenized_input[0], &st) == 0)
		{
			child = fork();
			if (child == -1)
			{
				perror("Error while creating a child process");
				exit(4);
			}
			if (child == 0) /*if it is 0 means that is the child process */
			{
				if (execve(tokenized_input[0], tokenized_input, environ) == -1)
				{
					perror(NULL); /*Con esto ya devuelve el mensaje por default*/
					/*free*/
					return;
				}
		}
		else /* parent process - waits for the child process to finish */
			wait(&status);
		}
	}
}

char *_realpath(char **tokenized_input)
{
	int i = 0, x = 0;
	char **path = NULL, *realpath = NULL;
	struct stat st;
	
	path = _getpath();
	while (path[i] != NULL)
	{
		realpath = _calloc(3, (sizeof(char) * ((_strlen(path[i])) + (_strlen(tokenized_input[x])) + 2)));
		
		if (realpath == NULL)
		{
			/*free*/
			return (NULL);
		}
		_strcat(realpath, tokenized_input[x]);

		if (stat(realpath, &st) == 0)
		{
			/*free*/
			return (realpath);
		}

	}
	/*free*/
	return (NULL);
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
 * ign_spaces_break_tab - function to ignore spaces, break line and tab to use
 * in the main function.
 * @str: string to search for spaces and break line
 * Return: 1 if there is a space and a break line or 0 if there isnt
 */

int ign_spaces_break_tab(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != 32 && str[i] != '\n' && str[i] != '\t')
		/**
		 * 32 number representation of space character in ASCII
		 **/
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * _ctrl_c - function that ignores ctrl + c input from keybord and prints a
 * break line with $ symbol.
 * @sig: signal to ignore
 **/

void _ctrl_c(int sig)
{
	if (sig == SIGINT)
		write(1, "\n$ ", 3);
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
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: compare strings
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
		/*print in standard outpu the environ variable*/
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
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

	token = strtok(str, "\n"); /*Tokenize with \n to remove it from the string */
	token = strtok(str, separator);

	while (token != NULL)
	{
		token_array[i] = token;
		if (_strcmp(token, exitt) == 0)/*If input is "exit" free memoryandExitShell*/
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
