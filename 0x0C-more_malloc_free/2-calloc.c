#include "main.h"
#include <stdlib.h>
/**
 * _calloc - a function that allocates memory for an array.
 * @nmemb: the number of elements.
 * @size: size of bytes.
 *
 * Return: pointer to the allocated memory.
 * if nmemb or size is 0, returns NULL.
 * if malloc fails, return NULL.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int a;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	for (a = 0; a < (nmemb * size); a++)
	{
		p[a] = 0;
	}
	return (p);
}
