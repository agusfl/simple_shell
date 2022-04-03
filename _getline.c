#include "main.h"

/**
 * _getline - implementation for getting a string from the user
 * Return: 0 if success
 **/

int _getline(void)
{
	char *buffer = NULL;/* Buena practica setear en NULL*/
	size_t bufsize = 0;/*Por defecto la funcion getline realoca al tamanio que se necesite*/

	buffer = malloc(bufsize * sizeof(char));
	printf("$ ");
	getline(&buffer, &bufsize, stdin);
	printf("%s", buffer);
	free(buffer);

	return (0);
}
