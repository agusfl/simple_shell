#include "main.h"

/**
 * main - shell implementation
 * Return: 0 if success
 **/

int main(void)
{
	char *input = NULL, *envv = "env", **path = NULL, **tokenized_input = NULL;
	int space = 0;

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
		tokenized_input = _strtok(input, space);
		if (tokenized_input == NULL)
		{
			exit(1);
		}
		path = _getpath();
		if (_isletter(tokenized_input[0][0]) == 1)
		{
			_execute_command(path, tokenized_input);
		}
		else
		{
			_execute_path(tokenized_input);
		}
	}
	_free_path(2, path), _free(2, tokenized_input), _free(1, input);
	return (0);
}
