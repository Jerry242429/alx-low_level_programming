#include "main.h"
/**
 * _memcpy - which is a function that copies memory area
 * @dest: memory where information is stored
 * @src: memory whre copy is made
 * @n: number of bytes
 *
 * Return: copied memory with n byted altered
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int g = 0;
	int m = n;

	for (; g < m; g++)
	{
		dest[g] = src[g];
		n--;
	}
	return (dest);
}
