#include <stdio.h>
#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * This function obtains the length of the prefix based of the
 * matching chars from the main string found in the secondary string
 * If the main string has a char that is not found in the secondary string,
 * the prefix length stops there and the function should return the
 * number of characters of the main string found on the secondary
 * which is the length of the prefix.
 * @s: pointer that points  to first character of the main string.
 * @accept: pointer that points  to first character of the secondary string.
 * Return: the number of bytes in the initial segment
 * of s which consist only of bytes from accept.
 *
 */
unsigned int _strspn(char *s, char *accept)
{
	int counter;
	int secondCounter;
	int numberOfMatches;
	/* tells if a diff char has been found: 0 if not found, 1 if found */
	int foundDifferentChar;
	int foundCurrentChar;

	foundDifferentChar = 0;
	numberOfMatches = 0;
	/*
	* runs while a null Terminator is not found AND
	* while a diff char has not been found
	*/
	for (
		counter = 0;
		((*(s + counter) != '\0') && (foundDifferentChar == 0));
		counter++
		)
	{
		foundCurrentChar = 0;
		/*
		* runs while a null Terminator is not found AND
		* while the current char has not been found
		*/
		for (
			secondCounter = 0;
			((*(accept + secondCounter) != '\0') && (foundCurrentChar == 0));
			secondCounter++
			)
		{
			if (*(s + counter) == *(accept + secondCounter))
			{
				foundCurrentChar = 1;
				numberOfMatches++;
			}
		}
		if (foundCurrentChar == 0)
			foundDifferentChar = 1;
	}
	return (numberOfMatches);
}
