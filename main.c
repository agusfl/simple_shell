#include "main.h"

int main(void)
{
	int i;
	char *puto;

	puto = _getline();
	i = spaces();

	printf("spaces: %d\n", i);
	_free(1, puto);

	return (0);
}
