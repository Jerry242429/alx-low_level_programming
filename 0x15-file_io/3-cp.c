#include <stdio.h>
#include <stdlib.h>
#include "main.h"

char *c_buffer(char *filef);
void c_file(int file_d);

/**
 * c_buffer - a function buffer it allocates 1024 bytes
 * @filef: the name of the file
 * Return: pointer to aloocated buffer
 *
 */

char *c_buffer(char *filef)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);
	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: can't write to %s\n", filef);
		exit(99);

	}
return (buf);

}

/**
 * c_file - close opened file using file_d
 * @file_d: the file descriptor to be closed
 */

void c_file(int file_d)
{
	int a;

	a = close(file_d);
	if (a == -1)
	{
	dprintf(STDERR_FILENO, "Error: can't close fd %d\n", file_d);	

		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count variable
 * @argv: argument variable vector
 * Return: if on sucess 0, otherwise return exit
 *
 */

int main(int argc, char *argv[])
{
	int s, d;
	int wrote, nread;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	buf = c_buffer(argv[2]);
	s = open(argv[1], O_RDONLY);
	nread = read(s, buf, 1024);
	d = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	do {
		if (s == -1 || nread == -1)
		{
			dprintf(STDERR_FILENO,  "Error: Can't read from %s\n",  argv[1]);

			free(buf);
			exit(98);
		}
		wrote = write(d, buf, nread);
		if (d  == -1 || wrote == -1)
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		nread = read(s, buf, 1024);
		d = open(argv[2], O_WRONLY | O_APPEND);
	} while (nread > 0);

	free(buf);
	c_file(s);
	c_file(d);

	return (0);
}
