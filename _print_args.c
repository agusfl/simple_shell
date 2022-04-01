#include "main.h"

/**
 *  * main - function to print a command line without using the argument argc
 *   * @argc: argument counter (unused)
 *    * @argv: arguments vector
 *     * Return: number of arguments
 *      */

int _print_args(int __attribute__((unused)) argc, char *argv[])
{
	int i;
	while (argv[i] != NULL)
	{
		printf("%s\n --->", argv[i]);
		i++;
	}

	return (i);
}
