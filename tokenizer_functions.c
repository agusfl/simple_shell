#include "main.h"

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
			_free(1, str), _free(2, token_array);
			return(NULL);
		}
		if (token_array == NULL)
		{
			_free(2, token_array), _free(1, str);
			return (NULL);
		}
		token = strtok(NULL, separator);
		i++;
	}
	token_array[i] = NULL;
	
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
	char *token, *separator = ":";
	char **tokenized_path;
	int i = 0;

	size = _colons(str);
	tokenized_path = _calloc(size, sizeof(char *));

	token = strtok(str, "\n"); /*Tokenize with \n to remove it from the string */
	token = strtok(str, separator);

	while (token != NULL)
	{
		tokenized_path[i] = token;

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

