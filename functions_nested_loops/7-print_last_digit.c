#include "main.h"

/**
 * print_last_digit - prints the last digit of a number.
 * @n: The number get the last digit of for printing.
 *
 * Return: Always 0.
 */
int print_last_digit(int n)
{
	int last_digit;

	if (n < 0)
		last_digit = -1 * (n % 10);
	else
		last_digit = n % 10;

	_putchar('0' + last_digit);
	return (last_digit);
	return (0);
}
