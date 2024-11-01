#include "main.h"

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

	while (currentChar != '\0')
	{
		charCounter++;
		char *nextPointer = (ps + charCounter);

		currentChar = *nextPointer;

	}
return (charCounter);
}

