#include "main.h"
#include <stdlib.h>
/**
 * array_range - a function creates an array of integers.
 * @min: minimum input value
 * @max: maximum input value
 *
 * Return: pointer to the newly created array.
 */
int *array_range(int min, int max)
{
	int *r;
	int a;

	if (min > max)
	{
		return (NULL);
	}
	r = malloc(sizeof(*r) * ((max - min) + 1));
	if (r == NULL)
	{
		return (NULL);
	}
	for (a = 0; min <= max; a++, min++)
	{
		r[a] = min;
	}
	return (r);
}
