#include "main.h"

/**
 * main - shell implementation
 * Return: 0 if success
 **/

int main(void)
{
	char *input = NULL, *envv = "env", **path = NULL, **tokenized_input = NULL;
	int space = 0;

	signal(SIGINT, _ctrl_c);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		input = _getline(), space = spaces(input), input = convert_tab_space(input);
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
			exit(0);
		path = _getpath();
		if (_isletter(tokenized_input[0][0]) == 1)
		{
			_execute_command(path, tokenized_input);
			if (space == 2)/*this means you send only a command without arguments*/
				free(input);
		}
		else
		{
			_execute_path(tokenized_input);
			if (space == 2)
				free(input);
		}
		_free(tokenized_input), _free_path(path);
	}
	free(input);
	return (0);
}
