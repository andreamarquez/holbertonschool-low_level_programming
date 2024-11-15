#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc.
 * if malloc fails, the malloc_checked function should
 * cause normal process termination with a status value of 98.
 * @memory_size: size in bytes for the memory that we want to assign.
 * Return: A pointer to the allocated memory.
 */
void *malloc_checked(unsigned int memory_size)
{
	void *ptr_to_memory = malloc(memory_size);

	if (ptr_to_memory == NULL)
	{
		exit(98);
	}
	return (ptr_to_memory);
}
