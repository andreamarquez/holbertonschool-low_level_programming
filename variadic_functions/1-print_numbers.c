#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers, followed by a separator and
 * a new line.
 * @separator: The string to be printed between numbers.
 * @number: The number of integers passed to the function.
 * If the separator is NULL, it will not be printed between numbers.
 */
void print_numbers(const char *separator, const unsigned int number, ...)
{
	unsigned int counter;
	int next_arg;
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

	/* iThis code snippet iterates through a list of 
	variadic arguments and prints them. */
	
	for (counter = 0; counter < last_position; counter++)
	{
		next_arg = va_arg(arguments, int);
		printf("%d%s", next_arg, separator);
	}
	next_arg = va_arg(arguments, int);
	printf("%d\n", next_arg);

	/* Clean up the va_list */
	va_end(arguments);
}
