#include "main.h"
/**
 * _strstr - A Program Entry point
 * @haystack: input value
 * @needle: input value
 * Return: Always 0 (Success)
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *p = haystack;
		char *e = needle;

		while (*p == *e && *e != '\0')
		{
			p++;
			e++;
		}
		if (*e == '\0')
		{
			return (haystack);
		}
	}
	return (0);
}
