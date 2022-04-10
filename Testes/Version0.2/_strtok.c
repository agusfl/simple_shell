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
	token_array[i] = token; /* Token pasa a ser NULL porque salio del while en NULL y se lo asignamos al ultimo
				   elemento de nuestro array para que termine en NULL */
	return (token_array);
}
