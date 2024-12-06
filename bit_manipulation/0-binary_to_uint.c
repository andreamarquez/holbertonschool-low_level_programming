#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string containing a binary number (0s and 1s).
 *
 * Return: The converted number, or 0 if:
 *         - There is one or more chars in the string b that is not 0 or 1.
 *         - b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int converted_number = 0;
	int index;

	if (b == NULL)
		return (0);

	for (index = 0; b[index] != '\0'; index++)
	{
		if (b[index] != '0' && b[index] != '1')
			return (0);
		converted_number = converted_number * 2 + (b[index] - '0');
	}

	return (converted_number);
}
