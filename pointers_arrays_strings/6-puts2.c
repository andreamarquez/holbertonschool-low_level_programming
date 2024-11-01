#include "main.h"

/**
 * puts2 - prints every other character of a string,
 * starting with the first character, followed by a new line.
 * @pstr: pointer that points to the string ("chain of characters").
 *
 */
void puts2(char *pstr)
{
	int charCounter = 0;
	char currentChar = *pstr;
	char *nextPointer;

	while (currentChar != '\0')
	{
		_putchar(currentChar);
		charCounter++;
		nextPointer = (pstr + charCounter);
		currentChar = *nextPointer;
	}
	_putchar('\n');
}
