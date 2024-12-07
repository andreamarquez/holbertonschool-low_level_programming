#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

void copy_textfile(char *file_from, char *file_to);
void exit_program(int number, char *workfile);

/**
 * main - Entry point of application that copies the content of a file
 * @ac: Count of arguments
 * @av: List of arguments
 *
 * Return: Always 0 (Success)
 * If the count of arguments is incorrect, exits the program with code 97
 * If cannot read the origin file, exits with code 98
 * If cannot create or write into the destiny file, exits with code 99
 * If cannot close a file descriptor, exits with code 100
 */
int main(int ac, char **av)
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_textfile(av[1], av[2]);

	return (0);
}

/**
 * copy_textfile - Copies from text file to another
 * @file_from: File from copy the information
 * @file_to: File where to copy the information
 *
 * Description: Copies the information from one file to another
 * If the file where to copy already exist, it truncates it and does not
 *  change it permissions. If not, create with permissions rw-rw-r--
 * If cannot read the file_from file, exits with code 98
 * If cannot create or write into file_to file, exits with code 99
 * If cannot close a file descriptor, exits with code 100
 *
 * Return: Nothing
 */
void copy_textfile(char *file_from, char *file_to)
{
	int fst, fe, el1, el2, c = 1;
	char buffer[1024];

	fst = open(file_from, O_RDONLY);
	if (fst == -1)
		exit_program(98, file_from);

	fe = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fe == -1)
		close(fst), exit_program(99, file_to);

	while (c)
	{
		el1 = read(fst, buffer, 1024);
		if (el1 == -1)
		{
			close(fst), close(fe);
			exit_program(98, file_from);
		}
		el2 = write(fe, buffer, el1);
		if (el2 == -1)
		{
			close(fst), close(fe);
			exit_program(99, file_to);
		}
		if (el2 < 1024)
			c = 0;
	}
	el1 = close(fst), el2 = close(fe);
	if (el1 == -1 || el2 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", (el1 == -1 ? fst : fe));
		exit(100);
	}
}

/**
 * exit_program - Exits the program and send a message according to the error
 * @number: Number of error
 * @workfile: Name fo the file that produces the error
 *
 * Return: Nothing
 */
void exit_program(int number, char *workfile)
{
	switch (number)
	{
	case 98:
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", workfile);
		break;
	case 99:
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", workfile);
		break;
	case 100:
		dprintf(STDERR_FILENO, "Error: Can't close fd %s\n", workfile);
		break;
	}
	exit(number);
}
