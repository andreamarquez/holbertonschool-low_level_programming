#include "main.h"

/**
 * print_to_98 - prints all natural numbers from startingNumber to 98
 * @startingNumber: the starting number
 */
void print_to_98(int startingNumber)
{
	int num;

	if (startingNumber <= 98)
	{
		for (num = startingNumber; num <= 98; num++)
		{
			if (num >= 10)
			{
				_putchar((num / 10) + '0');
			}
			_putchar((num % 10) + '0');
			if (num != 98)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
	}
	else
	{
		for (num = startingNumber; num >= 98; num--)
		{
			if (num >= 100)
			{
				_putchar((num / 100) + '0');
				_putchar(((num / 10) % 10) + '0');
			}
			else if (num >= 10)
			{
				_putchar((num / 10) + '0');
			}
			_putchar((num % 10) + '0');
			if (num != 98)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
	}
	_putchar('\n');
}
