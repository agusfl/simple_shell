#include "main.h"

/**
 * main - shell implementation
 * Return: 0 if success
 */

int main(void)
{
	char *input = NULL,*envv = "env", **tokenized_input = NULL, **path;
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
		tokenized_input = _strtok(input, space);

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

		_execute_command(tokenized_input);
		free(tokenized_input);
	}
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
			_free(1, command);
			return (realpath);
		}
	}

	_free(1, realpath);
	_free(1, command);
	return (NULL);
}

void _execute_command(char **tokenized_input)
{
    pid_t child;
    struct stat st;
    int status, succes = 0;
    char *command = NULL;

    if (tokenized_input[0] != NULL)
    {
        if (_isletter(tokenized_input[0][0]) == 1)
        {
            command = tokenized_input[0];
			printf("AAAAA%s\n", command);
            tokenized_input[0] = _realpath(tokenized_input, command);
			printf("BBBBB%s\n", tokenized_input[0]);
            if (tokenized_input[0] == NULL)
            {
                free(tokenized_input[0]);
                return;
            }
            succes = 1;
        }
        if (stat(tokenized_input[0], &st) == 0)
        {
            child = fork();
            if (child == 0)
            {
                if (execve(tokenized_input[0], tokenized_input, environ) == -1)
                {
                    perror(tokenized_input[0]);
                    free(tokenized_input[0]);
                    free(tokenized_input);
                    exit(-1);
                }
            }
            else
                wait(&status);
                
            if (succes == 1)
                free(tokenized_input[0]);
        }
        else
        {
            write(STDOUT_FILENO, tokenized_input[0], _strlen(tokenized_input[0]));
            write(STDOUT_FILENO, ": not found\n", 12);
        }
    }
}