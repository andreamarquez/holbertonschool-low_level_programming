#include <stdio.h>
#include "main.h"

/**
 * _memset - fills memory with a constant byte.
 * @memory_area: A pointer to start on the memory area.
 * @value: The value to fill the memory with.
 * @number_of_bytes_to_replace: The number of bytes(slots),
 * to fill in the memory area.
 *
 * Return: the pointer to the memory area.
 *
 */
char *_memset(
	char *memory_area,
	char value,
	unsigned int number_of_bytes_to_replace
	)
{
	unsigned int positionCounter;

	for (
		positionCounter = 0;
		positionCounter < number_of_bytes_to_replace;
		positionCounter++
		)
	{
		/* Replace the character at the current position with the desired value */
		*(memory_area + positionCounter) = value;
	}

	return (memory_area);
}
