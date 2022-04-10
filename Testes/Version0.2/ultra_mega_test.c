#include "../main.h"

int main(int __attribute__((unused)) argc, char __attribute__((unused)) **argv)
{
	char *str = NULL, **array = NULL, *envv = "env";
	int space = 0, status = 0;
	pid_t child;
	char *env[] = {NULL};

	while (1) /* infinite while --> kill with exit or ctrl + d */
	{
		signal(SIGINT, _ctrl_c); /*ctrl c - ignore and make a break line*/
		if (isatty(STDIN_FILENO) == 1) /* If it is 1 the interactive mode is on */
			write(1, "$ ", 2); /* 1 is equal to standard output (pantalla) */

		str = _getline();
		space = spaces(str);
		if (ign_spaces_break(str) != 1)/*Ignorar espacios y saltos de linea*/
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

		if (_isletter(str[0]) == 0) /*No es una letra, es ruta, ejecuta de one*/
		{
			_excecute(str);
		}
		else /*Es una letra, llama a path*/
		{
			Concatena el input con cada token del path tokenizado y se lo pasa a excecute
		}
	}
	return (0);
}
