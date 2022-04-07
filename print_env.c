#include "main.h"

/**
 * print_env - print environmental variables
 * Return: 0 if success
 */

int print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	/*environ is the global variable and was declared in the main.h*/
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		/*print in standard outpu the environ variable*/
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
