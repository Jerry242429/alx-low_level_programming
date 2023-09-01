#include "main.h"
/**
 * _memset - program that fills a block of memory with specific value
 * @s: starting address of memory to be  filled
 * @b: the desired value
 * @n: the number of bytes changed
 *
 * Return: change array with the new value for n bytes
 */
char *_memset(char *s, char b, unsigned int n)
{
	int a = 0;

	for (; n > 0; a++)
	{
		s[a] = b;
		n--;
	}
	return (s);
}
