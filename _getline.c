#include "main.h"

/**
 * _getline - implementation for getting a string from the user
 * Return: buffer --> this is the string to tokenizae with strtok.
 **/

char *_getline(void)
{
	char *buffer = NULL, *buffer_ret = NULL; /* Buena practica setear en NULL */
	size_t bufsize = 1024; /* Cambiar cantidad de espacio */

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
	buffer_ret = strdup(buffer);
	free(buffer);

	return (buffer_ret);
}
