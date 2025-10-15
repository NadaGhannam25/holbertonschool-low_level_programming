#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error_exit(int code, const char *msg, const char *file, int fd)
{
	if (fd != -1)
		close(fd);
	if (file)
		dprintf(STDERR_FILENO, msg, file);
	else
		dprintf(STDERR_FILENO, "%s", msg);
	exit(code);
}

/**
 * main - Copies content of one file to another.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char buffer[BUF_SIZE];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n", NULL, -1);

	from = open(argv[1], O_RDONLY);
	if (from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1], -1);

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
		error_exit(99, "Error: Can't write to %s\n", argv[2], from);

	while ((r = read(from, buffer, BUF_SIZE)) > 0)
	{
		w = write(to, buffer, r);
		if (w != r)
			error_exit(99, "Error: Can't write to %s\n", argv[2], from);
	}

	if (r == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1], from);

	if (close(from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", NULL, from);
	if (close(to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", NULL, to);

	return (0);
}
