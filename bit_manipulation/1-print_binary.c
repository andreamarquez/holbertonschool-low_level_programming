#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a number.
 * @number: The number to be printed in binary.
 *
 * Description: This function takes an unsigned long integer and prints
 * its binary representation to the standard output.
 */
void print_binary(unsigned long int number)
{
	if (number > 1)
		print_binary(number >> 1);

	putchar((number & 1) ? '1' : '0');
	}
