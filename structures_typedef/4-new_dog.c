#include <stdlib.h>
#include <stdio.h>
#include "dog.h"

char *_strcpy(char *destination, char *source);
int _strlen(char *ps);

/**
 * new_dog - creates a new dog.
 * Store a copy of name and owner.
 * @name: Name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 * Return: NULL if function fails, or a pointer
 * to the dog_t that was created.
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *p_doggy;

	char *name_copy = "";
	char *owner_copy = "";

	if (name == NULL || owner == NULL)
		return (NULL);

	p_doggy = malloc(sizeof(dog_t));

	if (p_doggy == NULL)
	{
		return (NULL);
	}

	name_copy = malloc((_strlen(name) + 1) * sizeof(char));
	if (name_copy == NULL)
	{
		free(pointer);
		return (NULL);
	}

	owner_copy = malloc((_strlen(owner) + 1) * sizeof(char));
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(pointer);
		return (NULL);
	}

	_strcpy(name_copy, name);
	_strcpy(owner_copy, owner);

	p_doggy->name = name_copy;
	p_doggy->age = age;
	p_doggy->owner = owner_copy;

	return (p_doggy);
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


/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0), to the
 * buffer pointed to by @destination
 *
 *
 * @destination: copy address destination (for the string to copy)
 * @source: the address of the original string to copy
 *
 * Return: the pointer to destination
 *
 */
char *_strcpy(char *destination, char *source)
{
	int sourceCharCounter = 0;
	char currentSourceChar = *source;
	char *nextSourceCharPointer;

	/*
	* we copy until we reach the null terminator '\0'
	* but as we need to include it, we will add it after the while
	*/
	while (currentSourceChar != '\0')
	{
		/*
		* sourceCharCounter begins on 0 so the first address
		* of source is used on the 1st iteration of the while,
		* then we start jumping address positions:
		* 78 + 0, 78 + 1
		*
		*/
		nextSourceCharPointer = (source + sourceCharCounter);
		currentSourceChar = *nextSourceCharPointer;
		*(destination + sourceCharCounter) = currentSourceChar;
		sourceCharCounter++;
	}

	/*
	* sourceCharCounter now lets us jump to the very end of
	* the string we formed, pointed by destination,
	* to add a null Terminator
	*
	*/
	*(destination + sourceCharCounter) = '\0';

	return (destination);
}
