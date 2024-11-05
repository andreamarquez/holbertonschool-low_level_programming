#include <stdio.h>
#include "main.h"

/**
 * _memcpy - Copies memory area.
 * @number_of_bytes_to_replace: The number of bytes(slots) to copy
 * from the source to the destination.
 * @source: First memory area.
 * @destination: Second memory area.
 *
 * Return: Pointer to the destination area.
 *
 */
char *_memcpy(
	char *destination,
	char *source,
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
		/* Replace the slots from the source to the final */
		*(destination + positionCounter) =
		*(source + positionCounter);
	}

	return (destination);
}
