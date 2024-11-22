#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_strings - Prints strings, followed by a separator and
 * a new line.
 * @separator: The string to be printed between strings.
 * @number: The number of strings passed to the function.
 * If the separator is NULL, it will not be printed between numbers.
 * If one of the string is NULL, print (nil) instead.
 */
void print_strings(const char *separator, const unsigned int number, ...)
{
	unsigned int counter;
	char *next_arg;
	unsigned int last_position;
	va_list arguments;

	/* Checks if the number is 0 */
	if (number == 0)
	{
		printf("\n");
		return;
	}

	last_position = number - 1;

	if (separator == NULL)
		separator = "";

	/*
	 * Initialize the variable arguments with va_start.
	 */
	va_start(arguments, number);

	/*
	 * This code snippet iterates through a list of
	 * variadic arguments and prints them.
	 */
	for (counter = 0; counter < last_position; counter++)
	{
		next_arg = va_arg(arguments, char *);
		if (next_arg == NULL)
			next_arg = "(nil)";
		printf("%s%s", next_arg, separator);
	}
	next_arg = va_arg(arguments, char *);
	if (next_arg == NULL)
		next_arg = "(nil)";
	printf("%s\n", next_arg);

	/* Clean up the va_list */
	va_end(arguments);
}
