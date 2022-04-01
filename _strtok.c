#include "main.h"

/**
 *
 **/
int main (void)
{
	char *str, token, array[];
	char separator[2] = " ";
	int i = 0, length;

	str = _getline();

	array = malloc(_strlen(str) * sizeof(char));

	length = sizeof(array)/sizeof(array[0]);



	token = strtok(str, separator);

	while (token != NULL)
	{
		printf ("%s\n", token);
		array[i] = token;
		token = strtok (NULL, separator);
		i++;
	}

	return (0);
}

