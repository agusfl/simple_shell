#include "main.h"

/**
 *
 *
 *
 *
 *
 **/
void _ctrl_c(int signal)
{
	if (signal == SIGINT)
		write (1,"\n$ ",3);
}
