#include "main.h"

/**
 * create_file -  function that creates a file
 * @filename: the name of the file to be created
 * @text_content: NULL terminated string to write to file
 * Return: 1 on sucess , -1 on failure
 *
 */

int create_file(const char *filename, char *text_content)
{

	int f, nl, re;

	if (filename == NULL)
	{
		return (-1);
	}
	if (text_content !=  NULL)
	{
		for (re = 0; text_content[re];)
			re++;
	}
	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	nl =  write(f, text_content, re);

	if (f == -1 || nl == -1)
	{
		return (-1);
	}
	close(f);
	return (1);
}
