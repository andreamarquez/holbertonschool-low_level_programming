#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

void _printChar(va_list *arguments);
void _printInt(va_list *arguments);
void _printFloat(va_list *arguments);
void _printString(va_list *arguments);

/**
 * print_all - Prints anything with a new line at the end.
 * @format: a arguments of types of arguments passed to
 * the function:
 * c: char
 * i: integer
 * f: float
 * s: char *
 * the string is NULL, print (nil) instead
 * any other char should be ignored.
 */
void print_all(const char * const format, ...)
{
	print_type_t print_by_type[] = {
		{"c", _printChar},
		{"i", _printInt},
		{"f", _printFloat},
		{"s", _printString},
		{NULL, NULL}
	};

	int next_argument_position = 0;
	int format_option_counter = 0;
	va_list arguments;
	/* used to be printed before each argument */
	/* we need an empty separator only on the 1st iteration */
	char *separator = "";

	va_start(arguments, format);

	while (format && format[next_argument_position])
	{
		format_option_counter = 0;

		while (print_by_type[format_option_counter].format_type != NULL)
		{
			/* we ignore any char on the format string that is not one of the options */
			if (format[next_argument_position] ==
			print_by_type[format_option_counter].format_type[0])
			{
				printf("%s", separator);
				print_by_type[format_option_counter].print_function(&arguments);
				separator = ", ";
				/* we end the inner loop iteration we found something to print */
				break;
			}
			format_option_counter++;
		}

		/* we set the comma to print before the following args */
		
		next_argument_position++;
	}
	printf("\n");
	va_end(arguments);
}

/**
 * _printChar - Prints a character from a variadic args.
 * @arguments: The variadic argument args containing
 * the character to print.
 *
 * Description: This function retrieves a character from the provided
 *              variadic args and prints it using printf.
 */
void _printChar(va_list *arguments)
{
	printf("%c", va_arg(*arguments, int));
}

/**
 * _printInt - Prints an integer from a variadic argument arguments.
 * @arguments: The variadic args containing the integer to print.
 *
 * This function retrieves an integer from the provided variadic argument
 * args and prints it using the printf function.
 */
void _printInt(va_list *arguments)
{
	printf("%i", va_arg(*arguments, int));
}

/**
 * _printFloat - Prints a float from a variadic args.
 * @arguments: The variadic args containing the float to print.
 *
 * This function retrieves a double value from the provided variadic
 * args and prints it using the printf function with the
 * %f format specifier.
 */
void _printFloat(va_list *arguments)
{
	printf("%f", va_arg(*arguments, double));
}

/**
 * _printString - Prints a string from variadic args.
 * @arguments: The variadic args containing the string to print.
 *
 * Description: This function retrieves a string from the provided
 * args and prints it. If the string is NULL,
 * it prints "(nil)" instead.
 */
void _printString(va_list *arguments)
{
	char *non_null_string;

	non_null_string = va_arg(*arguments, char *);

	if (non_null_string == NULL)
		non_null_string = "(nil)";

	printf("%s", non_null_string);
}
