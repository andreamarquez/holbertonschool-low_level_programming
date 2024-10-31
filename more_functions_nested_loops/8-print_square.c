#include "main.h"

/**
 * print_square - prints a square, followed by a new line.
 * @size: Is the size of the square.
 * If @size <= 0, fuction should print only a new line.
 * # - character to print.
 * Return: void.
 */
void print_square(int size)
{
	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int poundCounter;
		int lineCounter;

		for (poundCounter = 0; poundCounter < size; poundCounter++)
		{
			for (lineCounter = 0; lineCounter < size; lineCounter++)
			_putchar('#');
			_putchar('\n');
		}
	}
}
