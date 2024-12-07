#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

#define BUFFER_SIZE 1024

void open_file(
	const char *filename,
	int *fd, int flags, mode_t mode, int error_code);
void copy_content(int fd_from, int fd_to, const char *file_to);
void close_file(int fd, int error_code);

/**
 * main - Copies the content of one file to another.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 *
 * Return: 0 on success, or exits with an error code on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
		print_error_and_exit("Usage: cp file_from file_to\n", 97, NULL);

	if (argv[1] == NULL || argv[2] == NULL)
		print_error_and_exit("Error: Invalid file name\n", 97, NULL);

	if (strcmp(argv[1], argv[2]) == 0)
		print_error_and_exit(
			"Error: Source and destination files are the same\n",
			97,
			NULL);

	open_file(argv[1], &fd_from, O_RDONLY, 0, 98);
	open_file(argv[2], &fd_to, O_WRONLY | O_CREAT | O_TRUNC, 0664, 99);

	copy_content(fd_from, fd_to, argv[2]);

	close_file(fd_from, 100);
	close_file(fd_to, 100);

	return (0);
}

/**
 * open_file - Opens a file with the specified flags and mode.
 * @filename: The name of the file to open.
 * @fd: Pointer to an integer where the file descriptor will be stored.
 * @flags: The flags to use when opening the file.
 * @mode: The mode to use when opening the file.
 * @error_code: The error code to use if the file cannot be opened.
 *
 * This function attempts to open the file specified by @filename with the
 * given @flags and @mode. If the file cannot be opened, it calls
 * print_error_and_exit with the provided @error_code and @filename.
 */
void open_file(
	const char *filename,
	int *fd, int flags, mode_t mode, int error_code)
{
	*fd = open(filename, flags, mode);
	if (*fd == -1)
		print_error_and_exit("Error: Can't open file %s\n", error_code, filename);
}

/**
 * copy_content - Copies the content from one file descriptor to another.
 * @fd_from: The file descriptor to read from.
 * @fd_to: The file descriptor to write to.
 * @file_to: The name of the destination file (used for error messages).
 *
 * This function reads data from the file descriptor `fd_from` and writes it
 * to the file descriptor `fd_to` using a buffer of size `BUFFER_SIZE`. If an
 * error occurs during reading or writing, the function closes both file
 * descriptors and exits with an error message.
 *
 * Errors:
 * - If writing to `fd_to` fails, the function prints an error message and
 *   exits with status code 99.
 * - If reading from `fd_from` fails, the function prints an error message and
 *   exits with status code 98.
 */
void copy_content(int fd_from, int fd_to, const char *file_to)
{
	char buffer[BUFFER_SIZE];
	int read_bytes, written_bytes;
	int total_written;

	while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		total_written = 0;

		while (total_written < read_bytes)
		{
			written_bytes = write(
				fd_to, buffer + total_written, read_bytes - total_written);
			if (written_bytes == -1)
			{
				close(fd_from);
				close(fd_to);
				print_error_and_exit("Error: Can't write to %s\n", 99, file_to);
			}
			total_written += written_bytes;
		}
	}

	if (read_bytes == -1)
	{
		close(fd_from);
		close(fd_to);
		print_error_and_exit("Error: Can't read from file %s\n", 98, file_to);
	}
}

/**
 * close_file - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to be closed.
 * @error_code: The error code to be used
 * in the error message if closing fails.
 *
 * Description: This function attempts to close the file descriptor specified
 * by @fd. If the close operation fails, it calls the function
 * print_error_and_exit with an error message and the provided @error_code.
 */
void close_file(int fd, int error_code)
{
	if (close(fd) == -1)
		print_error_and_exit("Error: Can't close fd %d\n", error_code, NULL);
}

/**
 * print_error_and_exit - Prints an error message to stderr and exits.
 * @message: The error message to print.
 * @exit_code: The exit code to use.
 * @filename: The file name to include in the error message.
 */
void print_error_and_exit(
	const char *message, int exit_code, const char *filename)
{
	if (filename)
		dprintf(STDERR_FILENO, message, filename);
	else
		dprintf(STDERR_FILENO, message, exit_code);
	exit(exit_code);
}
