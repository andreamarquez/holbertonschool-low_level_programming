#include "main.h"

/**
 * print_diagonal - draws a diagonal line.
 * @n: he number of times the character \ should be printed.
 * The diagonal should end with a \n.
 * If n is 0 or less, the function should only print \n.
 * Return: void.
 */
void print_diagonal(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int diagonalCounter;

		for (diagonalCounter = 0; diagonalCounter < n; diagonalCounter++)
		{
			/* -> starts printing spaces */
			int spacesCounter;

			for (spacesCounter = 0; spacesCounter < diagonalCounter; spacesCounter++)
			{
				_putchar(' ');
			}

			/* -> ends printing spaces*/

			_putchar('\\');
			_putchar('\n');
		}
	}
}
