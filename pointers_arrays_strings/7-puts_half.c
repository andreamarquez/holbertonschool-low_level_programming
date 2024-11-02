#include "main.h"

int isEven(int n);
int _strlen(char *ps);

/**
 * puts_half - prints the second half of a string. If the number of characters
 * is odd, the function should print the last n characters of the string,
 * where `n = (length_of_the_string - 1) / 2`, followed by a new line.
 *
 * @pstr: `pointer` to the string that will be used
 *
 */
void puts_half(char *pstr)
{
	int stringLength = _strlen(pstr);
	int finalStringIndex = stringLength - 1;
	/*
	 * Get the final char address of the string
	*/
	char *currentCharAddress = (pstr + finalStringIndex);
	int numberOfCharactersToPrint;

	if (isEven(stringLength))
		numberOfCharactersToPrint = stringLength / 2;
	else
		numberOfCharactersToPrint = (stringLength - 1) / 2;

	/*
	 * Print the char on the current address and keep moving
	 * from end to start one by one until we reach
	 * the needed characters to print the half
	*/
	while (numberOfCharactersToPrint > 0)
	{
		_putchar(*currentCharAddress);
		currentCharAddress--;
		numberOfCharactersToPrint--;
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
