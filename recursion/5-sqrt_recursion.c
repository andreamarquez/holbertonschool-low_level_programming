#include "main.h"

int find_root(int base_number, int number_to_test, int max_limit);

/**
 * _sqrt_recursion - gets the natural square root of a number.
 * @base_number: the base number.
 *
 * Return: returns the natural square root of a number.
 * If base_number  does not have a natural square root,
 * the function should return -1.
 *
 */
int _sqrt_recursion(int base_number)
{
	int max_limit = base_number - (base_number / 2);

	if (base_number < 0)
	{
		return (-1);
	}
	if (base_number == 0)
	{
		return (0);
	}
	if (base_number == 1)
	{
		return (1);
	}

	return (find_root(base_number, 1, max_limit));
}

/**
 * find_root - gets the natural square root of a number.
 * @base_number: the base number.
 * @number_to_test: the number to start testing
 * multiplying by itself to check == with base_number
 * @max_limit: the max number to look for before returning
 * -1 if a root was not found.
 *
 * Return: returns the natural square root of a number.
 *
 */
int find_root(int base_number, int number_to_test, int max_limit)
{
	if (number_to_test >= max_limit)
	{
		return (-1);
	}
	if (number_to_test * number_to_test == base_number)
		return (number_to_test);
	else if (number_to_test * number_to_test < base_number)
	{
		return (find_root(base_number, number_to_test + 1, max_limit));
	}
	else
	{
		return (find_root(base_number, number_to_test - 1, max_limit - 1));
	}
}
