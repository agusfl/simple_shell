#include "main.h"

int main(void)
{
	char *input = NULL, *realpath = NULL,  *envv = "env", **path = NULL, **tokenized_input = NULL;
	int space = 0, status = 0;
	pid_t child;
	char *env[] = {NULL};

	while (1) 
	{
		signal(SIGINT, _ctrl_c); 
		if (isatty(STDIN_FILENO) == 1) 
			write(1, "$ ", 2); 

		input = _getline();
		space = spaces(input);
		input = convert_tab_space(input);
        path = _getpath()
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

		if (_isletter(str) == 1)
		{
			realpath = _realpath(path, tokenized_input[0]);

			child = fork();
			if (child == -1)
			{
				perror("Error while creating a child process");
				exit(4);
			}
			if (child == 0) /*if it is 0 means that is the child process */
			{
				if (execve(realpath, tokenized_input, environ) == -1)
				{
					perror(NULL); /*Con esto ya devuelve el mensaje por default*/
					/*free*/
					return;
				}
			}
			else /* parent process - waits for the child process to finish */
				wait(&status);	
		}
		 
		
		
	}
	return (0);
}

/**
 * _realpath - asd
 * @tokenized_input: asd
 * @command: asd
 * Return: asd
 **/
char *_realpath(char **path, char *command)
{
    char *realpath = NULL;
    struct stat st;
	int i = 0;

	for (i = 0; tokenized_input[i]; i++)
	{
		realpath = _strcat(tokenized_input[i], command);
		if (stat(realpath, &st) == 0)
		{
			return (realpath); 
		}
	}

	free(realpath);
	free(command);
	return (NULL);
}

/*
void _execute(char **tokenized_input)
{
	int status = 0, back = 0;
	struct stat st;
	pid_t child;

	if (tokenized_input[0] != NULL)
	{
		
	}
}
*/