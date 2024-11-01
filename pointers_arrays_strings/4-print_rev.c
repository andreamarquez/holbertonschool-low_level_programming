#include "main.h"

int _strlen(char *ps);

/**
 *  print_rev - prints a string, in reverse, followed by a new line.
 * @str: pointer that points to the string (chain of characters).
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

/**
 *  _strlen - Returns the length of a string.
 * @ps: pointer that points to the string ("chain of characters").
 * Return: string lenght (int)
 *
 */
int _strlen(char *ps)
{
	int charCounter = 0;
	char currentChar = *ps;
	char *nextPointer;

	while (currentChar != '\0')
	{
		charCounter++;
		nextPointer = (ps + charCounter);

		currentChar = *nextPointer;

	}
	return (charCounter);
}
