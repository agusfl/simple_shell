#include "main.h"

/**
 *_calloc - allocates memory for an array
 *@nmemb: number of elements of the array
 *@size: size in bytes of the array
 *Return: pointer to the array or NULL if it fails
 **/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *mem_space;
	unsigned int i, limit = 0;

	limit = nmemb * size;

	if (limit <= 0)
		return (NULL);

	mem_space = malloc(limit);

	if (mem_space == NULL)
		return (NULL);

	for (i = 0; i < limit; i++)
		*((char *)mem_space + i) = 0;

	return (mem_space);
}
