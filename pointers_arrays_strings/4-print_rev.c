#include "main.h"

/**
 *  print_rev - prints a string, in reverse, followed by a new line.
 * @str: pointer that points to the string (ze chaine of characters).
 *
 */
void print_rev(char *str)
{
	int stringLength = _strlen(str);

	int positionsToSkip = stringLength - 1;

	char *reversedString = str + positionsToSkip;

	while (reversedString >= str)
	{
		_putchar(*reversedString);
		reversedString--;
	}
	_putchar('\n');
}
