#include "main.h"
#include <stdio.h>

/**
 * _print_rev_recursion - prints a string in reverse.
 * @s: Pointer that points to where the string begins.
 * Return: void.
 */
void _print_rev_recursion(char *s)
{
	if (s == NULL)
	{
		return;
	}
	if (*s == '\0')
	{
		return;
	}
	_print_rev_recursion(s + 1);
	_putchar(*s);
}
