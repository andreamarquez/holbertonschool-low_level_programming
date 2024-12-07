#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * main - Copies the content of one file to another.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 *
 * Return: 0 on success, or exits with an error code on failure.
 */
int main(int argc, char **argv)
{
	int fd_source, fd_dest, bytes_read, bytes_written, close_source, close_dest;
	char buffer[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	fd_source = open(argv[1], O_RDONLY);
	if (fd_source == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_dest == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	while ((bytes_read = read(fd_source, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_dest, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	close_source = close(fd_source);
	if (close_source == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_source), exit(100);
	close_dest = close(fd_dest);
	if (close_dest == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_dest), exit(100);

	return (0);
}
