#include "main.h"
/**
 * _strspn - Program Entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int m = 0;
	int r;

	while (*s)
	{
		for (r = 0; accept[r]; r++)
		{
			if (*s == accept[r])
			{
				m++;
				break;
			}
			else if (accept[r + 1] == '\0')
				return (m);
		}
		s++;
	}
	return (m);
}
