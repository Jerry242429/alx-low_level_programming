#include "main.h"
#include <stdlib.h>
/**
 * argstostr - main entry point
 * @ac: int input value
 * @av: double pointer array
 * Return: 0
 */
char *argstostr(int ac, char **av)
{
	int a, n, r = 0, m = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (a = 0; a < ac; a++)
	{
		for (n = 0; av[a][n]; n++)
			m++;
	}
	m += ac;

	str = malloc(sizeof(char) * m + 1);
	if (str == NULL)
		return (NULL);
	for (a = 0; a < ac; a++)
	{
	for (n = 0; av[a][n]; n++)
	{
		str[r] = av[a][n];
		r++;
	}
	if (str[r] == '\0')
	{
		str[r++] = '\n';
	}
	}
	return (str);
}
