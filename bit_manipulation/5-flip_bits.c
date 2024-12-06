#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to flip
 * to convert one number to another.
 * @number1: The first number.
 * @number2: The second number.
 *
 * Return: The number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int number1, unsigned long int number2)
{
	unsigned long int xor_result = number1 ^ number2;
	unsigned int bit_flip_count = 0;

	while (xor_result != 0)
	{
		bit_flip_count += xor_result & 1;
		xor_result >>= 1;
	}

	return (bit_flip_count);
}
