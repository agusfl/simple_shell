#include "main.h"

/**
 *_strtok - function for make tokens of a string
 * Return: pointer to an array of the string tokens
 **/
char **_strtok(void)
{
	char *str, *token;
	char *separator = " ";
	int i = 0, size;

	str = "Hola";
	size = 1;

	char **token_array = malloc(sizeof(char *) * size);

	token = strtok(str, separator);
	while (token != NULL)
	{
		printf("%s\n", token);
		token_array[i] = _strdup(token);
		if (token_array == NULL)
		{
			_free(2, token_array);
			return (NULL);
		}
		token = strtok(NULL, separator);
		i++;
	}
	token_array[i] = token;
	/* Token pasa a ser NULL porque salio del while en NULL y se lo asignamos*/
	/*al ultimo elemento de nuestro array para que termine en NULL */

	return (token_array);
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

	size = _colons(str);
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