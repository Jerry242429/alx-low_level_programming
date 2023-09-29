#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointing to a string of 0 and 1 chars
 * Return: unsigned int with decimal value of binary number
 *
 */

unsigned int binary_to_uint(const char *b)
{
	int c;
	unsigned int n = 0;

	if (!b)
	{
		return (0);
	}
	for (c = 0; b[c] != '\0'; c++)
	{
		if (b[c] != '0' && b[c] != '1')
		{
			return (0);
		}
	}
	for (c = 0; b[c] != '\0'; c++)
	{
		n <<= 1;
		if (b[c] == '1')
			n += 1;
	}
	return (n);
}
