#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - Creates an array of chars and
 *  initializes it with a specific char.
 * @size: The number of characters in the array.
 * @c: The character we use to initialize each element of the array.
 * Return: A pointer to the array, or NULL if size is = 0 or
 * if memory allocation fails.
 *
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}

	array = malloc(size * sizeof(char));
	if (array == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		array[i] = c;
	}

	return (array);
}
