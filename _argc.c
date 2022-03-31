#include <stdio.h>

int main(int __attribute__((unused)) argc, char *argv[])
{
	int i;
	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}

	return (i);
}
