#include "main.h"

/**
 *  _puts - prints a string, followed by a new line, to stdout.
 * @str: pointer that points to the string (chaine of characters).
 * Return: 0.
 *
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
