#include "main.h"

/**
 * main - implementation of getline
 * Return: 0 if succes
 **/

int main(void)
{
	char *buffer;
	size_t bufsize = 32;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(0);
	}

	printf("$ ");
	getline(&buffer, &bufsize, stdin);
	printf("%s\n", buffer);

	return (0);
}
