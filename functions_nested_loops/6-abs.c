#include "main.h"

/**
 * _abs - computes the absolute value of an integer.
 * @n: The number to turn to absolute value.
 *
 * Return: returns the absolute value.
 */
int _abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}
