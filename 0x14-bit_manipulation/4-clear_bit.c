#include "main.h"

/**
 * clear_bit -  sets the value of a bit to 0 at a given index
 * @n: parameter
 * @index: index of the bit
 * Return: 1 if success, -1 if error
 *
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int a;

	if (index > 63)
	{
		return (-1);
	}
	a = 1 << index;
	if (*n & a)
	{
		*n ^= a;
	}
	return (1);
}
