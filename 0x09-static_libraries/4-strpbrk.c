#include "main.h"
/**
 * _strpbrk -A program  Entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */
char *_strpbrk(char *s, char *accept)
{
	int p;

	while (*s)
	{
		for (p = 0; accept[p]; p++)
		{
			if (*s == accept[p])
			{
				return (s);
			}
		}

	s++;
	}
	return ('\0');
}
