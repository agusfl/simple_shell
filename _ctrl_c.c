#include "main.h"
/**
 *
 *
 *
 *
 *
 **/
void _ctrl_C(int signal)
{
	if (signal == SIGINT)
		write (1,"\n",1);
}
