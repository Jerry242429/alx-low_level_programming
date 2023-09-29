#include  "main.h"

/**
 * get_endianness - function that checks the endianness.
 *
 * Return: 0 if  big endian, 1 if little endian
 *
 */


int get_endianness(void)
{
	unsigned int b = 1;
	char *e;

	e = (char *) &b;
	return ((int)*e);
}
