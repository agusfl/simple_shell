#include "main.h"

/**
 * main - shell implementation
 * Return: 0 if success
 **/

int main(void)
{
	char *input = NULL, *envv = "env", **path = NULL, **tokenized_input = NULL;
	int space = 0, status = 0;
	pid_t child;

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
			free(input);
			continue;
		}
		if (_strcmp(input, envv) == 0)
		{
			print_env();
			free(input);
			continue;
		}
		path = _getpath();
		tokenized_input = _strtok(input, space);
		if (_isletter(tokenized_input[0][0]) == 1)
		{
			tokenized_input[0] = _realpath(path, tokenized_input[0]);
			child = fork();
			if (child == -1)
			{
				perror(NULL);
				_free(2, path), _free(2, tokenized_input);
				exit(4);
			}
			if (child == 0) /*if it is 0 means that is the child process */
			{
				if (execve(tokenized_input[0], tokenized_input, environ) == -1)
				{
					perror(NULL); /*Con esto ya devuelve el mensaje por default*/
					break;
				}
			}
			else /* parent process - waits for the child process to finish */
			{
                                wait(&status);
                                _free_path(2, path), _free(2, tokenized_input), free(input);
            }
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
				if (execve(tokenized_input[0], tokenized_input, environ) == -1)
				{
					perror(NULL); /*Con esto ya devuelve el mensaje por default*/
					break;
				}
			}
			else /* parent process - waits for the child process to finish */
			{
				wait(&status);
				_free_path(2, path), _free(2, tokenized_input), free(input);
			}
		}
	}
	 _free_path(2, path), _free(2, tokenized_input), free(input);
	return (0);
}