#include "main.h"

/**
 * main - simple shell
 * Return: 0 if success
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	/*getline*/
	char *buffer = NULL;/* Buena practica setear en NULL*/
	size_t bufsize = 1024;/*Por defecto la funcion getline realoca al tamanio que se necesite*/

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer"); /*Print message error */
		free(buffer); /*free buffer in case it fails malloc */
		exit(0); /*exit function in case of error */
	}
	printf("$ ");
	getline(&buffer, &bufsize, stdin);

	/*Spaces*/

	char *str;
        int space = 0, x = 0;

        str = buffer;

        while (str[x] != '\0')
        {
                if (str[x] == 32)
                {
                        space++;
                }
                x++;
        }
        space++;

	/*strtok*/

	char *str2, *token;
        char *separator = " ";
        int i = 0, size;

        str2 = buffer;
        size = space;

        char **token_array = malloc(sizeof(char *) * size);
	
	token = strtok(str2, "\n");
        token = strtok(str2, separator);

        while (token != NULL)
        {
                token_array[i] = token;
                if (token_array == NULL)
                {
                        _free(2, token_array);
                        return (0);
                }
		token = strtok(NULL, separator);
                i++;
        }
        token_array[i] = token; /* Token pasa a ser NULL porque salio del while en NULL y se lo asignamos al ultimo
                                   elemento de nuestro array para que termine en NULL */

	/*shell*/
	pid_t child;

	char *env[] = {NULL};
	int status, child_count = 0;

	while (child_count < 1)
	{
		child = fork();
		if (child == -1)
		{
			perror("Error while creating a child process");
			exit(1);
		}
		if (child == 0) /*if it is 0 means that is the child process */
		{
			if (execve(token_array[0], token_array, env) == -1)
			{
				perror("Could not execute execve");
			}
		}
		else
		{
			wait(&status);
		}
	child_count++;
	}
	free(buffer);
	return (0);
}
