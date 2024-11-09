#include "main.h"

/**
 * _pow_recursion - Returns the value of x raised to the power of y.
 * @base_number: the base number.
 * @number_exponent: the exponent.
 *
 * Return: The result of x raised to the power of y.
 * If y is lower than 0, returns -1.
 */
int _pow_recursion(int base_number, int number_exponent)
{
	if (number_exponent < 0)
	{
		return (-1);
	}
	if (number_exponent == 0)
	{
		return (1);
	}
	return (base_number * _pow_recursion
		(base_number, number_exponent - 1));
}
