#include "main.h"

/**
 *_strtok - function for make tokens of a string
 * Return: a completar
 **/
int _strtok(void)
{
	char *str, *token;
	char separator[2] = " ";
	int i = 0, size;

	str = _getline();

	size = spaces();

	char *array[size];

	token = strtok(str, separator);

	while (token != NULL)
	{
		printf("%s\n", token);
		array[i] = token;
		token = strtok(NULL, separator);
		i++;
	}
	printf("==============================\n"); /*Prueba, despues borrar */
	for (i = 0; i < size; i++)
	{
		printf("%s\n", array[i]);
	}

	return (0);
}
