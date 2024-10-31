#include "main.h"

/**
 * print_triangle - Prints a triangle, followed by a new line.
 * @size: Is the size of the triangle.
 * If size is 0 or less, the function should only print \n.
 * #: character to print the triangle.
 */
void print_triangle(int size)
{
	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int lineCounter;

		for (lineCounter = 1; lineCounter <= size; lineCounter++)
		{
			int spaceCounter;
			int numberSignCounter;

			for (spaceCounter = 0; spaceCounter < (size - lineCounter); spaceCounter++)
			{
				_putchar(' ');
			}

			for (
				numberSignCounter = 0;
				numberSignCounter < lineCounter;
				numberSignCounter++
				)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
