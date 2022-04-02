#include "main.h"

/**
 * _getline - implementation for getting a string from the user
 * Return: string read
 **/

char *_getline(void)
{
	char *buffer = NULL;/* Buena practica setear en NULL*/
	size_t bufsize = 0;/*Por defecto la funcion getline realoca al tamanio que se necesite*/

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer"); /*Print message error */
		free(buffer); /*free buffer in case it fails malloc */
		exit(0); /*exit function in case of error */
	}

	printf("$ ");
	getline(&buffer, &bufsize, stdin);
	printf("%s", buffer);
	free(buffer);

	return (0);
}
