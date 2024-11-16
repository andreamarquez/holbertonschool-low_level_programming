#include <stdlib.h>

/**
 * _calloc - allocates memory for an array (using
 * malloc).
 * @number_elements: Number of elements of the array.
 * @size_in_bytes: Size in bytes of each element of the array.
 * The memory is set to zero.
 * Return: a pointer to the allocated memory with the bytes
 * set to zero.
 * If malloc fails, then _calloc returns NULL.
 * If number_elements or size is 0, then _calloc returns NULL.
 */
void *_calloc(unsigned int number_elements, unsigned int size_in_bytes)
{
	unsigned int total_size;
	void *reserved_memory;
	unsigned int counter;

	if (number_elements == 0 || size_in_bytes == 0)
		return (NULL);

	/* Assigns the memory */
	total_size = number_elements * size_in_bytes;
	reserved_memory = malloc(total_size);

	if (reserved_memory == NULL)
		return (NULL);

	/* Initialize the memory assigned to 0*/
	for (counter = 0; counter < total_size; counter++)
	{
		((char *)reserved_memory)[counter] = 0;
	}

	return (reserved_memory);
}
