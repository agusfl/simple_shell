#include "main.h"

int main(void)
{
	char *str = NULL, **array = NULL, *envv = "env", **path = NULL, *realpath = NULL;
	int space = 0, status = 0;
	pid_t child;
	char *env[] = {NULL};

	while (1) 
	{
		signal(SIGINT, _ctrl_c); 
		if (isatty(STDIN_FILENO) == 1) 
			write(1, "$ ", 2); 

		str = _getline();
		space = spaces(str);
		str = convert_tab_space(str);

		if (ign_spaces_break_tab(str) != 1)
		{
			_free(1, str);
			continue;
		}

		if (_strcmp(str, envv) == 0)
		{
			print_env();
			_free(1, str);
			continue;
		}

		array = _strtok(str, space);//input tokenizado
		path = _getpath();
		realpath = _realpath(path, str);

		child = fork();
		if (child == -1)
		{
			perror("Error while creating a child process");
			exit(4);
		}
		if (child == 0) /*if it is 0 means that is the child process */
		{
			if (execve(realpath[0], realpath, env) == -1)
			{
				perror(NULL); /*Con esto ya devuelve el mensaje por default*/
				_free(1, str), _free(1, array); /*In case of error free allocated memory*/
				return (0);
			}
		}
		else /* parent process - waits for the child process to finish */
			wait(&status);
		_free(1, str), _free(1, array);
	}
	return (0);
}

/**
 * _realpath - asd
 * @tokenized_input: asd
 * @command: asd
 * Return: asd
 **/
char *_realpath(char **tokenized_input, char *command)
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