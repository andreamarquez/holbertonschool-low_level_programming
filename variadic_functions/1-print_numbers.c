#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

void print_number(int number_to_print);
void print_separator(const char *separator);

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
	unsigned int last_position = number - 1;

	va_list arguments;

	/* Checks if the number is 0 */
	if (number == 0)
		return;

	/*
	* Initialize the variable arguments with va_start.
	*/
	va_start(arguments, number);


	/* iterate through arguments and sum them using */
	/* the va_arg macro */
	for (counter = 0; counter < number; counter++)
	{
		next_arg = va_arg(arguments, int);
		print_number(next_arg);
		if (separator != NULL && (counter < last_position))
			print_separator(separator);
	}

	/* Clean up the va_list */
	va_end(arguments);
}


/**
 * print_number - Prints a given number.
 * @number_to_print: The number to be printed.
 *
 * This function takes an integer as input and prints it
 * to the standard output.
 */
void print_number(int number_to_print)
{
	unsigned int num;

	if (number_to_print < 0)
	{
		_putchar('-');
		num = number_to_print * -1;
	}
	else
	{
		num = number_to_print;
	}

	/* Recursively print each digit */
	if (num / 10)
	{
		print_number(num / 10);
	}
	_putchar((num % 10) + '0');
}

/**
 * print_separator - Prints the separator string.
 * @separator: The string to be printed.
 */
void print_separator(const char *separator)
{
	if (separator == NULL)
		return;

	while (*separator)
	{
		_putchar(*separator);
		separator++;
	}
}
