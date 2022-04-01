#include "main.h"

/**
 *
 **/
int main (void)
{
	char str[100] = "Numbers: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.";
	char separator[2] = ",";
	char *token;
	char *array[500];
	int i = 0, length;

	length = sizeof(array)/sizeof(array[0]);

	token = strtok(str, separator);

	while (token != NULL)
	{
		printf ("%s\n", token);
		array[i] = token;
		token = strtok (NULL, separator);
		i++;
	}
	printf("====================================================\n");
	for (i = 0; i < length; i++)
	{
		printf("%s\n",array[i]);

		if (array[i] == NULL || array[i] == 0)
			exit;
	}

	return (0);
}

