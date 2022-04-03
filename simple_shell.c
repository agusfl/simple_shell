#include "main.h"

/**
 * main - simple shell
 * Return: 0 if success
 */

int main(int __attribute__((unused)) argc, char **argv)
{
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
	printf("%s", buffer);

	pid_t child;

	char *argV[] = {buffer, NULL};
	char *env[] = {NULL};
	int status, child_count = 0;

	printf("1 %s\n",argV[0]);
	while (child_count < 1)
	{
		printf("2 %s\n",argV[0]);
		child = fork();
		if (child == -1)
		{
			printf("3 %s\n",argV[0]);
			perror("Error while creating a child process");
			exit(1);
		}
		
		if (child == 0) /*if it is 0 means that is the child process */
		{
			printf("4 %s\n",argV[0]);
			printf("Child process ID: %d\n", getpid());

			if (execve(argV[0], argV, env) == -1)
			{
				printf("5 %s\n",argV[0]);
				perror("Could not execute execve");
			}
		}
		else
		{
			wait(&status);
			printf("This is the parent process ID: %d\n", getppid());
			printf("6 %s\n",argV[0]);
		}
	child_count++;
	}
	free(buffer);
	return (0);
}
