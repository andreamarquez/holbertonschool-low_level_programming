#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include "variadic_functions.h"

/**
 * sum_them_all - Sums all its parameters.
 * @number: The number of parameters passed to the function.
 * @...: A variable number of parameters to be summed.
 *
 * Return: The sum of all parameters. If number is 0, return 0.
 */
int sum_them_all(const unsigned int number, ...)
{
	unsigned int counter;
	int next_arg;
	/*
	* sum is a variable that hold the sum and
	* initialize it to 0
	*/
	int sum = 0;
	va_list arguments;

	/* Checks if the number is 0 */
	if (number <= 0)
		return (0);

	/*
	* Initialize the variable arguments with va_start.
	*/
	va_start(arguments, number);


	/* iterate through arguments and sum them using */
	/* the va_arg macro */
	for (counter = 0; counter < number; counter++)
	{
		next_arg = va_arg(arguments, int);

		/* Check for overflow */
		if (sum + next_arg > INT_MAX)
		{
			va_end(arguments);
			return (sum);
		}
		sum = sum + next_arg;
	}

	/* Clean up the va_list */
	va_end(arguments);

	return (sum);
}
