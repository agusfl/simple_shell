#include "main.h"

/**
 *
 *
 *
 **/
void _free(int n, ...)
{
	char *ptr;
	va_list valist;
	int i;

	va_start(valist,n);

	if (n == 1)
	{
		ptr = va_arg(valist, char *);
		if (ptr == NULL)
			return;
		free(ptr);
	}

	va_end(valist);
}

