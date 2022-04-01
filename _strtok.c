#include "main.h"

/**
 *
 **/
int main (void)
{
	char str[100] = "Numbers: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.";
	char separator[2] = ",";
	char *token;

	token = strtok(str, separator);

	while (token != NULL)
	{
		printf ("%s\n", token);
		
		token = strtok (NULL, separator);
	}

	return (0);
}

