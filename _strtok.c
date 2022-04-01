#include "main.h"

/**
 *
 **/
int _strtok (void)
{
	char *str, *token;
	char separator[2] = " ";
	int i = 0, length, size;

	str = _getline();

	size = spaces();

	char *array[size];

	length = sizeof(array)/sizeof(array[0]);

	token = strtok(str, separator);

	while (token != NULL)
	{
		printf ("%s\n", token);
		array[i] = token;
		token = strtok (NULL, separator);
		i++;
	}
	printf("====================================================\n"); /*Prueba, despues borrar */
	for (i = 0; i < length; i++)
	{
		printf("%s\n",array[i]);
	}

	return (0);
}

int spaces (void)
{
	char *str;
	int spaces, i = 0;

	str = _getline();

	while (str[i] != '\0')
	{

		if (str[i] == ' ')
			spaces++;

		i++;
	}
	spaces++;
	return (spaces);
}
