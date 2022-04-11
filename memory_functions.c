#include "main.h"

/**
 * _free - function to free 1 pointer or a double pointer
 * @toknized: indicates if it is a 1 pointer to be freed or a double pointer
 **/

void _free(char **tokenized)
{
	char **dptr = NULL;
	int i = 0;

	dptr = tokenized;
	if (dptr == NULL)
	{
		return;
	}

	for (i = 0; dptr[i + 1] != NULL; i++)
	{
		free(dptr[i]);
	}
	free(dptr);
}

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

/**
 * _free_path - function to free 1 pointer or a double pointer
 * @path: indicates if it is a 1 pointer to be freed or a double pointer
 **/

void _free_path(char **path)
{
	char **dptr = NULL;
	int i = 0;

	dptr = path;
	if (dptr == NULL)
	{
		return;
	}

	for (i = 0; dptr[i] != NULL; i++)
	{
		free(dptr[i]);
	}
	free(dptr);
}
