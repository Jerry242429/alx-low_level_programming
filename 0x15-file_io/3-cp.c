#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void check_FIO_status(int status, int file_d, char  *filename, char m);

/**
 * main - copy the content of file to another file
 * @argc: to be argument count variable
 * @argv: to be argument vector variable
 * Return: if on success 1, if not on exit
 *
 */

int main(int argc, char *argv[])
{
	int s, d;
	int cs, cd;
	int wrote, nread = 1024;
	char bu[1024];
	unsigned int m = S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	s = open(argv[1], O_RDONLY);
	check_FIO_status(s, -1, argv[1], 'o');
	d = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, m);
	check_FIO_status(d, -1, argv[2], 'W');
	while (nread == 1024)
	{
		nread = read(s, bu, sizeof(bu));
		if (nread == -1)
			check_FIO_status(-1, -1, argv[1], 'o');
		wrote = write(d, bu, nread);
		if (wrote == -1)
			check_FIO_status(-1, -1, argv[2], 'W');
	}
	cs = close(s);
	check_FIO_status(cs, s, NULL, 'C');
	cd = close(d);
	check_FIO_status(cd, d, NULL, 'C');
	return (0);
}

/**
 * check_I/O_status- that checks file whether opened or closed
 * @status: the file to be opend
 * @filename: the name of the file
 * @m: which is closing or opening
 * @file_d: file desrcriptor of the functiom
 * Return: void
 *
 */

void check_FIO_status(int status, int file_d, char *filename, char m)
{
	if (m == 'C' && status == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd%d\n", file_d);
		exit(100);
	}
	else if (m == 'W' && status == -1)
	{

		dprintf(STDERR_FILENO, "Error: cannot write to the %s\n", filename);
		exit(99);
	}
	else if (m == 'o' && status == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot be read from file %s\n", filename);
		exit(98);
	}
}
