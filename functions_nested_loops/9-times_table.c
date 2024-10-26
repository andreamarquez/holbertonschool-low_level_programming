#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0.
 *
 * Does not takes arguments.
 *
 * Return: void, just prints the 9 times table.
 *
 */
void times_table(void)
{
	int multiplier, multiplicand, product;

	/* Loop through each number from 0 to 9 (multiplier) */
	for (multiplier = 0; multiplier <= 9; multiplier++)
	{
		/* Loop through each number from 0 to 9 (multiplicand) */
		for (multiplicand = 0; multiplicand <= 9; multiplicand++)
		{
			/* Calculate the product of multiplier and multiplicand */
			product = multiplier * multiplicand;

			/**
			 * Print a comma and space before each number,
			 * except the first in each row
			 */
			if (multiplicand != 0)
			{
				_putchar(',');
				_putchar(' ');
				/* Print an extra space for single-digit products for alignment */
				if (product < 10)
				{
					_putchar(' ');
				}
			}

			/* Print the tens digit if the product is 10 or greater */
			if (product >= 10)
			{
				_putchar((product / 10) + '0');
			}
			/* Print the units digit of the product */
			_putchar((product % 10) + '0');
		}
		/* Print an enter to move to the next row */
		_putchar('\n');
	}
	}
