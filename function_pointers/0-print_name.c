#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name.
 * The print_name function will call the function
 * pointed to by f, passing the name string to it.
 * @name: A pointer to a character of a string that is
 * the name of the person.
 * @function: a pointer to a function that takes a char and
 * returns a void. This function will be applied to the name.
 *
 * Returns: Void.
 */
void print_name(char *name, void (*function)(char *))
{
	/* Check if name or function pointer is NULL */
	if (name == NULL || function == NULL)
		return;

	/* Call the function pointed to by function with name as the argument */
	function(name);
}
