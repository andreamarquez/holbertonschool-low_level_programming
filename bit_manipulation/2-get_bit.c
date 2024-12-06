#include <limits.h>

/**
 * get_bit - Retrieves the value of a bit at a given index.
 * @number: The number to be examined.
 * @index: The index of the bit to retrieve, starting from 0.
 *
 * Return: The value of the bit at the specified index (0 or 1),
 *         or -1 if an error occurred (e.g., if index is out of range).
 */
int get_bit(unsigned long int number, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * CHAR_BIT)
		return (-1);

	return ((number >> index) & 1);
}
