#include <stdlib.h>
#include <stdio.h>

/**
 * op_add - Adds two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}


/**
 * op_sub - Subtracts two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The result of subtracting b from a.
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiplies two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Divides one integer by another.
 * @a: The dividend.
 * @b: The divisor.
 *
 * Return: The result of the division of a by b.
 */
int op_div(int a, int b)
{
	int division_by_zero_error = 100;

	if (b == 0)
	{
		printf("Error\n");
		exit(division_by_zero_error);
	}

	return (a / b);
}

/**
 * op_mod - Computes the remainder of the division of one integer by another.
 * @a: The dividend.
 * @b: The divisor.
 *
 * Return: The remainder of the division of a by b.
 */
int op_mod(int a, int b)
{
	int module_by_zero_error = 100;

	if (b == 0)
	{
		printf("Error\n");
		exit(module_by_zero_error);
	}

	return (a % b);
}
