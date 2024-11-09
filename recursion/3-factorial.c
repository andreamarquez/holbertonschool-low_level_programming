#include "main.h"

/**
 * factorial - Returns the factorial of a given number.
 * @n: the given number.
 * Return: -1 if n is lower than 0. And the factorial if
 * the number is greater than 0.
 */
int factorial(int n)
{
	int result;

	if (n < 0)
	{
		return (-1);
	}
	if (n == 0)
	{
		return (1);
	}
	if (n == 1)
	{
		return (1);
	}

	result = n * factorial(n - 1);
	return (result);
}
