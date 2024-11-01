#include "main.h"

int _strlen(char *ps);

/**
 *  rev_string - A function that reverses a string.
 * @ps: pointer that points to the string ("chain of characters").
 *
 */
void rev_string(char *ps)
{
	int stringLength = _strlen(ps);
	int positionStartingFromLeft = 0;
	int positionStartingFromRight = stringLength - 1;
	char temporalCharacterHolder;

	while (positionStartingFromLeft < positionStartingFromRight)
	{
		/**
		 * temporalCharacterHolder = ps[positionStartingFromLeft];
		 * ps[positionStartingFromLeft] = ps[positionStartingFromRight];
		 * ps[positionStartingFromRight] = temporalCharacterHolder;
		*/

		temporalCharacterHolder = *(ps + positionStartingFromLeft);
		*(ps + positionStartingFromLeft) = *(ps + positionStartingFromRight);
		*(ps + positionStartingFromRight) = temporalCharacterHolder;

		positionStartingFromLeft++;
		positionStartingFromRight--;
	}
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
