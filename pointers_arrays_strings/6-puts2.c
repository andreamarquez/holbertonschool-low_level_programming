#include "main.h"

int isEven(int n);

/**
 * puts2 - prints every other character of a string -> skipping one in between,
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
		/**
		 * Checks if the number is even (0, 2, 4, etc)
		*/
		if (isEven(charCounter))
			_putchar(currentChar);

		charCounter++;
		nextPointer = (pstr + charCounter);
		currentChar = *nextPointer;
	}
	_putchar('\n');
}

/**
 * isEven - Checks if a number is even (0, 2, 4, etc).
 * @number: The number to check.
 *
 * Return: 1 if the number is even, 0 otherwise.
 */
int isEven(int number)
{
	if (number % 2 == 0)
		return (1);
	else
		return (0);
}
