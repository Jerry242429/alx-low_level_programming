#include "main.h"
/**
 * _strcat - that concatenates two strings
 * @dest: the input value
 * @src: the input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int a;
	int j;

	a = 0;
	while (dest[a] != '\0')
	{
		a++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[a] = src[j];
		a++;
		j++;
	}

	dest[a] = '\0';
	return (dest);
}
