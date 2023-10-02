#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

/**
 * read_textfile - that reads a text file and prints it to POSIX
 * @filename: the file name that read
 * @letters: number of letter that reads and prints
 * Return: the actual numbert of letter
 *
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_dscript;
	ssize_t lenw ;
	ssize_t lengthr;
	char *buff;

	if (filename == NULL)
	{
		return (0);
	}
	file_dscript = open(filename, O_RDONLY);
	if (file_dscript == -1)
	{
		return (0);
	}
	buff = malloc(sizeof(char) * letters);
	lengthr = read(file_dscript, buff, letters);
	lenw = write(STDOUT_FILENO, buff, lengthr);

	free(buff);
	close(file_dscript);
	return (lenw);
}
