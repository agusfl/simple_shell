#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	while (argv[i] != NULL)	
		i++;

	printf("%d", i);
	return (i);
}
