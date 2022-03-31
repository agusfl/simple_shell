#include "main.h"

/**
 *
 *
 *
 *
 *
 **/
int _strtok (void)
{
	int i, x;
	char *str;


}

/**
 *
 *
 *
 *
 *
 *
 **/
unsigned int is_delim(char c, char *delim)
{
	while(*delim != '\0')
	{
		if(c == *delim)
			return 1;

		delim++;
	}

	return 0;
}
