#include "main.h"

/**
 * print_to_98 - prints all natural numbers from startingNumber to 98
 * @startingNumber: the starting number
 */
void print_to_98(int startingNumber)
{
    int currentNumber;

    if (startingNumber <= 98)
    {
        for (currentNumber = startingNumber; currentNumber <= 98; currentNumber++)
        {
            if (currentNumber < 0)
            {
                _putchar('-');
                _putchar(-currentNumber + '0');
            }
            else if (currentNumber >= 10)
            {
                if (currentNumber >= 100)
                {
                    _putchar((currentNumber / 100) + '0');
                    _putchar(((currentNumber / 10) % 10) + '0');
                }
                else
                {
                    _putchar((currentNumber / 10) + '0');
                }
                _putchar((currentNumber % 10) + '0');
            }
            else
            {
                _putchar(currentNumber + '0');
            }
            if (currentNumber != 98)
            {
                _putchar(',');
                _putchar(' ');
            }
        }
    }
    else
    {
        for (currentNumber = startingNumber; currentNumber >= 98; currentNumber--)
        {
            if (currentNumber >= 100)
            {
                _putchar((currentNumber / 100) + '0');
                _putchar(((currentNumber / 10) % 10) + '0');
            }
            else if (currentNumber >= 10)
            {
                _putchar((currentNumber / 10) + '0');
            }
            _putchar((currentNumber % 10) + '0');
            if (currentNumber != 98)
            {
                _putchar(',');
                _putchar(' ');
            }
        }
    }
    _putchar('\n');
}
