#include "main.h"

/**
 * print_to_98 - prints all natural numbers from startingNumber to 98
 * @startingNumber: the starting number
 */
void print_to_98(int startingNumber)
{
	int currentNumber;

	for (
		currentNumber = startingNumber;
		currentNumber != 98;
		currentNumber += (startingNumber < 98) ? 1 : -1
		)
	{
	if (currentNumber < 0)
	{
		_putchar('-');
		if (currentNumber <= -100)
		{
			_putchar((-currentNumber / 100) + '0');
			_putchar(((-currentNumber / 10) % 10) + '0');
		}
		else if (currentNumber <= -10)
			_putchar((-currentNumber / 10) + '0');
		_putchar((-currentNumber % 10) + '0');
	}
	else
	{
		if (currentNumber >= 100)
		{
			_putchar((currentNumber / 100) + '0');
			_putchar(((currentNumber / 10) % 10) + '0');
		}
		else if (currentNumber >= 10)
			_putchar((currentNumber / 10) + '0');
		_putchar((currentNumber % 10) + '0');
	}
	if (currentNumber != 98)
	{
		_putchar(',');
		_putchar(' ');
	}
	}
	_putchar('9');
	_putchar('8');
	_putchar('\n');
}
