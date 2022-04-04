#include "main.h"

/**
 * main - simple shell
 * Return: 0 if success
 */
int main(int __attribute__((unused)) argc, char **argv)
{

}

/**
 * _getline - implementation for getting a string from the user
 * Return: 0 if success
 **/

int _getline(void)
{
	char *buffer = NULL;/* Buena practica setear en NULL*/
	size_t bufsize = 1024;
	/* Por defecto la funcion getline realoca al tamanio que se necesite
	 * le ponemos un tamanio porque sino quedaban memory leaks.*/

	buffer = malloc(bufsize * sizeof(char));
	printf("$ ");
	getline(&buffer, &bufsize, stdin);
	printf("%s", buffer);
	free(buffer);

	return (0);
}

/**
 * spaces - function to get spaces of a string
 * Return: number of spaces plus 1 for the null byte of the last word
 */

int spaces(void)
{
	char *str;
	int space = 0, i = 0;

	str = _getline();

	while (str[i] != '\0')
	{
		if (str[i] == 32)
		{
			space++;
		}
		i++;
	}
	space++;
	return (space);
}

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
