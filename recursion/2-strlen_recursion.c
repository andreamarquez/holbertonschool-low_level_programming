#include "main.h"
#include <stdio.h>

/**
 * _strlen_recursion - Returns the length of a string.
 * @s: Pointer that points to where the string begins.
 * Return: the length of the string.
 */
int _strlen_recursion(char *s)
{
	int length_counter = 0;

	if (s == NULL)
	{
		return (0);
	}
	if (*s == '\0')
	{
		return (0);
	}
	length_counter++;
	length_counter = length_counter + _strlen_recursion(s + 1);
	return (length_counter);
}
