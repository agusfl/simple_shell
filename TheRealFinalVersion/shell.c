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

char *_realpath(char **tokenized_input)
{
	int i = 0, x = 0;
	char *file_path = NULL;
	char **path = NULL;
	struct stat st;

	path = _getpath;
	while (path[i] != NULL)
	{
		file_path = calloc(3, (sizeof(char) *
		((_strlen(path[i])) + (_strlen(tokenized_input[x])) + 2)));
		
		if (file_path == NULL)
		{
			free(path);
			return (NULL);
		}

		_strcat(file_path, path[i]);
		_strcat(file_path, "/");
		_strcat(file_path, tokenized_input[x]);

		printf("CCCCCC %s\n", file_path);

		if (stat(file_path, &st) == 0)
		{
			free(path);
			return (file_path);
		}
		i++;
	free(file_path);
	}
	write(STDOUT_FILENO, tokenized_input[0], _strlen(tokenized_input[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
	free(path);
	return (NULL);
}

void _execute_command(char **tokenized_input)
{
    pid_t child;
    struct stat st;
    int status, succes = 0;
    char *command = NULL, **path;

	path = _getpath();

    if (tokenized_input[0] != NULL)
    {
        if (_isletter(tokenized_input[0][0]) == 1)
        {
            command = tokenized_input[0];
			printf("AAAAA%s\n", command);
            tokenized_input[0] = _realpath(tokenized_input);
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