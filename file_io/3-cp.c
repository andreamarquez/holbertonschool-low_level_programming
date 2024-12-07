#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handle_error(int exit_code, const char *message, const char *filename);
void copy_file_content(const char *source_file, const char *dest_file);

/**
 * main - Entry point of application that copies the content of a file
 * @argc: Count of arguments
 * @argv: List of arguments
 *
 * Return: Always 0 (Success)
 * If the count of arguments is incorrect, exits the program with code 97
 * If cannot read the origin file, exits with code 98
 * If cannot create or write into the destination file, exits with code 99
 * If cannot close a file descriptor, exits with code 100
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file_content(argv[1], argv[2]);

	return (0);
}

/**
 * copy_file_content - Copies content from one file to another
 * @source_file: File to copy the information from
 * @dest_file: File to copy the information to
 *
 * Description: Copies the information from one file to another
 * If the destination file already exists, it truncates it and does not
 * change its permissions. If not, it creates it with permissions rw-rw-r--.
 * If it cannot read the source file, exits with code 98.
 * If it cannot create or write into the destination file, exits with code 99.
 * If it cannot close a file descriptor, exits with code 100.
 */
void copy_file_content(const char *source_file, const char *dest_file)
{
	int source_fd, dest_fd, bytes_read, bytes_written;
	char buffer[1024];

	source_fd = open(source_file, O_RDONLY);
	if (source_fd == -1)
	{
		handle_error(98, "Error: Can't read from file", source_file);
	}

	dest_fd = open(dest_file, O_WRONLY | O_CREAT, 0664);
	if (dest_fd == -1)
	{
		close(source_fd);
		handle_error(99, "Error: Can't write to", dest_file);
	}

	if (ftruncate(dest_fd, 0) == -1)
	{
		close(source_fd);
		close(dest_fd);
		handle_error(99, "Error: Can't write to", dest_file);
	}

	while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close(source_fd);
			close(dest_fd);
			handle_error(99, "Error: Can't write to", dest_file);
		}
	}
	if (bytes_read == -1)
	{
		close(source_fd);
		close(dest_fd);
		handle_error(98, "Error: Can't read from file", source_file);
	}

	if (close(source_fd) == -1)
	{
		close(dest_fd);
		handle_error(100, "Error: Can't close fd", source_file);
	}

	if (close(dest_fd) == -1)
	{
		handle_error(100, "Error: Can't close fd", dest_file);
	}
}

/**
 * handle_error - Handles errors by printing a message and exiting
 * @exit_code: The exit code to use
 * @message: The error message to print
 * @filename: The filename associated with the error
 */
void handle_error(int exit_code, const char *message, const char *filename)
{
	dprintf(STDERR_FILENO, "%s %s\n", message, filename);
	exit(exit_code);
}
