#include <limits.h>

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @number: Pointer to the number to modify.
 * @index: The index of the bit to set, starting from 0.
 *
 * Return: 1 if it worked, or -1 if an error occurred
 * (e.g., if index is out of range).
 */
int set_bit(unsigned long int *number, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * CHAR_BIT)
		return (-1);

	*number |= (1UL << index);
	return (1);
}
