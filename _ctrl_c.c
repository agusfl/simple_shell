#include "main.h"

/**
 * _ctrl_c - function that ignores ctrl + c input from keybord and prints a
 * break line with $ symbol.
 * @sig: signal to ignore
 **/

void _ctrl_c(int sig)
{
	if (sig == SIGINT)
		write(1, "\n$ ", 3);
}
