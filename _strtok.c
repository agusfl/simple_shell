#include "main.h"

/**
 *
 **/
int _strtok (void)
{
	token = strtok(buffer, delimiter);

	while (token != NULL)
	{
		toks[counter] = strdup(token);
		token = strtok(NULL, delimiter);
		Counter++;
	}

	toks[counter] = token;	
}
Z