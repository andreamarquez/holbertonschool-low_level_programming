#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers, followed by a separator.
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
		return;

	last_position = number - 1;

	/*
	* Initialize the variable arguments with va_start.
	*/
	va_start(arguments, number);


	/* iterate through arguments and sum them using */
	/* the va_arg macro */
	for (counter = 0; counter < number; counter++)
	{
		next_arg = va_arg(arguments, int);
		printf("%d", next_arg);
		if (separator != NULL && (counter < last_position))
			printf("%s", separator);
	}
	printf("\n");

	/* Clean up the va_list */
	va_end(arguments);
}
