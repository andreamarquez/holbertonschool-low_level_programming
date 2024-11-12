#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int _strlen(char *ps);

/**
 * _strdup -> takes a string as an input.
 * _strdup - Allocates new memory to hold a copy of the original_string.
 * Memory for the new string is obtained with malloc,
 * and can be freed with free.
 * @original_string: String to be duplicated.
 * Return: NULL if original_string = NULL or insufficient memory
 * or on success, the _strdup function returns a pointer to
 * the duplicated string.
 */
char *_strdup(char *original_string)
{
	int length;
	char *copy_string;
	int duplicator;

	if (original_string == NULL)
	{
		return (NULL);
	}

	length = _strlen(original_string) + 1;
	copy_string = malloc(length * sizeof(char));

	if (copy_string == NULL)
	{
		return (NULL);
	}

	for (duplicator = 0; duplicator < length; duplicator++)
	{
		copy_string[duplicator] = original_string[duplicator];
	}

	return (copy_string);
}


/**
 *  _strlen - Returns the length of a string.
 * @ps: pointer that points to the string ("chain of characters").
 * Return: string length (int)
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
