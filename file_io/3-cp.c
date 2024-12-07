#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * print_error_and_exit - Prints an error message to stderr and exits.
 * @message: The error message to print.
 * @exit_code: The exit code to use.
 */
void print_error_and_exit(const char *message, int exit_code)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}

/**
 * main - Copies the content of one file to another.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 *
 * Return: 0 on success, or exits with an error code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, read_bytes, written_bytes;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		print_error_and_exit("Usage: cp file_from file_to", 97);
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error_and_exit("Error: Can't read from file", 98);
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error_and_exit("Error: Can't write to file", 99);
	}
	while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		written_bytes = write(fd_to, buffer, read_bytes);
		if (written_bytes != read_bytes)
		{
			close(fd_from);
			close(fd_to);
			print_error_and_exit("Error: Can't write to file", 99);
		}
	}
	if (read_bytes == -1)
	{
		close(fd_from);
		close(fd_to);
		print_error_and_exit("Error: Can't read from file", 98);
	}
	if (close(fd_from) == -1)
		print_error_and_exit("Error: Can't close fd", 100);

	if (close(fd_to) == -1)
		print_error_and_exit("Error: Can't close fd", 100);
	return (0);
}
