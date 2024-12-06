#include <limits.h>

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the number to modify.
 * @index: The index of the bit to clear, starting from 0.
 *
 * Return: 1 if it worked, or -1 if an error occurred
 * (e.g., if index is out of range).
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * CHAR_BIT)
		return (-1);

	*n &= ~(1UL << index);
	return (1);
}
