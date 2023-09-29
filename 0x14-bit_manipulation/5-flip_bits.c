#include "main.h"

/**
 * flip_bits -the number of bits you would need to flip
 *
 * @n: the first number
 * @m: the second number
 * Return: number of bits
 *
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int b, count = 0;
	unsigned long int c;
	unsigned long int ex = n ^ m;

	for (b = 63; b >= 0; b--)
	{
		c = ex >> b;
		if (c & 1)
		{
			count++;
		}
	}
	return (count);
}
