#include <stdio.h>
#include "main.h"

/**
 * _strchr - Locates a character in a string.
 * @ps: A pointer to the string in which we want to search.
 * @char_to_search: Character that we are looking for in the string.
 * Return: A pointer that points where the character is located
 * in the string, or NULL if character is NOT found in the string.
 *
 */
char *_strchr(char *ps, char char_to_search)
{
	int positionCounter;
	char currentChar;

	currentChar = *ps;

	for (positionCounter = 0; currentChar != '\0'; positionCounter++)
	{
		currentChar = (*(ps + positionCounter));

		if (currentChar == char_to_search)
		{
			return (ps + positionCounter);
		}
	}
	return (NULL);
}
