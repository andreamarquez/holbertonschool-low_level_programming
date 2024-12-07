#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * open_file - Opens a file for reading.
 * @filename: The name of the file to open.
 *
 * Return: The file descriptor, or -1 if an error occurred.
 */
int open_file(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
	}
	return (fd);
}

/**
 * read_file - Reads from a file into a buffer.
 * @fd: The file descriptor.
 * @buffer: The buffer to read into.
 * @letters: The number of letters to read.
 *
 * Return: The number of bytes read, or -1 if an error occurred.
 */
ssize_t read_file(int fd, char *buffer, size_t letters)
{
	ssize_t bytes_read;

	bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1)
	{
		perror("Error reading file");
	}
	return (bytes_read);
}

/**
 * write_output - Writes a buffer to the standard output.
 * @buffer: The buffer to write.
 * @bytes_read: The number of bytes to write.
 *
 * Return: The number of bytes written, or -1 if an error occurred.
 */
ssize_t write_output(const char *buffer, ssize_t bytes_read)
{
	ssize_t bytes_written;

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1)
	{
		perror("Error writing to standard output");
	}
	return (bytes_written);
}

/**
 * read_textfile - Reads a text file and prints it to the POSIX
 * standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print,
 *         or 0 if the file cannot be opened or read, or if filename is NULL,
 *         or if write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (filename == NULL)
	{
		return (0);
	}
	fd = open_file(filename);
	if (fd == -1)
	{
		return (0);
	}
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	bytes_read = read_file(fd, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	bytes_written = write_output(buffer, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	free(buffer);
	close(fd);
	return (bytes_written);
}
