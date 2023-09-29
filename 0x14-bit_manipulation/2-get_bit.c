#include "main.h"

/**
 * get_bit -  returns the value of a bit at a given index
 * @n: unsigned long int input
 * @index: index at which to check bit
 * Return: value of bit
 *
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int a, c;

	if (index > (sizeof(unsigned long int) * 8 - 1))
	{

		return (-1);
	}
	a = 1 << index;
	c = n & a;
	if (c == a)
	{
	return (1);
	}
	return (0);
}
