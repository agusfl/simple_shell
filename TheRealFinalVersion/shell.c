#include "main.h"

/**
 * main - shell implementation
 * Return: 0 if success
 */

int main(void)
{
	char *input = NULL, /**realpath = NULL,*/  *envv = "env", **path = NULL, **tokenized_input = NULL;
	int space = 0, status = 0;
	pid_t child;
	struct stat st;

	while (1)
	{
		signal(SIGINT, _ctrl_c);
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		input = _getline();
		space = spaces(input);
		input = convert_tab_space(input);
		if (ign_spaces_break_tab(input) != 1)
		{
			_free(1, input);
			continue;
		}
		if (_strcmp(input, envv) == 0)
		{
			print_env();
			_free(1, input);
			continue;
		}
	
		tokenized_input = _strtok(input, space);
		if (_isletter(input[0]) == 1)
		{
			path = _getpath();
			input = _realpath(path, tokenized_input[0]);

			child = fork();
			if (child == -1)
			{
				perror("Error while creating a child process");
				exit(4);
			}
			if (child == 0) /*if it is 0 means that is the child process */
			{
				if (execve(input, tokenized_input, environ) == -1)
				{
					perror(NULL); /*Con esto ya devuelve el mensaje por default*/
					_free(1, input), _free(1, path), _free(1, tokenized_input);
					return (0);
				}
			}
			else /* parent process - waits for the child process to finish */
				wait(&status);
		_free(1, input), _free(1, path), _free(1, tokenized_input);
		}
		else
		{

			child = fork();
			if (child == -1)
			{
				perror("Error while creating a child process");
				exit(4);
			}
			if (child == 0) /*if it is 0 means that is the child process */
			{
				if (execve(input, tokenized_input, environ) == -1)
				{
					perror(NULL); /*Con esto ya devuelve el mensaje por default*/
					_free(1, input), _free(1, path), _free(1, tokenized_input);
					return (0);
				}
			}
			else /* parent process - waits for the child process to finish */
				wait(&status);
		}
	}
	return (0);
}

/**
 * _realpath - function to search path of command
 * @path: tokenaized path
 * @command: command to search
 * Return: string with the path of the command
 **/

char *_realpath(char **path, char *command)
{
	char *realpath = NULL;
	struct stat st;
	int i = 0;

	for (i = 0; path[i] != NULL; i++)
	{
		realpath = _strcat(path[i], command);

		if (stat(realpath, &st) == 0)
		{
			return (realpath);
		}
	}

	free(realpath);
	free(command);
	return (NULL);
}

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
		/*print in standard output the environ variable*/
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

/**
 * *convert_tab_space - function to convert tabs into spaces
 * @input: string to convert in case it has tabs ('\t')
 * Return: string converted or NULL.
 */

char *convert_tab_space(char *input)
{
	int i = 0;
	int x = 0;

	while (input[i] != '\0')
	{
		while (input[x] == '\t')
		{
			input[x] = ' ';
			x++;
		}
		i++;
		return (input);
	}
	return (NULL);
}
