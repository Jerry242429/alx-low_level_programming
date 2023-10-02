#include "main.h"

/**
 * append_text_to_file - function that appends text at the end of a file
 * @filename: the name of the file
 * @text_content: which is NULL string
 * Return: 1 if the file exists and -1
 *
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int nuletter;
	int r;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		return (-1);
	}
	if (text_content)
	{
		for (nuletter = 0; text_content[nuletter];)
			nuletter++;
		r = write(fd, text_content, nuletter);
		if (r == -1)
		{
			return (-1);

		}


	}
	close(fd);
	return (1);
}
