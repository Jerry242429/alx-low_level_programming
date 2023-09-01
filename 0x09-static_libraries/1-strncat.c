#include "main.h"
/**
 * _strncat - a function that concatinates two integers
 * Using no more than n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int p;
	int m;

	p = 0;
	while (dest[p] != '\0')
	{
		p++;
	}
	m = 0;
	while (m < n && src[m] != '\0')
	{
		dest[p] = src[m];
		p++;
		m++;
	}
	dest[p] = '\0';
	return (dest);
}
