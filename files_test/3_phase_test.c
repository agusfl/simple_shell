#include "../main.h"

char *reading_phase()
{

}

char *searching_phase()
{

}
char *execution_phase()
{
}


char *main(void)
{
	char *PATH = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	
	char *str = NULL, **array = NULL;
	int space = 0;

	
}

/**
 * colons - function to get the number of spaces of a string.
 * @str: string to count spaces
 * Return: number of spaces plus 1 for the null byte of the last word
 */

int colons(char *str)
{
	int colon = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == 32) /*number representation of space character in ASCII */
		{
			colon++;
		}
		i++;
	}
	colon += 2;/*added space for a new word and the NULL element of array*/

	return (colon);
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
