#ifndef VARIADIC_FUNCTIONS
#define VARIADIC_FUNCTIONS

int sum_them_all(const unsigned int number, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

int _putchar(char c);

#endif /* VARIADIC_FUNCTIONS */

#ifndef VARIADIC_STRUCTS
#define VARIADIC_STRUCTS

#include <stdarg.h>
/**
 * struct print_type - Struct print_type
 *
 * @format_type: the format of the params to print
 * @print_function: The corresponding function to print
 * the type of format_indicator
 */
typedef struct print_type
{
	char *format_type;
	void (*print_function)(va_list *args);
} print_type_t;

#endif /* VARIADIC_STRUCTS */
